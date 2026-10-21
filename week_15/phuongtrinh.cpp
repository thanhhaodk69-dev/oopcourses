#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class PT {
protected:
    double a, b;

public:
    // Constructors
    PT() : a(0), b(0) {}
    PT(double a, double b) : a(a), b(b) {}
    virtual ~PT() {}

    // Getters
    double getA() const { return a; }
    double getB() const { return b; }

    // Setters
    void setA(double a) { this->a = a; }
    void setB(double b) { this->b = b; }

    // Phương thức giải phương trình
    virtual void solve() const {
        cout << "\n--- Giai Phuong Trinh Bac 1: " << a << "x + " << b << " = 0 ---" << endl;
        if (a == 0) {
            if (b == 0) {
                cout << "Phuong trinh co vo so nghiem." << endl;
            } else {
                cout << "Phuong trinh vo nghiem." << endl;
            }
        } else {
            cout << "Phuong trinh co 1 nghiem duy nhat: x = " << -b / a << endl;
        }
    }
};

class PTB2 : public PT {
protected:
    double c;

public:
    // Constructors
    PTB2() : PT(), c(0) {}
    PTB2(double a, double b, double c) : PT(a, b), c(c) {}

    // Getter & Setter cho c
    double getC() const { return c; }
    void setC(double c) { this->c = c; }

    // Ghi đè phương thức solve
    void solve() const override {
        cout << "\n--- Giai Phuong Trinh Bac 2: " << a << "x^2 + " << b << "x + " << c << " = 0 ---" << endl;
        
        if (a == 0) {
            PT pt1(b, c);
            pt1.solve();
            return;
        }

        double delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "Phuong trinh vo nghiem (trong tap so thuc)." << endl;
        } else if (delta == 0) {
            cout << "Phuong trinh co nghiem kep: x1 = x2 = " << -b / (2 * a) << endl;
        } else {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem phan biet:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
    }
};

class PTB3 : public PT {
private:
    double c, d;

public:
    // Constructors
    PTB3() : PT(), c(0), d(0) {}
    PTB3(double a, double b, double c, double d) : PT(a, b), c(c), d(d) {}

    // Getters & Setters
    double getC() const { return c; }
    double getD() const { return d; }
    void setC(double c) { this->c = c; }
    void setD(double d) { this->d = d; }

    void solve() const override {
        cout << "\n--- Giai Phuong Trinh Bac 3: " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << " = 0 ---" << endl;

        if (a == 0) {
            PTB2 pt2(b, c, d);
            pt2.solve();
            return;
        }

        double p = (3 * a * c - b * b) / (3 * a * a);
        double q = (2 * b * b * b - 9 * a * b * c + 27 * a * a * d) / (27 * a * a * a);
        double delta = (q * q / 4.0) + (p * p * p / 27.0);

        if (delta > 0) {
            double u = cbrt(-q / 2.0 + sqrt(delta));
            double v = cbrt(-q / 2.0 - sqrt(delta));
            double x1 = u + v - (b / (3 * a));
            cout << "Phuong trinh co 1 nghiem thuc:" << endl;
            cout << "x1 = " << x1 << endl;
        } else if (delta == 0) {
            double u = cbrt(-q / 2.0);
            double x1 = 2 * u - (b / (3 * a));
            double x2 = -u - (b / (3 * a));
            cout << "Phuong trinh co nghiem boi:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = x3 = " << x2 << endl;
        } else {
            double r = sqrt(-p * p * p / 27.0);
            double phi = acos(-q / (2 * r));
            double m = 2 * cbrt(r);

            double x1 = m * cos(phi / 3.0) - (b / (3 * a));
            double x2 = m * cos((phi + 2 * M_PI) / 3.0) - (b / (3 * a));
            double x3 = m * cos((phi + 4 * M_PI) / 3.0) - (b / (3 * a));

            cout << "Phuong trinh co 3 nghiem phan biet:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
            cout << "x3 = " << x3 << endl;
        }
    }
};

int main() {
    cout << fixed << setprecision(4);

    // 1. Thử nghiệm Phương trình bậc 1
    PT pt1(2, -4);
    pt1.solve();

    // 2. Thử nghiệm Phương trình bậc 2
    PTB2 pt2(1, -5, 6);
    pt2.solve();

    // 3. Thử nghiệm Phương trình bậc 3
    PTB3 pt3(1, -6, 11, -6);
    pt3.solve();

    cout << "\n=== DEMO DA HINH (POLYMORPHISM) ===" << endl;
    PT* danhSachPT[3];
    danhSachPT[0] = new PT(3, 9);
    danhSachPT[1] = new PTB2(1, 2, 1);
    danhSachPT[2] = new PTB3(1, 0, 0, -8);

    for (int i = 0; i < 3; ++i) {
        danhSachPT[i]->solve();
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < 3; ++i) {
        delete danhSachPT[i];
    }

    return 0;
}