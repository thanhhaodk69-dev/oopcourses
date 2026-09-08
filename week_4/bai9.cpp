#include <iostream>
using namespace std;

double luyThua(double x, int n) {
    double res = 1.0;
    long long exp = abs((long long)n);

    for (long long i = 0; i < exp; i++) {
        res *= x;
    }

    if (n < 0) return 1.0 / res;
    return res;
}

int main() {
    double x;
    int n;
    cout << "Nhap co so x: ";
    cin >> x;
    cout << "Nhap mu n: ";
    cin >> n;

    cout << x << "^" << n << " = " << luyThua(x, n) << endl;
    return 0;
}