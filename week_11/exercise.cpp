#include <iostream>
#include <string>

using namespace std;

// Class Date
class Date
{
public:
    int year;
    int month;
    int day;

    Date()
    {
        this->year = 0;
        this->month = 0;
        this->day = 0;
    }

    Date(int year, int month, int day)
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }
};


// Class Student
class Student
{
private:
    // Properties - thuộc tính của Student
    string name;
    string address;
    Date birthdate;
    string cccd;

public:
    // Constructor 0 tham số
    Student()
    {
        this->name = "";
        this->address = "";
        this->birthdate = Date();
        this->cccd = "";
    }
    // Constructor 1 tham số
    Student(string name)
    {
        this->name = name;
        this->address = "";
        this->birthdate = Date();
        this->cccd = "";
    }

    // Constructor 2 tham số
    Student(string name, string address)
    {
        this->name = name;
        this->address = address;
        this->birthdate = Date();
        this->cccd = "";
    }

    // Constructor 3 tham số
    Student(string name, string address, Date birthdate)
    {
        this->name = name;
        this->address = address;
        this->birthdate = birthdate;
        this->cccd = "";
    }

    // Constructor 4 tham số
    Student(string name, string address, Date birthdate, string cccd)
    {
        this->name = name;
        this->address = address;
        this->birthdate = birthdate;
        this->cccd = cccd;
    }


    // Hiển thị thông tin Student
    void display()
    {
        cout << "Name: " << this->name << endl;
        cout << "Address: " << this->address << endl;

        cout << "Birthdate: "
             << this->birthdate.day << "/"
             << this->birthdate.month << "/"
             << this->birthdate.year << endl;

        cout << "CCCD: " << this->cccd << endl;
    }
};

int main()
{
    // 0 tham số
    Student student1;
    // 1 tham số
    Student student2("Huong");
    // 2 tham số
    Student student3("Hao", "Vo Van Ngan");
    // 3 tham số
    Date date1(2005, 10, 20);
    Student student4("Nam", "Ho Chi Minh", date1);
    // 4 tham số
    Date date2(2004, 5, 15);
    Student student5(
        "Lan",
        "Cao Bang",
        date2,
        "012345678901"
    );


    cout << "===== STUDENT 1 =====" << endl;
    student1.display();

    cout << "\n===== STUDENT 2 =====" << endl;
    student2.display();

    cout << "\n===== STUDENT 3 =====" << endl;
    student3.display();

    cout << "\n===== STUDENT 4 =====" << endl;
    student4.display();

    cout << "\n===== STUDENT 5 =====" << endl;
    student5.display();

    return 0;
}