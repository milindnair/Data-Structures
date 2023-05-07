#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function to sort the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = (low - 1); // Index of smaller element
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


// -----------------------------------------------------------------------

// for randomised partition use this function:

        /* This function takes last element as pivot, places
        the pivot element at its correct position in sorted
        array, and places all smaller (smaller than pivot)
        to left of pivot and all greater elements to right
        of pivot */
        // int partition(int arr[], int low, int high) {
        //     int pivotIndex = low + rand() % (high - low + 1);
        //     int pivot = arr[pivotIndex];
        //     int i = low - 1;

        //     for (int j = low; j < high; j++) {
        //         if (arr[j] < pivot) {
        //             i++;
        //             swap(&arr[i], &arr[j]);
        //         }
        //     }
        //     swap(&arr[i + 1], &arr[pivotIndex]);
        //     return i + 1;
        // }

// -----------------------------------------------------------------------


// QuickSort function to implement the algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Main function to test the code
int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
