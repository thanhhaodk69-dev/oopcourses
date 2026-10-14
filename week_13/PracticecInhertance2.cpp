#include <iostream>
#include <string>

using namespace std;

// 1. Class Employee (lớp cha)
class Employee {
protected:
    string cccd;        // CCCD
    string sdt;         // Số điện thoại
    string address;     // Địa chỉ

public:
    Employee();                                  // Khởi tạo mặc định
    Employee(string c, string s, string a);      // Khởi tạo có tham số
    void displayInfo() const;                    // Hiển thị thông tin

    // Getters & Setters
    string getCCCD() const;
    string getSDT() const;
    string getAddress() const;
    void setCCCD(string c);
    void setSDT(string s);
    void setAddress(string a);
};

// 2. Class HourlyEmployee (kế thừa từ Employee)
class HourlyEmployee : public Employee {
private:
    int soGioLamViec;   // Số giờ làm việc
    double donGia;      // Đơn giá (vnd/giờ)

public:
    HourlyEmployee();                            // Khởi tạo mặc định
    HourlyEmployee(string c, string s, string a, int soGio, double donGia);

    void displayInfo() const;                    // Ghi đè hiển thị thông tin
    double tinhLuong() const;                    // Tính lương = giờ * đơn giá

    // Getters & Setters
    int getSoGioLamViec() const;
    double getDonGia() const;
    void setSoGioLamViec(int g);
    void setDonGia(double dg);
};

// 3. Class MonthlyEmployee (kế thừa từ Employee)
class MonthlyEmployee : public Employee {
private:
    double luongCoBan;   // Lương cơ bản
    double phuCap;       // Phụ cấp
    double heSoThuong;   // Hệ số thưởng

public:
    MonthlyEmployee();                           // Khởi tạo mặc định
    MonthlyEmployee(string c, string s, string a, double lcb, double pc, double hs);

    void displayInfo() const;                    // Ghi đè hiển thị thông tin
    double tinhLuong() const;                    // Tính lương

    // Getters & Setters
    double getLuongCoBan() const;
    double getPhuCap() const;
    double getHeSoThuong() const;
    void setLuongCoBan(double lcb);
    void setPhuCap(double pc);
    void setHeSoThuong(double hs);
};
// --- 1. Định nghĩa cho Employee ---
Employee::Employee() {
    cccd = "";
    sdt = "";
    address = "";
}

Employee::Employee(string c, string s, string a) {
    cccd = c;
    sdt = s;
    address = a;
}

string Employee::getCCCD() const { return cccd; }
string Employee::getSDT() const { return sdt; }
string Employee::getAddress() const { return address; }
void Employee::setCCCD(string c) { cccd = c; }
void Employee::setSDT(string s) { sdt = s; }
void Employee::setAddress(string a) { address = a; }

// --- 2. Định nghĩa cho HourlyEmployee ---
HourlyEmployee::HourlyEmployee() : Employee() {
    soGioLamViec = 0;
    donGia = 0.0;
}

HourlyEmployee::HourlyEmployee(string c, string s, string a, int soGio, double dg)
    : Employee(c, s, a) {
    soGioLamViec = soGio;
    donGia = dg;
}

double HourlyEmployee::tinhLuong() const {
    return soGioLamViec * donGia; // Lương = số giờ làm việc * đơn giá
}

int HourlyEmployee::getSoGioLamViec() const { return soGioLamViec; }
double HourlyEmployee::getDonGia() const { return donGia; }
void HourlyEmployee::setSoGioLamViec(int g) { soGioLamViec = g; }
void HourlyEmployee::setDonGia(double dg) { donGia = dg; }

// --- 3. Định nghĩa cho MonthlyEmployee ---
MonthlyEmployee::MonthlyEmployee() : Employee() {
    luongCoBan = 0.0;
    phuCap = 0.0;
    heSoThuong = 0.0;
}

MonthlyEmployee::MonthlyEmployee(string c, string s, string a, double lcb, double pc, double hs)
    : Employee(c, s, a) {
    luongCoBan = lcb;
    phuCap = pc;
    heSoThuong = hs;
}

double MonthlyEmployee::tinhLuong() const {
    // Lương = lương cơ bản + phụ cấp + (lương cơ bản * hệ số thưởng)
    return luongCoBan + phuCap + (luongCoBan * heSoThuong);
}

double MonthlyEmployee::getLuongCoBan() const { return luongCoBan; }
double MonthlyEmployee::getPhuCap() const { return phuCap; }
double MonthlyEmployee::getHeSoThuong() const { return heSoThuong; }
void MonthlyEmployee::setLuongCoBan(double lcb) { luongCoBan = lcb; }
void MonthlyEmployee::setPhuCap(double pc) { phuCap = pc; }
void MonthlyEmployee::setHeSoThuong(double hs) { heSoThuong = hs; }

void Employee::displayInfo() const {
    cout << "CCCD: " << cccd << endl;
    cout << "SDT: " << sdt << endl;
    cout << "Address: " << address << endl;
}

void HourlyEmployee::displayInfo() const {
    Employee::displayInfo(); // gọi hàm lớp cha
    cout << "So gio lam viec: " << soGioLamViec << endl;
    cout << "Don gia: " << donGia << endl;
    cout << "Luong: " << tinhLuong() << endl;
}

void MonthlyEmployee::displayInfo() const {
    Employee::displayInfo(); // gọi hàm lớp cha
    cout << "Luong co ban: " << luongCoBan << endl;
    cout << "Phu cap: " << phuCap << endl;
    cout << "He so thuong: " << heSoThuong << endl;
    cout << "Luong: " << tinhLuong() << endl;
}

int main() {
    // Tạo đối tượng Employee
    Employee e1("079123456789", "Nguyen Van A", "Ho Chi Minh");

    // Tạo đối tượng HourlyEmployee
    HourlyEmployee h1("079876543210", "Tran Thi B", "Ha Noi", 160, 50000);

    // Tạo đối tượng MonthlyEmployee
    MonthlyEmployee m1("079987654321", "Le Minh C", "Da Nang", 15000000, 2000000, 1.2);

    // Hiển thị thông tin
    cout << "--- Thong tin Employee ---" << endl;
    e1.displayInfo();

    cout << "\n--- Thong tin HourlyEmployee ---" << endl;
    h1.displayInfo();

    cout << "\n--- Thong tin MonthlyEmployee ---" << endl;
    m1.displayInfo();

    return 0;
}