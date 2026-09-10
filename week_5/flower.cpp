#include <iostream>
#include <string>

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

    return 0;
}