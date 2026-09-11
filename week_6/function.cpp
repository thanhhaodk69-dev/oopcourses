#include <iostream>
using namespace std;

int maxValue(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int x = 15;
    int y = 20;
    int maxNum = maxValue(x, y);
    cout << "Maximum value: " << maxNum << endl;

    return 0;
}