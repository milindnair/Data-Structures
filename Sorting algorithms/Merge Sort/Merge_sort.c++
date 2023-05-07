#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int start, int mid, int end) {
    int left_size = mid - start + 1;
    int right_size = end - mid;
    
    // create temporary arrays to hold the left and right halves
    vector<int> left_half(left_size);
    vector<int> right_half(right_size);
    
    // copy the elements of left half to temporary array
    for (int i = 0; i < left_size; i++) {
        left_half[i] = arr[start + i];
    }
    
    // copy the elements of right half to temporary array
    for (int i = 0; i < right_size; i++) {
        right_half[i] = arr[mid + 1 + i];
    }
    
    int i = 0, j = 0, k = start;
    
    // merge the left and right halves back into the original array
    while (i < left_size && j < right_size) {
        if (left_half[i] <= right_half[j]) {
            arr[k++] = left_half[i++];
        } else {
            arr[k++] = right_half[j++];
        }
    }
    
    // copy any remaining elements of left half to the original array
    while (i < left_size) {
        arr[k++] = left_half[i++];
    }
    
    // copy any remaining elements of right half to the original array
    while (j < right_size) {
        arr[k++] = right_half[j++];
    }
}

void merge_sort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    vector<int> arr = { 5, 4, 1, 3, 2 };
    merge_sort(arr, 0, arr.size() - 1);
    
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
