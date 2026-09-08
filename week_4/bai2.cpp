#include <iostream>
using namespace std;

int main() {
    // tính giai thừa n!
    int n;
    cout << "Nhap n (n >= 0): ";
    cin >> n;

    if (n < 0) {
        cout << "Khong tinh duoc giai thua cua so am!" << endl;
        return 0;
    }

    long long giaiThua = 1;
    for (int i = 1; i <= n; i++) {
        giaiThua *= i;
    }

    cout << n << "! = " << giaiThua << endl;
    return 0;
}