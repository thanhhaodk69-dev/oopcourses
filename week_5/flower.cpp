#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_FLOWERS = 20;

struct Flower {
    string name;
    double price;
    int quantity;
    string type;
};

int main() {
    int n;

    do {
        cout << "How many flowers? ";
        cin >> n;
        if (n < 1 || n > MAX_FLOWERS) {
            cout << "Invalid number! Please enter from 1 to " << MAX_FLOWERS << ".\n";
        }
    } while (n < 1 || n > MAX_FLOWERS);

    Flower flowers[MAX_FLOWERS];

    for (int i = 0; i < n; i++) {
        cout << "\nFlower " << (i + 1) << ":\n";
        
        cout << "  Name: ";
        cin >> flowers[i].name;

        do {
            cout << "  Price: ";
            cin >> flowers[i].price;
            if (flowers[i].price <= 0) {
                cout << "  Invalid price! Must be > 0.\n";
            }
        } while (flowers[i].price <= 0);

        do {
            cout << "  Quantity: ";
            cin >> flowers[i].quantity;
            if (flowers[i].quantity < 0) {
                cout << "  Invalid quantity! Must be >= 0.\n";
            }
        } while (flowers[i].quantity < 0);

        cout << "  Type: ";
        cin >> flowers[i].type;
    }
    // 2. display the list of flowers
    cout << "\n FLOWER SHOP \n";
    cout << left << setw(4) << "No" 
         << setw(12) << "Name" 
         << setw(10) << "Price" 
         << setw(8) << "Qty" 
         << setw(12) << "Type" << "\n";
    cout << "---------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << left << setw(4) << (i + 1)
             << setw(12) << flowers[i].name
             << setw(10) << fixed << setprecision(1) << flowers[i].price
             << setw(8) << flowers[i].quantity
             << setw(12) << flowers[i].type << "\n";
    }
    // 3. find the most expensive flower and the cheapest flower
    int maxIdx = 0;
    int minIdx = 0;

    for (int i = 1; i < n; i++) {
        if (flowers[i].price > flowers[maxIdx].price) {
            maxIdx = i;
        }
        if (flowers[i].price < flowers[minIdx].price) {
            minIdx = i;
        }
    }

    cout << "\n--- ANALYSIS ---\n";
    cout << "Most expensive flower : " << flowers[maxIdx].name << " (" << fixed << setprecision(1) << flowers[maxIdx].price << ")\n";
    cout << "Cheapest flower       : " << flowers[minIdx].name << " (" << fixed << setprecision(1) << flowers[minIdx].price << ")\n";
    // 4. Count how many flowers belong to each type
    cout << "\n--- COUNT BY TYPE ---\n";
    bool counted[MAX_FLOWERS] = {false};

    for (int i = 0; i < n; i++) {
        if (!counted[i]) {
            int typeCount = 0;
            for (int j = i; j < n; j++) {
                if (flowers[j].type == flowers[i].type) {
                    typeCount++;
                    counted[j] = true; 
                }
            }
            cout << left << setw(12) << flowers[i].type << ": " << typeCount << "\n";
        }
    }

    return 0;
}