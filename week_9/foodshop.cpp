#include <iostream>
#include <string>

using namespace std;

// struct food
struct Food {
    string id;
    string name;
    double price;
    int quantity;
};

// struct order
struct Order {
    string id;
    string customerName;
    string address;
    Food food;
    int quantity;
    string status;
};

// struct restaurant
struct Restaurant {
    string name;
    string address;
    string phone;

    Food foods[100];
    int foodCount;

    Order orders[100];
    int orderCount;
};

// chức năng 1: nhập thông tin nhà hàng
void inputRestaurantInfo(Restaurant &restaurant) {
    cout << "Nhap ten cua hang: ";
    getline(cin, restaurant.name);

    cout << "Nhap dia chi: ";
    getline(cin, restaurant.address);

    cout << "Nhap so dien thoai: ";
    getline(cin, restaurant.phone);

    restaurant.foodCount = 0;
    restaurant.orderCount = 0;

    cout << "Da nhap thong tin cua hang thanh cong!\n";
}

// chức năng 2: thêm món ăn vào danh sách thực đơn
void addFood(Restaurant &restaurant) {
    Food food;

    cout << "Nhap ma mon: ";
    getline(cin, food.id);

    cout << "Nhap ten mon: ";
    getline(cin, food.name);

    cout << "Nhap don gia: ";
    cin >> food.price;

    cout << "Nhap so luong: ";
    cin >> food.quantity;

    cin.ignore();

    restaurant.foods[restaurant.foodCount] = food;
    restaurant.foodCount++;

    cout << "Them mon an thanh cong!\n";
}

// chức năng 3: hiển thị danh sách món ăn
void displayFoods(Restaurant &restaurant) {
    if (restaurant.foodCount == 0) {
        cout << "Chua co mon an nao!\n";
        return;
    }

    cout << "\nDanh sach mon an:\n";

    for (int i = 0; i < restaurant.foodCount; i++) {
        cout << "Ma mon: " << restaurant.foods[i].id << endl;
        cout << "Ten mon: " << restaurant.foods[i].name << endl;
        cout << "Don gia: " << restaurant.foods[i].price << endl;
        cout << "So luong: " << restaurant.foods[i].quantity << endl;
        cout << endl;
    }
}

// chức năng 4: tìm kiếm món ăn theo mã hoặc tên
void searchFood(Restaurant &restaurant) {
    int choice;
    string keyword;

    cout << "\n1. Tim theo ma mon\n";
    cout << "2. Tim theo ten mon\n";
    cout << "Nhap lua chon: ";
    cin >> choice;
    cin.ignore();

    cout << "Nhap thong tin can tim: ";
    getline(cin, keyword);

    bool found = false;

    for (int i = 0; i < restaurant.foodCount; i++) {
        if ((choice == 1 && restaurant.foods[i].id == keyword) ||
            (choice == 2 && restaurant.foods[i].name == keyword)) {

            cout << "\nTim thay mon an:\n";
            cout << "Ma mon: " << restaurant.foods[i].id << endl;
            cout << "Ten mon: " << restaurant.foods[i].name << endl;
            cout << "Don gia: " << restaurant.foods[i].price << endl;
            cout << "So luong: " << restaurant.foods[i].quantity << endl;

            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay mon an!\n";
    }
}

// chức năng 5: cập nhật giá và thông tin món ăn
void updateFood(Restaurant &restaurant) {
    string id;
    int choice;

    cout << "Nhap ma mon can cap nhat: ";
    getline(cin, id);

    bool found = false;

    for (int i = 0; i < restaurant.foodCount; i++) {
        if (restaurant.foods[i].id == id) {
            found = true;

            cout << "\nMon an hien tai:\n";
            cout << "Ma mon: " << restaurant.foods[i].id << endl;
            cout << "Ten mon: " << restaurant.foods[i].name << endl;
            cout << "Don gia: " << restaurant.foods[i].price << endl;
            cout << "So luong: " << restaurant.foods[i].quantity << endl;

            cout << "\n1. Cap nhat gia\n";
            cout << "2. Cap nhat so luong\n";
            cout << "Nhap lua chon: ";
            cin >> choice;

            if (choice == 1) {
                cout << "Nhap gia moi: ";
                cin >> restaurant.foods[i].price;

                cout << "Cap nhat gia thanh cong!\n";
            }
            else if (choice == 2) {
                cout << "Nhap so luong moi: ";
                cin >> restaurant.foods[i].quantity;

                cout << "Cap nhat so luong thanh cong!\n";
            }
            else {
                cout << "Lua chon khong hop le!\n";
            }

            cin.ignore();

            cout << "\nThong tin mon an sau khi cap nhat:\n";
            cout << "Ma mon: " << restaurant.foods[i].id << endl;
            cout << "Ten mon: " << restaurant.foods[i].name << endl;
            cout << "Don gia: " << restaurant.foods[i].price << endl;
            cout << "So luong: " << restaurant.foods[i].quantity << endl;

            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay mon an!\n";
    }
}

// chức năng 6: tạo đơn hàng
void createOrder(Restaurant &restaurant) {
    Order order;

    cout << "Nhap ma don hang: ";
    getline(cin, order.id);

    cout << "Nhap ten khach hang: ";
    getline(cin, order.customerName);

    cout << "Nhap dia chi: ";
    getline(cin, order.address);

    cout << "Nhap ma mon: ";
    getline(cin, order.food.id);

    cout << "Nhap so luong: ";
    cin >> order.quantity;

    cin.ignore();

    order.status = "Cho xu ly";

    restaurant.orders[restaurant.orderCount] = order;
    restaurant.orderCount++;

    cout << "\nDon hang vua tao:\n";
    cout << "Ma don hang: " << order.id << endl;
    cout << "Ten khach hang: " << order.customerName << endl;
    cout << "Dia chi: " << order.address << endl;
    cout << "Ma mon: " << order.food.id << endl;
    cout << "So luong: " << order.quantity << endl;
    cout << "Trang thai: " << order.status << endl;

    cout << "Tao don hang thanh cong!\n";
}

int main() {
    Restaurant restaurant;

    // chức năng 1
    inputRestaurantInfo(restaurant);
    // chức năng 2
    addFood(restaurant);
    addFood(restaurant);
    // chức năng 3
    displayFoods(restaurant);
    // chức năng 4
    searchFood(restaurant);
    // chức năng 5
    updateFood(restaurant);
    // chức năng 6
    createOrder(restaurant);

    return 0;
}