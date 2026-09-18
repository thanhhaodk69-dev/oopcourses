#include <iostream>
using namespace std;

void setFirstToZero(int arr[]) {
    arr[0] = 0;
}

void incrementAll(int (&arr)[4]) {
    for (int i = 0; i < 4; ++i) {
        arr[i] += 1;
    }
}

void setLastToTen(int& x) {
    x = 10;
}

int main() {
    //Main Practice
    cout << "=== Main Practice Output ===" << endl;
    int nums[4] = {1, 2, 3, 4};
    setFirstToZero(nums);
    incrementAll(nums);
    
    cout << nums[0] << " " << nums[1] << " " 
         << nums[2] << " " << nums[3] << endl;

    //Variation
    cout << "\n=== Try a Variation Output ===" << endl;
    int nums2[4] = {3, 5, 7, 9};
    setLastToTen(nums2[3]);

    for (int i = 0; i < 4; ++i) {
        cout << nums2[i] << " "; 
    }
    cout << endl;

    return 0;
}