#include <iostream>
#include <vector>

using namespace std;

void subsetSum(int arr[], int n, vector<int>& subset, int sum, int idx)
{
    if (sum == 0) {
        // Found a subset whose sum is equal to the given sum
        cout << "Subset found: ";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i] << " ";
        }
        cout << endl;
        return;
    }
    
    if (sum < 0 || idx == n) {
        // Exceeded the given sum or reached the end of the array
        return;
    }
    
    // Exclude the current element and move to the next element
    subsetSum(arr, n, subset, sum, idx+1);
    
    // Include the current element and move to the next element
    subset.push_back(arr[idx]);
    subsetSum(arr, n, subset, sum-arr[idx], idx+1);
    subset.pop_back();
}

int main()
{
    int n, sum;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the sum: ";
    cin >> sum;
    
    vector<int> subset;
    subsetSum(arr, n, subset, sum, 0);
    
    return 0;
}
