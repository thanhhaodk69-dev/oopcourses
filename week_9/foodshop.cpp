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

// chuc nang 1: nhap thong tin cua hang
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

int main() {
    Restaurant restaurant;

    // chuc nang 1
    inputRestaurantInfo(restaurant);

    cout << "\nThong tin cua hang:\n";
    cout << "Ten cua hang: " << restaurant.name << endl;
    cout << "Dia chi: " << restaurant.address << endl;
    cout << "So dien thoai: " << restaurant.phone << endl;

    return 0;
}