#include <iostream>
using namespace std;

void swapValues1(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void swapValues2(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a1 = 5, b1 = 10;
    cout << "Before swap: a1 = " << a1 << ", b1 = " << b1 << endl;
    swapValues1(a1, b1);
    cout << "After swap  : a1 = " << a1 << ", b1 = " << b1 << endl << endl;

    int a2 = 5, b2 = 10;
    cout << "Before swap: a2 = " << a2 << ", b2 = " << b2 << endl;
    swapValues2(a2, b2);
    cout << "After swap  : a2 = " << a2 << ", b2 = " << b2 << endl << endl;

    return 0;
}