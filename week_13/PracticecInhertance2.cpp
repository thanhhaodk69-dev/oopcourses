#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. Class Employee (lớp cha)
class Employee {
protected:
    string cccd;
    string sdt;
    string address;
public:
    Employee();
    Employee(string c, string s, string a);

    virtual ~Employee() {}
    virtual void displayInfo() const;
    virtual double tinhLuong() const { return 0.0; } 
    virtual string getType() const { return "Employee"; } // Phân loại nhân viên

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
    int soGioLamViec;
    double donGia;

public:
    HourlyEmployee();
    HourlyEmployee(string c, string s, string a, int soGio, double donGia);
    double tinhLuong() const override;
    void displayInfo() const override;
    string getType() const override { return "HourlyEmployee"; }

    // Getters & Setters
    int getSoGioLamViec() const;
    double getDonGia() const;
    void setSoGioLamViec(int g);
    void setDonGia(double dg);
};

// 3. Class MonthlyEmployee (kế thừa từ Employee)
class MonthlyEmployee : public Employee {
private:
    double luongCoBan;
    double phuCap;
    double heSoThuong;

public:
    MonthlyEmployee();
    MonthlyEmployee(string c, string s, string a, double lcb, double pc, double hs);

    double tinhLuong() const override;
    void displayInfo() const override;
    string getType() const override { return "MonthlyEmployee"; }

    // Getters & Setters
    double getLuongCoBan() const;
    double getPhuCap() const;
    double getHeSoThuong() const;
    void setLuongCoBan(double lcb);
    void setPhuCap(double pc);
    void setHeSoThuong(double hs);
};

// ĐỊNH NGHĨA CÁC PHƯƠNG THỨC & CONSTRUCTOR
// --- Employee ---
Employee::Employee() { cccd = ""; sdt = ""; address = ""; }
Employee::Employee(string c, string s, string a) : cccd(c), sdt(s), address(a) {}

string Employee::getCCCD() const { return cccd; }
string Employee::getSDT() const { return sdt; }
string Employee::getAddress() const { return address; }
void Employee::setCCCD(string c) { cccd = c; }
void Employee::setSDT(string s) { sdt = s; }
void Employee::setAddress(string a) { address = a; }

void Employee::displayInfo() const {
    cout << "CCCD: " << cccd << endl;
    cout << "SDT: " << sdt << endl;
    cout << "Address: " << address << endl;
}

// --- HourlyEmployee ---
HourlyEmployee::HourlyEmployee() : Employee(), soGioLamViec(0), donGia(0.0) {}
HourlyEmployee::HourlyEmployee(string c, string s, string a, int soGio, double dg)
    : Employee(c, s, a), soGioLamViec(soGio), donGia(dg) {}

// Bài 1: Công thức tính lương HourlyEmployee
double HourlyEmployee::tinhLuong() const {
    return soGioLamViec * donGia;
}

// Bài 2: Ghi đè displayInfo
void HourlyEmployee::displayInfo() const {
    Employee::displayInfo();
    cout << "So gio lam viec: " << soGioLamViec << endl;
    cout << "Don gia: " << donGia << endl;
    cout << "Luong: " << tinhLuong() << endl;
}

int HourlyEmployee::getSoGioLamViec() const { return soGioLamViec; }
double HourlyEmployee::getDonGia() const { return donGia; }
void HourlyEmployee::setSoGioLamViec(int g) { soGioLamViec = g; }
void HourlyEmployee::setDonGia(double dg) { donGia = dg; }

// --- MonthlyEmployee ---
MonthlyEmployee::MonthlyEmployee() : Employee(), luongCoBan(0.0), phuCap(0.0), heSoThuong(0.0) {}
MonthlyEmployee::MonthlyEmployee(string c, string s, string a, double lcb, double pc, double hs)
    : Employee(c, s, a), luongCoBan(lcb), phuCap(pc), heSoThuong(hs) {}

// Bài 1: Công thức tính lương MonthlyEmployee
double MonthlyEmployee::tinhLuong() const {
    return luongCoBan + phuCap + (luongCoBan * heSoThuong);
}

// Bài 2: Ghi đè displayInfo
void MonthlyEmployee::displayInfo() const {
    Employee::displayInfo();
    cout << "Luong co ban: " << luongCoBan << endl;
    cout << "Phu cap: " << phuCap << endl;
    cout << "He so thuong: " << heSoThuong << endl;
    cout << "Luong: " << tinhLuong() << endl;
}

