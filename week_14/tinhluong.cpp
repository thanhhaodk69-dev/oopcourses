#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
private:
    string cccd;
    string phone;
    string address;

public:
    Employee() : cccd(""), phone(""), address("") {}
    Employee(string c, string p, string a) : cccd(c), phone(p), address(a) {}

    virtual double calculateSalary(int month, int year) = 0;
    
    // Phương thức thuần ảo tính lương theo năm
    virtual double calculateYearlySalary(int year) = 0;

    virtual void displayInfo() {
        cout << "CCCD: " << cccd << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
    }

    virtual ~Employee() = default;
};

class HourlyEmployee : public Employee {
private:
    int hours;
    double salaryPerHour;
    int month, year;

public:
    HourlyEmployee() : Employee(), hours(0), salaryPerHour(0), month(0), year(0) {}
    HourlyEmployee(string c, string p, string a, int h, double s, int m, int y)
        : Employee(c, p, a), hours(h), salaryPerHour(s), month(m), year(y) {}

    double calculateSalary(int m, int y) override {
        if (m == month && y == year)
            return hours * salaryPerHour;
        return 0;
    }

    double calculateYearlySalary(int y) override {
        if (y == year) {
            return calculateSalary(month, y);
        }
        return 0;
    }
};

class MonthlyEmployee : public Employee {
private:
    double monthlySalary;
    int month, year;

public:
    MonthlyEmployee(string c, string p, string a, double s, int m, int y)
        : Employee(c, p, a), monthlySalary(s), month(m), year(y) {}

    double calculateSalary(int m, int y) override {
        if (m == month && y == year)
            return monthlySalary;
        return 0;
    }

    double calculateYearlySalary(int y) override {
        if (y == year) {
            return monthlySalary; 
        }
        return 0;
    }
};

class DailyEmployee : public Employee {
private:
    int numberOfDays;
    double salaryPerDay;
    int month, year;

public:
    DailyEmployee(string c, string p, string a, int d, double s, int m, int y)
        : Employee(c, p, a), numberOfDays(d), salaryPerDay(s), month(m), year(y) {}

    double calculateSalary(int m, int y) override {
        if (m == month && y == year)
            return numberOfDays * salaryPerDay;
        return 0;
    }

    double calculateYearlySalary(int y) override {
        if (y == year) {
            return calculateSalary(month, y);
        }
        return 0;
    }
};

double calculateCompanyYearlySalary(Employee* employees[], int size, int year) {
    double total = 0;
    for (int i = 0; i < size; ++i) {
        total += employees[i]->calculateYearlySalary(year);
    }
    return total;
}

int main() {
    HourlyEmployee h("001", "0901", "HCM", 160, 50000, 10, 2026);
    MonthlyEmployee m("002", "0902", "Dong Nai", 15000000, 10, 2026);
    DailyEmployee d("003", "0903", "Ha Noi", 22, 400000, 10, 2026);

    Employee* employees[] = {&h, &m, &d};
    int size = sizeof(employees) / sizeof(employees[0]);

    cout << "--- LUONG THANG 10/2026 ---" << endl;
    for (Employee* e : employees) {
        cout << e->calculateSalary(10, 2026) << endl;
    }

    cout << "\n--- LUONG CAN NHAN VIEN TRONG NAM 2026 ---" << endl;
    for (Employee* e : employees) {
        cout << e->calculateYearlySalary(2026) << endl;
    }

    cout << "\nTong luong cong ty nam 2026: " 
         << calculateCompanyYearlySalary(employees, size, 2026) << endl;

    return 0;
}