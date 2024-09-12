#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> numbers, int target) {
    if (numbers.empty()) {
        return -1;
    }

    int left = 0;
    int right = numbers.size() - 1;

    while (left + 1 < right) {
        int mid = left + (right - left) / 2;

        if (numbers[mid] == target) {
            return mid;
        } else if (numbers[mid] < target) {
            left = mid;
        } else {
            right = mid;
        }
    }

    if (numbers[left] == target) {
        return left;
    }

    if (numbers[right] == target) {
        return right;
    }
    
    return -1;
}

int main() {
    vector<int> numbers = {2, 5, 8, 9, 12, 13};

    cout << "The index is " << binarySearch(numbers, 9) << endl;

    return 0;
}