double MonthlyEmployee::getLuongCoBan() const { return luongCoBan; }
double MonthlyEmployee::getPhuCap() const { return phuCap; }
double MonthlyEmployee::getHeSoThuong() const { return heSoThuong; }
void MonthlyEmployee::setLuongCoBan(double lcb) { luongCoBan = lcb; }
void MonthlyEmployee::setPhuCap(double pc) { phuCap = pc; }
void MonthlyEmployee::setHeSoThuong(double hs) { heSoThuong = hs; }

int main() {
    // Bài 3: Khởi tạo ít nhất 2 đối tượng mỗi loại
    // Bài 4: Tạo mảng vector<Employee*>
    vector<Employee*> dsNhanVien;

    dsNhanVien.push_back(new HourlyEmployee("079876543210", "0901002003", "Ha Noi", 160, 50000));
    dsNhanVien.push_back(new HourlyEmployee("079111222333", "0901112233", "Hai Phong", 120, 60000));
    dsNhanVien.push_back(new MonthlyEmployee("079987654321", "0903004005", "Da Nang", 15000000, 2000000, 1.2));
    dsNhanVien.push_back(new MonthlyEmployee("079444555666", "0904445566", "Can Tho", 10000000, 1500000, 1.0));

    cout << "================ DANH SACH NHAN VIEN ================\n";
    for (const auto& nv : dsNhanVien) {
        nv->displayInfo();
        cout << "-----------------------------------\n";
    }

    // Bài 4: Tính tổng quỹ lương
    double tongQuyLuong = 0;
    for (const auto& nv : dsNhanVien) {
        tongQuyLuong += nv->tinhLuong();
    }
    cout << "\n Tong quy luong cua cong ty: " << tongQuyLuong << " VND\n";

    // Bài 5: Tìm nhân viên lương cao nhất & thấp nhất
    if (!dsNhanVien.empty()) {
        Employee* maxNV = dsNhanVien[0];
        Employee* minNV = dsNhanVien[0];

        for (size_t i = 1; i < dsNhanVien.size(); ++i) {
            if (dsNhanVien[i]->tinhLuong() > maxNV->tinhLuong()) maxNV = dsNhanVien[i];
            if (dsNhanVien[i]->tinhLuong() < minNV->tinhLuong()) minNV = dsNhanVien[i];
        }

        cout << "\n Nhan vien co LUONG CAO NHAT (" << maxNV->tinhLuong() << " VND):\n";
        maxNV->displayInfo();

        cout << "\n Nhan vien co LUONG THAP NHAT (" << minNV->tinhLuong() << " VND):\n";
        minNV->displayInfo();
    }

    // Bài 6: Đếm số lượng nhân viên từng loại
    int countHourly = 0, countMonthly = 0;
    for (const auto& nv : dsNhanVien) {
        if (nv->getType() == "HourlyEmployee") countHourly++;
        else if (nv->getType() == "MonthlyEmployee") countMonthly++;
    }
    cout << "\n So luong HourlyEmployee: " << countHourly << "\n";
    cout << " So luong MonthlyEmployee: " << countMonthly << "\n";

    // Bài 7: Tìm và hiển thị danh sách NV có lương > X
    double luongNguong;
    cout << "\n Nhap muc luong toi thieu can tim: ";
    cin >> luongNguong;

    cout << "---> Danh sach nhan vien co luong > " << luongNguong << " VND:\n";
    bool found = false;
    for (const auto& nv : dsNhanVien) {
        if (nv->tinhLuong() > luongNguong) {
            nv->displayInfo();
            cout << "-----------------------------------\n";
            found = true;
        }
    }
    if (!found) cout << "Khong co nhan vien nao dat muc luong nay.\n";

    // Bài 8: Sắp xếp giảm dần theo lương (Dùng Bubble Sort - Không dùng <algorithm>)
    int n = dsNhanVien.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (dsNhanVien[j]->tinhLuong() < dsNhanVien[j + 1]->tinhLuong()) {
                Employee* temp = dsNhanVien[j];
                dsNhanVien[j] = dsNhanVien[j + 1];
                dsNhanVien[j + 1] = temp;
            }
        }
    }

    cout << "\n DANH SACH NHAN VIEN SAU KHI SAP XEP GIAM DAN THEO LUONG:\n";
    for (const auto& nv : dsNhanVien) {
        nv->displayInfo();
        cout << "-----------------------------------\n";
    }

    for (auto nv : dsNhanVien) {
        delete nv;
    }

    return 0;
}