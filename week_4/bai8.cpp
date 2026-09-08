#include <iostream>
using namespace std;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a, b;
    cout << "Nhap 2 so a va b: ";
    cin >> a >> b;

    if (a == 0 || b == 0) {
        cout << "Boi chung nho nhat: 0" << endl;
    } else {
        long long lcm = (1LL * abs(a) * abs(b)) / gcd(a, b);
        cout << "Boi chung nho nhat la: " << lcm << endl;
    }
    return 0;
}