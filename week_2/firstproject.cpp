#include <iostream>
#include <string> 

using namespace std;

int main() {
    // Tiêu đề
    cout << "===========================" << "\n";
    cout << "      CVP CHALLENGE APP    " << "\n";
    cout << "===========================" << "\n";

    
    string myName = "Alex";           
    string myCourse = "C++ For Newbies";
    int currentYear = 2026;           
    double initialIq = 100.5;         

    const double MIN_PASS_GPA = 2.0; 

    // Hiển thị thông tin ban đầu
    cout << "Student: " << myName << "\n";
    cout << "Course: " << myCourse << "\n";
    cout << "Current Year: " << currentYear << "\n";
    cout << "Initial IQ: " << initialIq << "\n";
    cout << "Minimum GPA needed: " << MIN_PASS_GPA << "\n";
    cout << "---------------------------" << "\n";

    int remainingYears = 4 - (currentYear - 2022); 
    

    double targetGpa = MIN_PASS_GPA * 1.75; 

    initialIq -= 10.5;

    cout << "Analysis Results:" << "\n";
    cout << "Years of study remaining: " << remainingYears << "\n";
    cout << "Recommended Target GPA: " << targetGpa << "\n";
    cout << "Updated IQ after learning: " << initialIq << "\n"; // IQ đã cập nhật

    cout << "===========================" << "\n";
    return 0;
}