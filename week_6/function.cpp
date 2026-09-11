#include <iostream>
using namespace std;

// 1. Định nghĩa struct để chứa nhiều kết quả
struct ScoreInfo {
    double sum;
    double average;
    int count;
    double maxScore;
    double minScore;
};

// 2. Hàm nhận vào mảng double[] và kích thước mảng size
ScoreInfo analyzeScores(const double scores[], int size) {
    ScoreInfo result;
    result.sum = 0;
    result.count = size;

    if (result.count == 0) {
        result.average = 0;
        result.maxScore = 0;
        result.minScore = 0;
        return result;
    }

    result.minScore = scores[0];
    result.maxScore = scores[0];

    // Duyệt mảng bằng vòng lặp for thông thường
    for (int i = 0; i < size; i++) {
        result.sum += scores[i];
        if (scores[i] > result.maxScore) result.maxScore = scores[i];
        if (scores[i] < result.minScore) result.minScore = scores[i];
    }

    result.average = result.sum / result.count;
    return result;
}

int main() {
    double scores[] = {8.5, 7.0, 9.5, 6.0, 8.0};
    int size = sizeof(scores) / sizeof(scores[0]); 

    ScoreInfo info = analyzeScores(scores, size);

    // In kết quả
    cout << "Total: " << info.sum << endl;
    cout << "Average: " << info.average << endl;
    cout << "Max score: " << info.maxScore << endl;
    cout << "Min score: " << info.minScore << endl;

    return 0;
}