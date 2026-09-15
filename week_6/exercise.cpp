#include <iostream>

using namespace std;

// 1. Count Excellent Students (>= 9.0)
int countExcellentStudents(const double scores[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (scores[i] >= 9.0) {
            count++;
        }
    }
    return count;
}
// 2. Count Students in a Score Range [a, b]
int countStudentsInRange(const double scores[], int n, double minScore, double maxScore) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (scores[i] >= minScore && scores[i] <= maxScore) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    do {
        cout << "How many students? ";
        cin >> n;
        if (n < 2 || n > 20) {
            cout << "Invalid number of students!\nPlease enter a number from 2 to 20.\n";
        }
    } while (n < 2 || n > 20);

    double scores[20];
    for (int i = 0; i < n; i++) {
        do {
            cout << "Enter score for student " << (i + 1) << ": ";
            cin >> scores[i];
            if (scores[i] < 0 || scores[i] > 10) {
                cout << "Invalid score! Please enter a value from 0 to 10.\n";
            }
        } while (scores[i] < 0 || scores[i] > 10);
    }

    // --- Count Excellent Students ---
    int excellentCount = countExcellentStudents(scores, n);
    cout << "\nNumber of excellent students: " << excellentCount << "\n";

    // --- Count Students in a Score Range [7.0, 9.0] ---
    double minR, maxR;
    cout << "\nEnter minimum score: ";
    cin >> minR;
    cout << "Enter maximum score: ";
    cin >> maxR;

    int rangeCount = countStudentsInRange(scores, n, minR, maxR);
    cout << "Students in range: " << rangeCount << "\n";

    return 0;
}