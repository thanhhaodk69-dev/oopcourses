#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Vui long nhap so nguyen duong!" << endl;
        return 0;
    }

    int count = 0;

    // In ra cac uoc va dem số lượng
    cout << "Divisors: ";
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
            count++;
        }
    }
    cout << endl;

    cout << "So luong uoc so: " << count << endl;

    return 0;
}