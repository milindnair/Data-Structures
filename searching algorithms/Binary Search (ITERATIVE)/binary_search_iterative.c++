#include <iostream>
#include <vector>
using namespace std;

// Iterative binary search function
int binarySearch(vector<int> arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // target not found
}

// Driver code
int main() {
    vector<int> arr = {2, 3, 6, 7, 10, 14, 19, 23, 27};
    int target = 7;

    int result = binarySearch(arr, target);

    if (result == -1) {
        cout << "Element not present in array" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }

    return 0;
}
