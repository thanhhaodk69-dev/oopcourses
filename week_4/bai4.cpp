#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int temp = n;
    int daoNguoc = 0;

    while (temp > 0) {
        daoNguoc = daoNguoc * 10 + temp % 10;
        temp /= 10;
    }

    if (n == daoNguoc) {
        cout << n << " la so doi xung." << endl;
    } else {
        cout << n << " khong phai la so doi xung." << endl;
    }
    return 0;
}