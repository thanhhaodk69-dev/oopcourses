#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Employee {
private:
    string id;
    string name;

public:
    // Constructors
    Employee() : id(""), name("") {}
    Employee(string id, string name) : id(id), name(name) {}

    // Getters
    string getId() const { return id; }
    string getName() const { return name; }

    // Setters
    void setId(string id) { this->id = id; }
    void setName(string name) { this->name = name; }

    // Phương thức ảo để tính lương và hiển thị
    virtual double calculateSalaryMonth() const { return 0; }
    virtual double calculateSalaryYear() const { return calculateSalaryMonth() * 12; }

    virtual void display() const {
        cout << "ID: " << id << " | Ten: " << name;
    }

    virtual ~Employee() {}
};

class HourlyEmployee : public Employee {
private:
    double hours;
    double salaryPerHour;
    int month;
    int year;

public:
    // Constructors
    HourlyEmployee() : Employee(), hours(0), salaryPerHour(0), month(1), year(2026) {}
    HourlyEmployee(string id, string name, double hours, double salaryPerHour, int month, int year)
        : Employee(id, name), hours(hours), salaryPerHour(salaryPerHour), month(month), year(year) {}

    // Getters
    double getHours() const { return hours; }
    double getSalaryPerHour() const { return salaryPerHour; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Setters
    void setHours(double hours) { this->hours = hours; }
    void setSalaryPerHour(double salaryPerHour) { this->salaryPerHour = salaryPerHour; }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }

    // Tinh luong theo thang va nam
    double calculateSalaryMonth() const override {
        return hours * salaryPerHour;
    }

    double calculateSalaryYear() const override {
        return calculateSalaryMonth() * 12; // Gia dinh luong hang thang deu đan
    }

    void display() const override {
        Employee::display();
        cout << " | Loai: Theo gio" << endl
             << " | So gio: " << hours << endl
             << " | Luong/gio: " << salaryPerHour << endl
             << " | Thang/Nam: " << month << "/" << year << endl
             << " | Luong Thang: " << fixed << setprecision(0) << calculateSalaryMonth() << endl
             << " | Luong Nam: " << calculateSalaryYear() << endl;
    }
};

class MonthlyEmployee : public Employee {
private:
    double monthlySalary;
    int month;
    int year;

public:
    // Constructors
    MonthlyEmployee() : Employee(), monthlySalary(0), month(1), year(2026) {}
    MonthlyEmployee(string id, string name, double monthlySalary, int month, int year)
        : Employee(id, name), monthlySalary(monthlySalary), month(month), year(year) {}

    // Getters
    double getMonthlySalary() const { return monthlySalary; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Setters
    void setMonthlySalary(double monthlySalary) { this->monthlySalary = monthlySalary; }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }

    // Tinh luong theo thang va nam
    double calculateSalaryMonth() const override {
        return monthlySalary;
    }

    double calculateSalaryYear() const override {
        return monthlySalary * 12;
    }

    void display() const override {
        Employee::display();
        cout << " | Loai: Coded Thang" << endl
             << " | Thang/Nam: " << month << "/" << year << endl
             << " | Luong Thang: " << fixed << setprecision(0) << calculateSalaryMonth() << endl
             << " | Luong Nam: " << calculateSalaryYear() << endl;
    }
};

class DailyEmployee : public Employee {
private:
    int numberOfDays;
    double salaryPerDay;
    int month;
    int year;

public:
    // Constructors
    DailyEmployee() : Employee(), numberOfDays(0), salaryPerDay(0), month(1), year(2026) {}
    DailyEmployee(string id, string name, int numberOfDays, double salaryPerDay, int month, int year)
        : Employee(id, name), numberOfDays(numberOfDays), salaryPerDay(salaryPerDay), month(month), year(year) {}

    // Getters
    int getNumberOfDays() const { return numberOfDays; }
    double getSalaryPerDay() const { return salaryPerDay; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Setters
    void setNumberOfDays(int numberOfDays) { this->numberOfDays = numberOfDays; }
    void setSalaryPerDay(double salaryPerDay) { this->salaryPerDay = salaryPerDay; }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }

    // Tinh luong theo thang va nam
    double calculateSalaryMonth() const override {
        return numberOfDays * salaryPerDay;
    }

    double calculateSalaryYear() const override {
        return calculateSalaryMonth() * 12;
    }

    void display() const override {
        Employee::display();
        cout << " | Loai: Theo ngay" << endl
             << " | So ngay: " << numberOfDays << endl
             << " | Luong/ngay: " << salaryPerDay << endl
             << " | Thang/Nam: " << month << "/" << year << endl
             << " | Luong Thang: " << fixed << setprecision(0) << calculateSalaryMonth() << endl
             << " | Luong Nam: " << calculateSalaryYear() << endl;
    }
};

int main() {
    HourlyEmployee emp1("NV01", "Nguyen Van A", 160, 50000, 10, 2026);
    MonthlyEmployee emp2("NV02", "Tran Thi B", 15000000, 10, 2026);
    DailyEmployee emp3("NV03", "Le Van C", 22, 400000, 10, 2026);

    cout << "--- THONG TIN NHAN VIEN ---" << endl;
    emp1.display();
    emp2.display();
    emp3.display();

    return 0;
}