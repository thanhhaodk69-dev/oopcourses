#include <iostream>
#include <string>
#include <vector>

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


    // Nhập thông tin
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

    void display()
    {
        cout << "Name: " << this->name << endl;

        cout << "Address: "
             << this->address << endl;

        cout << "Birthdate: "
             << this->birthdate.day << "/"
             << this->birthdate.month << "/"
             << this->birthdate.year << endl;

        cout << "CCCD: "
             << this->cccd << endl;
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


    // Lấy danh sách sinh viên theo năm sinh
    static vector<Student> getStudentbyYear(
        int year,
        vector<Student> students)
    {
        vector<Student> result;

        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getBirthYear() == year)
            {
                result.push_back(students[i]);
            }
        }

        return result;
    }


    // Lấy danh sách sinh viên theo tỉnh
    static vector<Student> getStudentbyProvince(
        string province,
        vector<Student> students)
    {
        vector<Student> result;

        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getAddress() == province)
            {
                result.push_back(students[i]);
            }
        }

        return result;
    }
};


// Hàm display danh sách
void display(vector<Student> students)
{
    for (int i = 0; i < students.size(); i++)
    {
        cout << "\n===== STUDENT "
             << i + 1
             << " =====" << endl;

        students[i].display();
    }
}

int main()
{
    int n;

    // Nhập số lượng sinh viên
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();
    // Tạo vector chứa danh sách sinh viên
    vector<Student> students;

    // NHẬP DANH SÁCH SINH VIÊN
    for (int i = 0; i < n; i++)
    {
        cout << "\n===== NHAP SINH VIEN "
             << i + 1 << " =====" << endl;

        Student student;

        student.input();

        students.push_back(student);
    }

    // HIỂN THỊ DANH SÁCH SINH VIÊN
    cout << "\n\n===== DANH SACH SINH VIEN ====="
         << endl;

    display(students);

    // THỐNG KÊ THEO NĂM SINH
    int year;

    cout << "\nNhap nam sinh can thong ke: ";
    cin >> year;


    vector<Student> s;

    s = Student::getStudentbyYear(
        year,
        students
    );

    cout << "\n===== SINH VIEN SINH NAM "
         << year << " =====" << endl;

    cout << "So luong: "
         << s.size() << endl;

    display(s);

    // THỐNG KÊ THEO TỈNH
    string province;

    cin.ignore();

    cout << "\nNhap tinh can thong ke: ";
    getline(cin, province);


    s = Student::getStudentbyProvince(
        province,
        students
    );


    cout << "\n===== THONG KE THEO TINH ====="
         << endl;

    cout << "Tinh: " << province << endl;

    cout << "So luong sinh vien: "
         << s.size() << endl;

    display(s);


    return 0;
}

