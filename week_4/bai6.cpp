#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int temp = abs(n);
    int tong = 0;

    while (temp > 0) {
        tong += temp % 10;
        temp /= 10;
    }

    cout << "Tong cac chu so: " << tong << endl;
    return 0;
}