#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int temp = abs(n);
    int daoNguoc = 0;

    while (temp > 0) {
        daoNguoc = daoNguoc * 10 + temp % 10;
        temp /= 10;
    }

    if (n < 0) daoNguoc = -daoNguoc;

    cout << "So dao nguoc la: " << daoNguoc << endl;
    return 0;
}