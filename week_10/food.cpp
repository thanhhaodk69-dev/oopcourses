#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. Định nghĩa class Food (chuyển từ struct Food)
class Food {
public:
    string id;
    string name;
    double price;
    int quantity;

    void input() {
        cout << "Nhap ten: ";
        getline(cin, name);
        cout << "Nhap gia: ";
        cin >> price;
        cin.ignore();
        quantity = 0;
    }

    void display() {
        cout << name << " - " << price << " (" << quantity << ")" << endl;
    }
};

int main() {
    // Tạo danh sách lưu các món ăn
    vector<Food> listFood;
    int n = 3; // Tạo 3 món ăn theo yêu cầu

    // 2. Nhập thông tin 3 món ăn
    for (int i = 0; i < n; i++) {
        Food f;
        f.input();
        listFood.push_back(f);
    }

    // In thông tin các món ăn
    cout << "\n=== Danh sach mon an ===\n";
    for (int i = 0; i < n; i++) {
        listFood[i].display();
    }

    // Tìm món ăn theo tên
    cout << "\n=== Tim mon an ===\n";
    string searchName;
    cout << "Nhap ten mon an can tim: ";
    getline(cin, searchName);

    bool found = false;
    for (int i = 0; i < listFood.size(); i++) {
        if (listFood[i].name == searchName) {
            cout << "Da tim thay: ";
            listFood[i].display();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Khong tim thay mon an!\n";
    }

    // Cập nhật giá của một món ăn
    cout << "\n=== Cap nhat gia mon an ===\n";
    string updateName;
    cout << "Nhap ten mon an can cap nhat gia: ";
    getline(cin, updateName);

    found = false;
    for (int i = 0; i < listFood.size(); i++) {
        if (listFood[i].name == updateName) {
            double newPrice;
            cout << "Nhap gia moi: ";
            cin >> newPrice;
            listFood[i].price = newPrice;
            cout << "Cap nhat thanh cong!\n";
            listFood[i].display();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Khong tim thay mon an de cap nhat!\n";
    }

    return 0;
}