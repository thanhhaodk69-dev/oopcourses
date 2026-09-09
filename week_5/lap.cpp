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
//Đếm học sinh giỏi >= 9.0
    int excellentCount = 0;
    for (int i = 0; i < n; i++) {
        if (scores[i] >= 9.0) {
            excellentCount++;
        }
    }
    cout << "\n EXCELLENT STUDENTS \n";
    cout << "Number of excellent students: " << excellentCount << "\n";
//đếm học sinh trong khoảng [a, b]
    double minR, maxR;
    cout << "\n SCORE RANGE \n";
    cout << "Enter minimum score: ";
    cin >> minR;
    cout << "Enter maximum score: ";
    cin >> maxR;

    int rangeCount = 0;
    for (int i = 0; i < n; i++) {
        if (scores[i] >= minR && scores[i] <= maxR) {
            rangeCount++;
        }
    }
    cout << "Students in range: " << rangeCount << "\n";
//Học sinh trên trung bình lớp
    double totalScore = 0;
    for (int i = 0; i < n; i++) {
        totalScore += scores[i];
    }
    double avgScore = totalScore / n;

    cout << "\n ABOVE AVERAGE \n";
    cout << "Average score: " << avgScore << "\n";
    cout << "Students above average:\n";
    for (int i = 0; i < n; i++) {
        if (scores[i] > avgScore) {
            cout << "Student " << (i + 1) << ": " << scores[i] << "\n";
        }
    }
//Điểm cao thứ 2
    double secondMax = -1;
    for (int i = 0; i < n; i++) {
        if (scores[i] < maxScore) {
            if (secondMax == -1 || scores[i] > secondMax) {
                secondMax = scores[i];
            }
        }
    }

    cout << "\n SECOND HIGHEST SCORE \n";
    cout << "Highest score: " << maxScore << "\n";
    if (secondMax != -1) {
        cout << "Second highest score: " << secondMax << "\n";
    } else {
        cout << "All students have the same score.\n";
    }
    // Tìm vị trí các học sinh đạt điểm X
    double searchScore;
    cout << "\n SEARCH SCORE \n";
    cout << "Enter score to search: ";
    cin >> searchScore;

    cout << "Found at:\n";
    bool foundAny = false;
    for (int i = 0; i < n; i++) {
        if (scores[i] == searchScore) {
            cout << "Student " << (i + 1) << "\n";
            foundAny = true;
        }
    }
    if (!foundAny) {
        cout << "No student found with score " << searchScore << "\n";
    }
    // Học sinh trượt đầu tiên
    cout << "\n FIRST FAILING STUDENT \n";
    int failIdx = -1;
    for (int i = 0; i < n; i++) {
        if (scores[i] < 5.0) {
            failIdx = i;
            break;
        }
    }

    if (failIdx != -1) {
        cout << "First failing student: Student " << (failIdx + 1) << ": " << scores[failIdx] << "\n";
    } else {
        cout << "All students pass!\n";
    }
    return 0;
}