#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MAX_STUDENTS = 20;

    string names[MAX_STUDENTS];
    string ids[MAX_STUDENTS];
    string phones[MAX_STUDENTS];

    int N;

    do {
        cout << "Enter number of students (2-20): ";
        cin >> N;

        if (N < 2 || N > MAX_STUDENTS) {
            cout << "Invalid number! Please enter a number from 2 to 20.\n";
        }

    } while (N < 2 || N > MAX_STUDENTS);

    cin.ignore();

    for (int i = 0; i < N; i++) {
        cout << "\n--- Student " << i + 1 << " ---\n";

        cout << "Enter name: ";
        getline(cin, names[i]);

        cout << "Enter student ID: ";
        getline(cin, ids[i]);

        cout << "Enter phone number: ";
        getline(cin, phones[i]);
    }

    cout << "\n====================================\n";
    cout << "       STUDENT INFORMATION\n";
    cout << "====================================\n";

    for (int i = 0; i < N; i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Name : " << names[i] << endl;
        cout << "ID   : " << ids[i] << endl;
        cout << "Phone: " << phones[i] << endl;
    }

    return 0;
}