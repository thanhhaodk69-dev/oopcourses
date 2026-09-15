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
// 3. Find Students Above Average 
void findStudentsAboveAverage(const double scores[], int n) {
    double totalScore = 0;
    for (int i = 0; i < n; i++) {
        totalScore += scores[i];
    }
    double avgScore = totalScore / n;

    cout << "\nAverage score: " << avgScore << "\n";
    cout << "Students above average:\n";
    for (int i = 0; i < n; i++) {
        if (scores[i] > avgScore) {
            cout << "Student " << (i + 1) << ": " << scores[i] << "\n";
        }
    }
}
// 4. Find the Second Highest Score 
void findSecondHighestScore(const double scores[], int n) {
    double maxScore = scores[0];
    for (int i = 1; i < n; i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
        }
    }

    double secondMax = -1;
    for (int i = 0; i < n; i++) {
        if (scores[i] < maxScore) {
            if (secondMax == -1 || scores[i] > secondMax) {
                secondMax = scores[i];
            }
        }
    }

    cout << "\nHighest score: " << maxScore << "\n";
    if (secondMax != -1) {
        cout << "Second highest score: " << secondMax << "\n";
    } else {
        cout << "All students have the same score.\n";
    }
}
void searchScore(const double scores[], int n) {
    double target;
    cout << "\nEnter score to search: ";
    cin >> target;

    cout << "Found at:\n";
    bool foundAny = false;
    for (int i = 0; i < n; i++) {
        if (scores[i] == target) {
            cout << "Student " << (i + 1) << "\n";
            foundAny = true;
        }
    }
    if (!foundAny) {
        cout << "No student found with score " << target << "\n";
    }
}
// 6. Count Score Frequency
void countScoreFrequency(const double scores[], int n) {
    double x;
    cout << "\nEnter score to count frequency: ";
    cin >> x;

    int freq = 0;
    for (int i = 0; i < n; i++) {
        if (scores[i] == x) {
            freq++;
        }
    }
    cout << "Score " << x << " appears " << freq << " times.\n";
}
// 7. Find First Failing Student 
void findFirstFailingStudent(const double scores[], int n) {
    cout << "\nFIRST FAILING STUDENT\n";
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
}
// 8. Compare Adjacent Students
void compareAdjacentStudents(const double scores[], int n) {
    cout << "\nCOMPARE ADJACENT STUDENTS\n";
    for (int i = 0; i < n - 1; i++) {
        if (scores[i + 1] > scores[i]) {
            cout << "Student " << (i + 2) << " improved compared to Student " << (i + 1) << "\n";
        }
    }
}
// 9. Find the Longest Pass Streak
void findLongestPassStreak(const double scores[], int n) {
    cout << "\nLONGEST PASS STREAK\n";
    int maxStreak = 0;
    int currentStreak = 0;

    for (int i = 0; i < n; i++) {
        if (scores[i] >= 5.0) {
            currentStreak++;
            if (currentStreak > maxStreak) {
                maxStreak = currentStreak;
            }
        } else {
            currentStreak = 0;
        }
    }
    cout << "Longest pass streak: " << maxStreak << " students\n";
}
// 10. Create a Score Distribution
void createScoreDistribution(const double scores[], int n) {
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;

    for (int i = 0; i < n; i++) {
        if (scores[i] < 5.0) c1++;
        else if (scores[i] < 6.5) c2++;
        else if (scores[i] < 8.0) c3++;
        else if (scores[i] < 9.0) c4++;
        else c5++;
    }

    cout << "\n====== SCORE DISTRIBUTION ======\n";
    cout << "0 - <5   : "; for (int i = 0; i < c1; i++) cout << "*"; cout << " " << c1 << "\n";
    cout << "5 - <6.5 : "; for (int i = 0; i < c2; i++) cout << "*"; cout << " " << c2 << "\n";
    cout << "6.5 - <8 : "; for (int i = 0; i < c3; i++) cout << "*"; cout << " " << c3 << "\n";
    cout << "8 - <9   : "; for (int i = 0; i < c4; i++) cout << "*"; cout << " " << c4 << "\n";
    cout << "9 - 10   : "; for (int i = 0; i < c5; i++) cout << "*"; cout << " " << c5 << "\n";
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

    // --- Find Students Above Average --- 
    findStudentsAboveAverage(scores, n);

    // --- Find the Second Highest Score --- 
    findSecondHighestScore(scores, n);

    // --- Search for a Specific Score --- 
    searchScore(scores, n);

    // --- Count Score Frequency ---
    countScoreFrequency(scores, n);

    // --- Find First Failing Student ---
    findFirstFailingStudent(scores, n);

    // --- Compare Adjacent Students ---
    compareAdjacentStudents(scores, n);

    // --- Find the Longest Pass Streak ---
    findLongestPassStreak(scores, n);

    // --- Create Score Distribution ---
    createScoreDistribution(scores, n);

    return 0;
}