#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1. Khai báo class Food
class Food {
private:
    string id;
    string name;
    double price;
    int quantity;

public:
    // Constructor mặc định và Constructor có tham số
    Food() : id(""), name(""), price(0.0), quantity(0) {}
    Food(string id, string name, double price, int quantity) {
        this->id = id;
        this->name = name;
        this->price = (price > 0) ? price : 0;
        this->quantity = (quantity >= 0) ? quantity : 0;
    }

    // Nhập thông tin
    void input() {
        cout << "Nhap ma mon: ";
        getline(cin, id);
        cout << "Nhap ten mon: ";
        getline(cin, name);
        
        do {
            cout << "Nhap gia (> 0): ";
            cin >> price;
        } while (price <= 0);

        do {
            cout << "Nhap so luong (>= 0): ";
            cin >> quantity;
        } while (quantity < 0);

        cin.ignore();
    }

    // Hiển thị thông tin
    void display() const {
        cout << id << " | " << name << " | Gia: " << price << " | So luong: " << quantity << endl;
    }

    // Cập nhật giá
    void setPrice(double newPrice) {
        if (newPrice > 0) {
            price = newPrice;
        } else {
            cout << "Loi: Gia moi phai lon hon 0!\n";
        }
    }

    // Cập nhật số lượng
    void setQuantity(int newQuantity) {
        if (newQuantity >= 0) {
            quantity = newQuantity;
        } else {
            cout << "Loi: So luong khong the am!\n";
        }
    }

    // Giảm số lượng khi mua hàng
    bool reduceQuantity(int amount) {
        if (amount > 0 && quantity >= amount) {
            quantity -= amount;
            return true;
        }
        return false;
    }

    // Kiểm tra còn hàng hay không
    bool isAvailable() const {
        return quantity > 0;
    }

    // Getter
    string getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
};

// 2. Thuật toán Sắp xếp nổi bọt (Bubble Sort) theo Giá tăng dần (Không dùng <algorithm>)
void sortByPrice(vector<Food>& store) {
    int n = store.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (store[j].getPrice() > store[j + 1].getPrice()) {
                // Hoán đổi 2 vị trí
                Food temp = store[j];
                store[j] = store[j + 1];
                store[j + 1] = temp;
            }
        }
    }
}

// 3. Thuật toán Sắp xếp nổi bọt (Bubble Sort) theo Tên A-Z (Không dùng <algorithm>)
void sortByName(vector<Food>& store) {
    int n = store.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (store[j].getName() > store[j + 1].getName()) {
                // Hoán đổi 2 vị trí
                Food temp = store[j];
                store[j] = store[j + 1];
                store[j + 1] = temp;
            }
        }
    }
}

int main() {
    vector<Food> store;
    int choice;

    do {
        cout << "\n================ MENU QUAN LY MON AN ================\n";
        cout << "1. Nhap danh sach mon an\n";
        cout << "2. Hien thi danh sach mon an\n";
        cout << "3. Tim mon an theo ma\n";
        cout << "4. Tim mon an theo ten\n";
        cout << "5. Cap nhat gia mon an\n";
        cout << "6. Cap nhat so luong mon an (Tiet giam/Mua hang)\n";
        cout << "7. Kiem tra mon an con hang\n";
        cout << "8. Sap xep danh sach theo gia tang dan (Bubble Sort)\n";
        cout << "9. Sap xep danh sach theo ten A-Z (Bubble Sort)\n";
        cout << "0. Thoat\n";
        cout << "-----------------------------------------------------\n";
        cout << "Chon chuc nang: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                int n;
                cout << "Nhap so luong mon an muon them: ";
                cin >> n;
                cin.ignore();
                for (int i = 0; i < n; i++) {
                    cout << "\n--- Nhap thong tin mon " << i + 1 << " ---\n";
                    Food f;
                    f.input();
                    store.push_back(f);
                }
                break;
            }
            case 2: {
                if (store.empty()) {
                    cout << "Danh sach hien dang rong!\n";
                } else {
                    cout << "\n=== DANH SACH MON AN ===\n";
                    for (size_t i = 0; i < store.size(); i++) {
                        store[i].display();
                    }
                }
                break;
            }
            case 3: {
                string searchId;
                cout << "Nhap ma mon can tim: ";
                getline(cin, searchId);
                bool found = false;
                for (size_t i = 0; i < store.size(); i++) {
                    if (store[i].getId() == searchId) {
                        cout << "Da tim thay: ";
                        store[i].display();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Khong tim thay mon an voi ma: " << searchId << endl;
                break;
            }
            case 4: {
                string searchName;
                cout << "Nhap ten mon can tim: ";
                getline(cin, searchName);
                bool found = false;
                for (size_t i = 0; i < store.size(); i++) {
                    if (store[i].getName() == searchName) {
                        cout << "Da tim thay: ";
                        store[i].display();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Khong tim thay mon an voi ten: " << searchName << endl;
                break;
            }
            case 5: {
                string searchId;
                cout << "Nhap ma mon can cap nhat gia: ";
                getline(cin, searchId);
                bool found = false;
                for (size_t i = 0; i < store.size(); i++) {
                    if (store[i].getId() == searchId) {
                        double newPrice;
                        cout << "Nhap gia moi: ";
                        cin >> newPrice;
                        cin.ignore();
                        store[i].setPrice(newPrice);
                        cout << "Da cap nhat gia thanh cong!\n";
                        store[i].display();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Khong tim thay mon an de cap nhat!\n";
                break;
            }
            case 6: {
                string searchId;
                cout << "Nhap ma mon can giam so luong (mua hang): ";
                getline(cin, searchId);
                bool found = false;
                for (size_t i = 0; i < store.size(); i++) {
                    if (store[i].getId() == searchId) {
                        int amount;
                        cout << "Nhap so luong can giam: ";
                        cin >> amount;
                        cin.ignore();
                        if (store[i].reduceQuantity(amount)) {
                            cout << "Giam so luong thanh cong!\n";
                            store[i].display();
                        } else {
                            cout << "So luong giam khong hop le hoac vuot qua so luong hien co!\n";
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Khong tim thay mon an!\n";
                break;
            }
            case 7: {
                string searchId;
                cout << "Nhap ma mon can kiem tra: ";
                getline(cin, searchId);
                bool found = false;
                for (size_t i = 0; i < store.size(); i++) {
                    if (store[i].getId() == searchId) {
                        if (store[i].isAvailable()) {
                            cout << "Mon " << store[i].getName() << " CON HANG (So luong: " << store[i].getQuantity() << ")\n";
                        } else {
                            cout << "Mon " << store[i].getName() << " DA HET HANG!\n";
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Khong tim thay mon an!\n";
                break;
            }
            case 8: {
                sortByPrice(store);
                cout << "Da sap xep danh sach theo gia tang dan!\n";
                break;
            }
            case 9: {
                sortByName(store);
                cout << "Da sap xep danh sach theo ten (A-Z)!\n";
                break;
            }
            case 0:
                cout << "Thoat chuong trinh. Tam biet!\n";
                break;
            default:
                cout << "Loi: Luachon khong hop le!\n";
        }
    } while (choice != 0);

    return 0;
}