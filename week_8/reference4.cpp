#include <iostream>
using namespace std;

void addFive(int& x) {
    x += 5;
}

void swapValues(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void changeValue(int x) {
    x = 100; // Pass by value
}

void changeRef(int& x) {
    x = 200; // Pass by reference
}

int main() {
    // 1. Modify through a Reference
    cout << "=== 1. Modify through a Reference ===" << endl;
    int n = 7;
    int& r = n;
    r = 15;
    cout << n << " " << r << endl;

    // 2. Use a Reference Parameter
    cout << "\n=== 2. Use a Reference Parameter ===" << endl;
    int a2 = 10;
    addFive(a2);
    cout << a2 << endl;

    // 3. Swap using References
    cout << "\n=== 3. Swap using References ===" << endl;
    int a3 = 4, b3 = 9;
    swapValues(a3, b3);
    cout << a3 << " " << b3 << endl;

    // 4. Reference vs Value
    cout << "\n=== 4. Reference vs Value ===" << endl;
    int a4 = 5;
    changeValue(a4);
    cout << "After changeValue: " << a4 << endl;
    changeRef(a4);
    cout << "After changeRef: " << a4 << endl;

    return 0;
}