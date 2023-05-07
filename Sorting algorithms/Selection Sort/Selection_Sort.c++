#include<iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

// The `Select_sort` function is implementing the selection sort algorithm to sort an array of integers.
//  It takes two arguments: a pointer to an integer array `a` and an integer `n` representing the 
//  size of the array. The function iterates through the array and finds the minimum element in the 
//  unsorted portion of the array and swaps it with the first element of the unsorted portion. 
//  This process is repeated until the entire array is sorted in ascending order.

int Select_sort(int* a,int n){
for(int i=0;i<n-1;i++)
{
    int i_min =i;
    for(int j=i+1;j<n;j++)
    {
        if(a[j]<a[i_min])
        {
            i_min=j;
        }
    }
        int temp=a[i];
        a[i]=a[i_min];
        a[i_min]=temp;


}

return 0;
}

int main()
{
    int n=1000;
    while(n<5001)
    {
        cout<<n<<endl;
        int arr[n];
        for(int i=0;i<n;i++) arr[i]=n-i;
        auto start = high_resolution_clock::now();
        Select_sort(arr,n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "Time taken for selection sort: "<<duration.count() << endl;
        n=n+500;
    }

    return 0;
}
