#include <iostream>
#include <string>
using namespace std;

void showScore(string name, double score) {
    cout << "Student: " << name << endl;
    cout << "Score  : " << score << endl;
    cout << "Keep going!" << endl;
}

int main() {
    string name = "Dinh Thanh Hao";
    double score = 3.6;
    showScore(name, score);

    return 0;
}