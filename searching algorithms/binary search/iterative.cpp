int binarySearch(int arr[],int size,int num)
{
    int l = 0;
    int r = size - 1;
    while (l <= r) {
        int m = l + (r - l) / 2; 
        // Check if x is present at mid
        if (arr[m] == num) return m; 
        // If x greater, ignore left half
        if (arr[m] < num) l = m + 1; 
        // If x is smaller, ignore right half
        else r = m - 1;
    }
    // if we reach here, then element was not present
    return -1;
}