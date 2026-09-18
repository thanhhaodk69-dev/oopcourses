#include <iostream>
#include <string>

using namespace std;

int main() {
    // 1. Nhập một câu từ người dùng
    string text;
    cout << "Enter a sentence: ";
    getline(cin, text);

    // 2. Hiển thị độ dài của câu
    cout << "Length of the sentence: " << text.length() << endl;

    // 3. Tìm vị trí của từ "C++"
    string target = "C++";
    size_t pos = text.find(target);

    // 4. Nếu tìm thấy, in từ đó ra từ vị trí đã tìm được (dùng substr)
    if (pos != string::npos) {
        cout << "Found position: " << pos << endl;
        string word = text.substr(pos, target.length());
        cout << "Extracted word: " << word << endl;
    } else {
        cout << "Word \"" << target << "\" not found!" << endl;
    }

    // 5. Thay thế từ "C++" thành "Programming" và hiển thị câu mới
    string newText = text;
    if (pos != string::npos) {
        newText.replace(pos, target.length(), "Programming");
    }
    cout << "New sentence: " << newText << endl;

    return 0;
}