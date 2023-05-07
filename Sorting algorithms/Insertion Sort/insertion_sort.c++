#include<iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;


int sort(int* a,int n)
{
    for(int i=0;i<n;i++)
    {
    int x = a[i];
    int j = i - 1;


    while (x < a[j] && j >= 0) {
      a[j + 1] = a[j];
      --j;
    }
    a[j + 1] = x;
    }
    return 0;
}

int main()
{
int n=1000;
 while(n<5001)
    {cout<<n<<endl;
    int arr[n];
    for(int i=0;i<n;i++)
        arr[i]=n-i;
    auto start = high_resolution_clock::now();
    sort(arr,n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "time taken for insertion sort "<<duration.count() << endl;
    n=n+500;
    }


    return 0;
}
