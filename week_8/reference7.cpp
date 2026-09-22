#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function for Part 2
void addExclaim(string& str) {
    str += "!";
}

// Function for Part 3
void swapStr(string& a, string& b) {
    string temp = a;
    a = b;
    b = temp;
}

// Function for Part 4
void changeFirstChar(string& str) {
    str[0] = 'P';
}

// Function for Part 6
void toUpperCase(string& str) {
    for (char& c : str) {
        c = toupper(c);
    }
}

int main() {
    cout << "=== Part 1 ===" << endl;
    string s1 = "Hello";
    string& r1 = s1;
    r1 += " World!";
    cout << s1 << endl;
    cout << r1 << endl;

    cout << "\n=== Part 2 ===" << endl;
    string msg = "Good Day";
    addExclaim(msg);
    cout << msg << endl;

    cout << "\n=== Part 3 ===" << endl;
    string x = "cat";
    string y = "dog";
    swapStr(x, y);
    cout << x << " " << y << endl;

    cout << "\n=== Part 4 ===" << endl;
    string name = "python";
    changeFirstChar(name);
    cout << name << endl;

    cout << "\n=== Part 5 ===" << endl;
    string s5 = "Hello";
    string r5 = s5;
    string& ref5 = s5;
    r5 += "!!!";
    ref5 += "???";
    cout << "s: " << s5 << endl;
    cout << "r: " << r5 << endl;
    cout << "ref: " << ref5 << endl;

    cout << "\n=== Part 6 ===" << endl;
    string text = "C++ is Fun!";
    toUpperCase(text);
    cout << text << endl;

    return 0;
}