#include <iostream>
#include <string>

using namespace std;

int main() {
    string names[20];
    string ids[20];
    string phones[20];

    cout << "=== NHAP THONG TIN 20 SINH VIEN ===" << endl;
    for (int i = 0; i < 20; i++) {
        cout << "Enter student " << (i + 1) << ":" << endl;
        
        cout << "  Name : ";
        getline(cin, names[i]);

        cout << "  ID   : ";
        getline(cin, ids[i]);

        cout << "  Phone: ";
        getline(cin, phones[i]);

        cout << "-----------------------------------" << endl;
    }
    cout << "            STUDENT LIST           " << endl;

    for (int i = 0; i < 20; i++) {
        cout << "Student " << (i + 1) << ":" << endl;
        cout << "  Name       : " << names[i] << endl;
        cout << "  Student ID : " << ids[i] << endl;
        cout << "  Phone      : " << phones[i] << endl;
        cout << "-----------------------------------" << endl;
    }

    cout << "Total students: 20" << endl;

    return 0;
}