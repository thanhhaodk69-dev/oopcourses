#include <iostream>
#include <string>

using namespace std;

int main() {
    // 1. Insert a String
    string str1 = "Hello World!";
    str1.insert(6, "C++ ");
    cout << "1. Insert Result: " << str1 << endl;

    // 2. Find a Substring
    string str2 = "I love C++ programming";
    string sub2 = "C++";
    size_t pos2 = str2.find(sub2);
    if (pos2 != string::npos) {
        cout << "2. Find Result  : Position " << pos2 << endl;
    } else {
        cout << "2. Find Result  : Not found" << endl;
    }

    // 3. Count Characters (with & without spaces)
    string str3 = "Hello C++";
    int countAll = str3.length();
    int countNoSpaces = 0;
    for (char c : str3) {
        if (c != ' ') countNoSpaces++;
    }
    cout << "3. Count Result : " << countAll << " (with spaces), " 
         << countNoSpaces << " (without spaces)" << endl;

    // 4. Replace a Substring
    string str4 = "I like Java";
    string oldSub = "Java";
    string newSub = "C++";
    size_t pos4 = str4.find(oldSub);
    if (pos4 != string::npos) {
        str4.replace(pos4, oldSub.length(), newSub);
    }
    cout << "4. Replace Result: " << str4 << endl;

    // 5. Extract a Substring
    string str5 = "Computer Science";
    int startPos = 9;
    int len = 7;
    string extracted = str5.substr(startPos, len);
    cout << "5. Extract Result: " << extracted << endl;

    return 0;
}