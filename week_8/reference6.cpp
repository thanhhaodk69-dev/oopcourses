#include <iostream>
#include <vector>

using namespace std;

void insertSubarray(vector<int>& arr, const vector<int>& sub, int index) {
    arr.insert(arr.begin() + index, sub.begin(), sub.end());
}

void printVector(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    cout << "=== TRUONG HOP 1 (Practice 6) ===" << endl;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> sub1 = {9, 9};
    int pos1 = 2;

    cout << "Mang ban dau: ";
    printVector(nums1);

    insertSubarray(nums1, sub1, pos1);

    cout << "Mang sau khi chen (pos = 2): ";
    printVector(nums1);

    cout << "\n=== TRUONG HOP 2 (Try Another Case) ===" << endl;
    vector<int> nums2 = {10, 20, 30};
    vector<int> sub2 = {7, 8, 9};
    int pos2 = 1;

    cout << "Mang ban dau: ";
    printVector(nums2);

    insertSubarray(nums2, sub2, pos2);

    cout << "Mang sau khi chen (pos = 1): ";
    printVector(nums2);

    return 0;
}