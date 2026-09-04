#include <iostream>
using namespace std;

void giaiphuongtrinhbac1(double a, double b) {
    if (a != 0) {
        double x = -b / a;
        cout << "Phuong trinh co nghiem duy nhat x = " << x << endl;
    } else {
        if (b == 0) {
            cout << "Phuong trinh co vo so nghiem" << endl;
        } else {
            cout << "Phuong trinh vo nghiem" << endl;
        }
    }
}

int main() {
    double a, b;
    cout << "Nhap a va b: ";
    cin >> a >> b;

    giaiphuongtrinhbac1(a, b);

    return 0;
}