
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Room {
protected:
    int roomId;
    double price;
    string roomType;

public:
    Room(int id, double p, string type) {
        roomId = id;
        price = p;
        roomType = type;
    }

    virtual double getPrice() const {
        return price;
    }

    virtual void displayInfo() const {
        cout << "Phong " << roomId
             << " | " << roomType
             << " | Gia: " << fixed << setprecision(0)
             << price << " VND/ dem";
    }

    virtual ~Room() {}
};

class StandardRoom : public Room {
public:
    StandardRoom(int id)
        : Room(id, 500000, "Standard") {}

    void displayInfo() const override {
        Room::displayInfo();
        cout << " | 2 nguoi lon + 1 tre em";
    }
};

class RelaxRoom : public Room {
private:
    string bedType;

public:
    RelaxRoom(int id, int bedChoice)
        : Room(id, bedChoice == 1 ? 700000 : 800000,
               "Relax") {
        bedType = (bedChoice == 1)
                  ? "1 giuong don lon"
                  : "2 giuong doi";
    }

    void displayInfo() const override {
        Room::displayInfo();
        cout << " | " << bedType
             << " | 2 nguoi lon + 1 tre em";
    }
};

class LuxuryRoom : public Room {
private:
    string bedType;

public:
    LuxuryRoom(int id, int bedChoice)
        : Room(id, bedChoice == 1 ? 1000000 : 1200000,
               "Luxury") {
        bedType = (bedChoice == 1)
                  ? "1 giuong don lon"
                  : "2 giuong doi";
    }

    void displayInfo() const override {
        Room::displayInfo();
        cout << " | " << bedType
             << " | Phong tam rieng"
             << " | 2 nguoi lon + 1 tre em";
    }
};

struct Option {
    string name;

    int standard;
    int relax;
    int luxury;

    int relaxBed;
    int luxuryBed;
};

double getRelaxPrice(int bedChoice) {
    return (bedChoice == 1) ? 700000 : 800000;
}

double getLuxuryPrice(int bedChoice) {
    return (bedChoice == 1) ? 1000000 : 1200000;
}

// Tinh tong tien cua mot phuong an
double calculateTotal(const Option& op) {
    return op.standard * 500000.0
         + op.relax * getRelaxPrice(op.relaxBed)
         + op.luxury * getLuxuryPrice(op.luxuryBed);
}

void displayRooms(const Option& op) {
    int id = 1;

    cout << "\nCHI TIET TUNG PHONG\n";

    for (int i = 0; i < op.standard; i++) {
        StandardRoom room(id++);
        room.displayInfo();
        cout << endl;
    }

    for (int i = 0; i < op.relax; i++) {
        RelaxRoom room(id++, op.relaxBed);
        room.displayInfo();
        cout << endl;
    }

    for (int i = 0; i < op.luxury; i++) {
        LuxuryRoom room(id++, op.luxuryBed);
        room.displayInfo();
        cout << endl;
    }
}

void displayOption(const Option& op) {
    int totalRooms = op.standard + op.relax + op.luxury;
    double total = calculateTotal(op);

    cout << "\n========================================\n";
    cout << op.name << endl;
    cout << "Standard: " << op.standard << " phong\n";
    cout << "Relax: " << op.relax << " phong";
    if (op.relax > 0) {
        cout << " - "
             << (op.relaxBed == 1
                 ? "1 giuong don lon"
                 : "2 giuong doi");
    }
    cout << endl;

    cout << "Luxury: " << op.luxury << " phong";
    if (op.luxury > 0) {
        cout << " - "
             << (op.luxuryBed == 1
                 ? "1 giuong don lon"
                 : "2 giuong doi");
    }
    cout << endl;

    cout << "Tong so phong: " << totalRooms << endl;
    cout << fixed << setprecision(0);
    cout << "Tong tien: " << total << " VND/ dem\n";
    cout << "Trung binh moi phong: "
         << total / totalRooms << " VND/ dem\n";

    displayRooms(op);
}

int main() {
    const int adults = 30;
    const int children = 20;

    const int standardAvailable = 10;
    const int relaxAvailable = 10;
    const int luxuryAvailable = 10;
    const int hotelCapacity = 30;

    cout << "QUAN LY PHONG KHACH SAN\n";
    cout << "Nguoi lon: " << adults << endl;
    cout << "Tre em (0-6 tuoi): " << children << endl;
    cout << "Tong khach: " << adults + children << endl;
    cout << "Tong so phong: " << hotelCapacity << endl;

    int requiredRooms = children + (adults - children) / 2;

    if (adults < children ||
        (adults - children) % 2 != 0) {
        cout << "Khong the bo tri theo quy tac da dat ra.\n";
        return 0;
    }

    if (requiredRooms > hotelCapacity) {
        cout << "Khong du phong cho doan khach.\n";
        return 0;
    }

    cout << "So phong can dung: " << requiredRooms << endl;
    cout << "So phong con trong: "
         << hotelCapacity - requiredRooms << endl;

    vector<Option> options = {
        {
            "OPTION 1 - TIET KIEM",
            10, 10, 5,
            1, 1
        },
        {
            "OPTION 2 - CAN BANG",
            10, 5, 10,
            2, 1
        },
        {
            "OPTION 3 - CAO CAP",
            5, 10, 10,
            2, 2
        }
    };

    for (int i = 0; i < (int)options.size(); i++) {
        int totalRooms = options[i].standard
                       + options[i].relax
                       + options[i].luxury;

        if (options[i].standard > standardAvailable ||
            options[i].relax > relaxAvailable ||
            options[i].luxury > luxuryAvailable ||
            totalRooms != requiredRooms) {
            cout << "Phuong an khong hop le!\n";
            return 0;
        }
    }

    cout << "\nSO SANH CAC PHUONG AN\n";

    for (int i = 0; i < (int)options.size(); i++) {
        cout << options[i].name
             << " | Tong tien: "
             << fixed << setprecision(0)
             << calculateTotal(options[i])
             << " VND/ dem\n";
    }

    for (int i = 0; i < (int)options.size(); i++) {
        displayOption(options[i]);
    }

    cout << "\nCHI PHI BINH QUAN MOI KHACH\n";

    for (int i = 0; i < (int)options.size(); i++) {
        cout << options[i].name << ": "
             << fixed << setprecision(0)
             << calculateTotal(options[i])
                / (adults + children)
             << " VND/ nguoi/ dem\n";
    }

    cout << "\nLuu y: Gia phong la gia mau cho 1 dem.\n";
    cout << "Tre em duoc tinh trong gia phong.\n";

    return 0;
}
