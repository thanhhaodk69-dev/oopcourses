#include <iostream>
using namespace std;

// Su dung thuat toan Euclid
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

    cout << "Uoc chung lon nhat cua " << a << " va " << b << " la: " << gcd(a, b) << endl;
    return 0;
}