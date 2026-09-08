#include <iostream>
using namespace std;

bool isPerfect(int n) {
    if (n <= 1) return false;
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    if (isPerfect(n)) {
        cout << n << " la so hoan hao." << endl;
    } else {
        cout << n << " khong phai la so hoan hao." << endl;
    }
    return 0;
}