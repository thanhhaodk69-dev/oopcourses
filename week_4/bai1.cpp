#include <iostream>
using namespace std;

int main() {
    //Tìm số lớn nhất trong 3 số a, b, c
    double a, b, c;
    cout << "Nhap 3 so a, b, c: ";
    cin >> a >> b >> c;

    double maxVal = a;
    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;

    cout << "So lon nhat la: " << maxVal << endl;
    return 0;
}