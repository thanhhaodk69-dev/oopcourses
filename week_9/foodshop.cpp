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

    cout << "\nMon an vua them:\n";
    cout << "Ma mon: " << food.id << endl;
    cout << "Ten mon: " << food.name << endl;
    cout << "Don gia: " << food.price << endl;
    cout << "So luong: " << food.quantity << endl;

    cout << "Them mon an thanh cong!\n";
}

int main() {
    Restaurant restaurant;

    // chức năng 1
    inputRestaurantInfo(restaurant);
    // chức năng 2
    addFood(restaurant);

    return 0;
}