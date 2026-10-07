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


    // Nhập thông tin Student
    void input()
    {
        cout << "Nhap ten: ";
        getline(cin, this->name);

        cout << "Nhap tinh: ";
        getline(cin, this->address);

        cout << "Nhap ngay sinh: ";
        cin >> this->birthdate.day;

        cout << "Nhap thang sinh: ";
        cin >> this->birthdate.month;

        cout << "Nhap nam sinh: ";
        cin >> this->birthdate.year;

        cin.ignore();

        cout << "Nhap CCCD: ";
        getline(cin, this->cccd);
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


    // Lấy năm sinh
    int getBirthYear()
    {
        return this->birthdate.year;
    }


    // Lấy địa chỉ
    string getAddress()
    {
        return this->address;
    }


    // Thống kê theo năm sinh
    static void statisticByBirthYear(Student students[], int n, int year)
    {
        int count = 0;

        cout << "\n===== SINH VIEN SINH NAM "
             << year << " =====" << endl;

        for (int i = 0; i < n; i++)
        {
            if (students[i].getBirthYear() == year)
            {
                students[i].display();
                cout << endl;
                count++;
            }
        }

        cout << "So luong sinh vien sinh nam "
             << year << ": " << count << endl;
    }


    // Thống kê theo tỉnh
    static void statisticByProvince(
        Student students[],
        int n,
        string province)
    {
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (students[i].getAddress() == province)
            {
                count++;
            }
        }

        cout << province << ": "
             << count << " sinh vien" << endl;
    }
};


int main()
{
    // Nhập số lượng sinh viên
    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    cin.ignore();


    // Tạo danh sách sinh viên
    Student students[100];


    // Nhập thông tin từng sinh viên
    for (int i = 0; i < n; i++)
    {
        cout << "\n===== NHAP SINH VIEN "
             << i + 1 << " =====" << endl;

        students[i].input();
    }


    // Hiển thị danh sách sinh viên
    cout << "\n\n===== DANH SACH SINH VIEN ====="
         << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;

        students[i].display();
    }


    // Nhập năm muốn thống kê
    int year;

    cout << "\nNhap nam sinh can thong ke: ";
    cin >> year;

    Student::statisticByBirthYear(
        students,
        n,
        year
    );


    // Nhập tỉnh muốn thống kê
    string province;

    cin.ignore();

    cout << "\nNhap tinh can thong ke: ";
    getline(cin, province);


    cout << "\n===== THONG KE THEO TINH ====="
         << endl;

    Student::statisticByProvince(
        students,
        n,
        province
    );


    return 0;
}
