#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Flower {
    string name;
    double price;
    int quantity;
    string type;
};

// Hàm nhập dữ liệu hoa (Price > 0, Qty >= 0)
void inputFlowers(Flower flowers[], int &n) {
    do {
        cout << "Enter number of flowers (1 <= N <= 20): ";
        cin >> n;
    } while (n < 1 || n > 20);

    for (int i = 0; i < n; i++) {
        cout << "\n--- Enter info for Flower " << (i + 1) << " ---\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, flowers[i].name);

        do {
            cout << "Price (> 0): ";
            cin >> flowers[i].price;
        } while (flowers[i].price <= 0);

        do {
            cout << "Quantity (>= 0): ";
            cin >> flowers[i].quantity;
        } while (flowers[i].quantity < 0);

        cout << "Type: ";
        cin.ignore();
        getline(cin, flowers[i].type);
    }
}

// 1. Display all flowers
void displayAllFlowers(const Flower flowers[], int n) {
    cout << "\n===== FLOWER SHOP =====\n\n";
    cout << left << setw(4) << "No" 
         << setw(16) << "Name" 
         << setw(10) << "Price" 
         << setw(8) << "Qty" 
         << setw(12) << "Type" << "\n";
    cout << "---------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << left << setw(4) << (i + 1)
             << setw(16) << flowers[i].name
             << setw(10) << fixed << setprecision(1) << flowers[i].price
             << setw(8) << flowers[i].quantity
             << setw(12) << flowers[i].type << "\n";
    }
}
// 2. Find the most expensive flower 
void findMostExpensiveFlower(const Flower flowers[], int n) {
    if (n <= 0) return;
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (flowers[i].price > flowers[maxIdx].price) {
            maxIdx = i;
        }
    }
    cout << "\nMost expensive flower : " << flowers[maxIdx].name 
         << " (" << fixed << setprecision(1) << flowers[maxIdx].price << ")\n";
}
// 3. Find the cheapest flower
void findCheapestFlower(const Flower flowers[], int n) {
    if (n <= 0) return;
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        if (flowers[i].price < flowers[minIdx].price) {
            minIdx = i;
        }
    }
    cout << "Cheapest flower       : " << flowers[minIdx].name 
         << " (" << fixed << setprecision(1) << flowers[minIdx].price << ")\n";
}
// 4. Find the flower with the largest quantity
void findLargestQuantityFlower(const Flower flowers[], int n) {
    if (n <= 0) return;
    int maxQtyIdx = 0;
    for (int i = 1; i < n; i++) {
        if (flowers[i].quantity > flowers[maxQtyIdx].quantity) {
            maxQtyIdx = i;
        }
    }
    cout << "Largest quantity      : " << flowers[maxQtyIdx].name 
         << " (" << flowers[maxQtyIdx].quantity << ")\n";
}

int main() {
    Flower flowers[20];
    int n = 0;

    inputFlowers(flowers, n);
    displayAllFlowers(flowers, n);
    findMostExpensiveFlower(flowers, n);
    findCheapestFlower(flowers, n);
    findLargestQuantityFlower(flowers, n);

    return 0;
}