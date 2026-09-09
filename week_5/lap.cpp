#include <iostream>

using namespace std;

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

    cout << "\n STUDENT SCORES \n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << (i + 1) << ": " << scores[i] << "\n";
    }

    cout << "\n RESULTS \n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << (i + 1) << ": " << scores[i] 
             << " -> " << (scores[i] >= 5.0 ? "PASS" : "FAIL") << "\n";
    }

    int passedCount = 0;
    for (int i = 0; i < n; i++) {
        if (scores[i] >= 5.0) {
            passedCount++;
        }
    }
    int failedCount = n - passedCount;
    int passRate = (passedCount * 100) / n;

    cout << "\n STATISTICS \n";
    cout << "Passed   : " << passedCount << " students\n";
    cout << "Failed   : " << failedCount << " students\n";
    cout << "Pass rate: " << passRate << "%\n";

    double maxScore = scores[0];
    double minScore = scores[0];

    for (int i = 1; i < n; i++) {
        if (scores[i] > maxScore) maxScore = scores[i];
        if (scores[i] < minScore) minScore = scores[i];
    }

    cout << "\nHighest score: " << maxScore << "\n";
    cout << "Lowest score : " << minScore << "\n";

    cout << "\n CLASSIFICATION \n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << (i + 1) << ": " << scores[i] << " -> ";
        if (scores[i] >= 9.0) {
            cout << "Excellent\n";
        } else if (scores[i] >= 8.0) {
            cout << "Very Good\n";
        } else if (scores[i] >= 6.5) {
            cout << "Good\n";
        } else if (scores[i] >= 5.0) {
            cout << "Average\n";
        } else {
            cout << "Fail\n";
        }
    }
    return 0;
}