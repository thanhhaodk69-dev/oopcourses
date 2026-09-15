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
// 5. Calculate total quantity
void calculateTotalQuantity(const Flower flowers[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += flowers[i].quantity;
    }
    cout << "Total quantity        : " << total << "\n";
}
// 6. Calculate average price (MỚI THÊM)
void calculateAveragePrice(const Flower flowers[], int n) {
    if (n <= 0) return;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += flowers[i].price;
    }
    double avg = sum / n;
    cout << "Average price         : " << fixed << setprecision(1) << avg << "\n";
}
// 7. Count flowers by type
void countFlowersByType(const Flower flowers[], int n) {
    cout << "\n=== COUNT FLOWERS BY TYPE ===\n";
    string types[20];
    int counts[20] = {0};
    int typeCount = 0;

    for (int i = 0; i < n; i++) {
        int foundIdx = -1;
        for (int j = 0; j < typeCount; j++) {
            if (types[j] == flowers[i].type) {
                foundIdx = j;
                break;
            }
        }
        if (foundIdx != -1) {
            counts[foundIdx]++;
        } else {
            types[typeCount] = flowers[i].type;
            counts[typeCount] = 1;
            typeCount++;
        }
    }

    for (int i = 0; i < typeCount; i++) {
        cout << "Type '" << types[i] << "': " << counts[i] << " flower(s)\n";
    }
}
// 8. Find all flowers of a given type (MỚI THÊM)
void findAllFlowersOfGivenType(const Flower flowers[], int n) {
    string targetType;
    cout << "\nEnter type to search: ";
    cin.ignore();
    getline(cin, targetType);

    cout << "\n=== FLOWERS OF TYPE: " << targetType << " ===\n";
    cout << left << setw(4) << "No" 
         << setw(16) << "Name" 
         << setw(10) << "Price" 
         << setw(8) << "Qty" 
         << setw(12) << "Type" << "\n";
    cout << "---------------------------------------------\n";

    bool found = false;
    int count = 1;
    for (int i = 0; i < n; i++) {
        if (flowers[i].type == targetType) {
            cout << left << setw(4) << count++
                 << setw(16) << flowers[i].name
                 << setw(10) << fixed << setprecision(1) << flowers[i].price
                 << setw(8) << flowers[i].quantity
                 << setw(12) << flowers[i].type << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No flowers found for type '" << targetType << "'.\n";
    }
}
// 9. Search by name
void searchByName(const Flower flowers[], int n) {
    string searchName;
    cout << "\nEnter flower name to search: ";
    getline(cin, searchName);

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (flowers[i].name == searchName) {
            cout << "\nFound flower information:\n";
            cout << "Name: " << flowers[i].name 
                 << " | Price: " << fixed << setprecision(1) << flowers[i].price 
                 << " | Quantity: " << flowers[i].quantity 
                 << " | Type: " << flowers[i].type << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Flower '" << searchName << "' not found.\n";
    }
}

int main() {
    Flower flowers[20];
    int n = 0;

    inputFlowers(flowers, n);
    displayAllFlowers(flowers, n);
    findMostExpensiveFlower(flowers, n);
    findCheapestFlower(flowers, n);
    findLargestQuantityFlower(flowers, n);
    calculateTotalQuantity(flowers, n);
    calculateAveragePrice(flowers, n);
    countFlowersByType(flowers, n);
    findAllFlowersOfGivenType(flowers, n);
    searchByName(flowers, n);

    return 0;
}