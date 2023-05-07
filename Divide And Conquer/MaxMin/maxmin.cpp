#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;
int arr[] = {12, 2, 5, 9, 6, 3, 10};
void maxmin(int arr[], int i, int j, int &max_value, int &min_value) {
    int mid;
 
    if (i == j) {
     
        max_value = arr[i];
        min_value = arr[j];
     
    } else if (i  == j-1) {
     
        if (arr[i] > arr[j]) {
            max_value = arr[i];
            min_value = arr[j];
        } else {
            max_value = arr[j];
            min_value = arr[i];
        }
    } else {
        mid = (i + j) / 2;
     
        int max1, min1, max2, min2;
        maxmin(arr, i, mid, max1, min1);
        maxmin(arr, mid + 1, j, max2, min2);
        max_value = max(max1, max2);
        min_value = min(min1, min2);
    }
}


int main() {
   
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_value, min_value;
  auto start = high_resolution_clock::now();
    maxmin(arr, 0, n - 1, max_value, min_value);
   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<nanoseconds>(stop - start);
    cout <<   max_value << endl;
    cout <<  min_value << endl;
     cout << "time count: "<<duration.count() <<endl;
    return 0;
}
