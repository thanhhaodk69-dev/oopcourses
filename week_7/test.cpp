#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct User {
    string username;
    string pwd;
};

struct Computer {
    string id;
    string name;
    string os;
    User user; 
    string model;
    int year;
};

struct Lab {
    string roomCode;
    string function;
};

void inputLabAndComputers(Lab &lab, Computer computers[], int &n) {
    cout << "=== INPUT LAB INFO ===\n";
    cout << "Enter Room Code: ";
    getline(cin, lab.roomCode);
    cout << "Enter Lab Function: ";
    getline(cin, lab.function);

    do {
        cout << "\nEnter number of computers (1 <= N <= 20): ";
        cin >> n;
    } while (n < 1 || n > 20);

    for (int i = 0; i < n; i++) {
        cout << "\n--- Enter info for Computer " << (i + 1) << " ---\n";
        cin.ignore();
        cout << "ID: ";
        getline(cin, computers[i].id);
        cout << "Name: ";
        getline(cin, computers[i].name);
        cout << "OS: ";
        getline(cin, computers[i].os);
        cout << "Username: ";
        getline(cin, computers[i].user.username);
        cout << "Password: ";
        getline(cin, computers[i].user.pwd);
        cout << "Model: ";
        getline(cin, computers[i].model);
        cout << "Year: ";
        cin >> computers[i].year;
    }
}

void showLabInfo(const Lab &lab) {
    cout << "\n=== LAB INFORMATION ===\n";
    cout << "Room Code: " << lab.roomCode << "\n";
    cout << "Function : " << lab.function << "\n";
}
// 1) Tìm và in thông tin máy tính theo ID
void getComputerInfo(const Computer computers[], int n, string targetId) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (computers[i].id == targetId) {
            cout << "\n=== COMPUTER INFO (ID: " << targetId << ") ===\n";
            cout << "Name    : " << computers[i].name << "\n";
            cout << "OS      : " << computers[i].os << "\n";
            cout << "Username: " << computers[i].user.username << "\n";
            cout << "Password: " << computers[i].user.pwd << "\n";
            cout << "Model   : " << computers[i].model << "\n";
            cout << "Year    : " << computers[i].year << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\nComputer with ID '" << targetId << "' not found.\n";
    }
}
// 2) Tìm và trả về đối tượng Computer
Computer getComputerById(const Computer computers[], int n, string targetId) {
    for (int i = 0; i < n; i++) {
        if (computers[i].id == targetId) {
            return computers[i];
        }
    }
    return Computer{"", "N/A", "N/A", {"N/A", "N/A"}, "N/A", 0};
}
// 3) Trả về con trỏ mảng các máy tính
const Computer* getComputers(const Computer computers[]) {
    return computers;
}
// 4) Lấy thông tin Username & Password từ struct User thông qua ID máy
User getUserAndPassword(const Computer computers[], int n, string targetId) {
    for (int i = 0; i < n; i++) {
        if (computers[i].id == targetId) {
            return computers[i].user;
        }
    }
    return User{"N/A", "N/A"};
}

int main() {
    Lab lab;
    Computer computers[20];
    int n = 0;

    inputLabAndComputers(lab, computers, n);
    showLabInfo(lab);

    // 1) Tìm và in thông tin máy tính theo ID
    string searchId;
    cout << "\nEnter Computer ID to print info: ";
    cin.ignore();
    getline(cin, searchId);
    getComputerInfo(computers, n, searchId);
    // 2) Tìm và trả về đối tượng Computer
    cout << "\nEnter Computer ID to return Computer object: ";
    getline(cin, searchId);
    Computer comp = getComputerById(computers, n, searchId);
    cout << "-> Returned object name: " << comp.name << " | Model: " << comp.model << "\n";
    // 3) Trả về con trỏ mảng các máy tính
    cout << "\n=== ALL COMPUTERS IN LAB (via getComputers) ===\n";
    const Computer* list = getComputers(computers);
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". ID: " << list[i].id 
             << " | Name: " << list[i].name 
             << " | OS: " << list[i].os << "\n";
    }
    // 4) Lấy thông tin Username & Password từ struct User thông qua ID máy
    cout << "\nEnter Computer ID to get credentials: ";
    getline(cin, searchId);
    User u = getUserAndPassword(computers, n, searchId);
    cout << "-> Credentials (User: " << u.username << " | Password: " << u.pwd << ")\n";
    return 0;
}