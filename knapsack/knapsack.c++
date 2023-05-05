//knapsack problem


#include <iostream>
#include <vector>
using namespace std;

void merge(double array[], int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto indexOfSubArrayOne
        = 0, 
        indexOfSubArrayTwo
        = 0; 
    int indexOfMergedArray
        = left; 
   
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
  

void mergeSort(double array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int reverseArray(double array[], int const begin, int const end){
    if(begin >= end){
        return 0;
    }
    else{
        int temp = array[begin];
        array[begin] = array[end];
        array[end] = temp;
        reverseArray(array, begin + 1, end - 1);
    }
}

 int binarySearch(double arr[] , int num , int low , int high)//here high is size-1 and low is 0 initially
    {
        if (low > high ) return -1;
        int mid = (high+low)/2;
      
        if (arr[mid] == num){
             return mid;
        }
      else if(mid == 0){
        if(arr[mid] == num) return 0;
        else return -1;
      }
        if (arr[mid] > num){
          return binarySearch(arr, num, low, mid - 1);
        } 
        return binarySearch(arr, num, mid + 1, high);
    }


int maxProfit(int maxWeight, double weight[], double profit[], int n){   
     int currentWeight = 0;
    int currentProfit = 0;
    int i = 0;

    double newprofit[5];
    for(int i=0;i<n;i++){
        newprofit[i] = profit[i];
    }

    mergeSort(newprofit, 0, 4);
    reverseArray(newprofit,0,4);
    
    for(int i=0;i<n;i++){
        cout<<newprofit[i]<<endl;
    }
    int x = binarySearch(profit, 7, 0, 4);
        cout<<"x: "<<x<<endl;
    while(currentWeight <= maxWeight && i < n){
        cout<<"i: "<<i<<endl;
        currentProfit += newprofit[i];
        cout<<newprofit[i]<<endl;
        cout<<"CurrentProfit: "<<currentProfit<<endl;
        int x = binarySearch(profit, 7, 0, 4);
        cout<<"x: "<<x<<endl;
        currentWeight += weight[binarySearch(profit, newprofit[i], 0, 4)];
        cout<<"CurrentWeight:"<<currentWeight<<endl;
        i++;
        x=0;
    }
    return currentProfit;
}

// int LeastWeight(int maxWeight, double profit[],double weight[],int n){
//     int currentWeight = 0;
//     int currentProfit = 0;
//     mergeSort(weight, 0,4);
//     int i = 0;
//     while(maxWeight > 0 && i < n){
//         if(weight[i] <= maxWeight){
//             currentWeight += weight[i];
//             currentProfit += profit[i];
//             maxWeight -= weight[i];
//         }
//         else{
//             currentWeight += maxWeight;
//             currentProfit += profit[i] * (maxWeight / weight[i]);
//             maxWeight = 0;
//         }
//         i++;
//     }
//     return currentWeight;

// }

int main(){
   double profit[5] = {10, 5, 15, 7, 6};
   double weight[5] = {2, 9, 5, 7, 1};

   double ppw[5];
   for(int i = 0; i < 5; i++){
       ppw[i] = profit[i] / weight[i];
    }
    // for(int j=0;j<5;j++){
    //     cout << ppw[j] << endl;
    // }

    // mergeSort(ppw, 0, 4);

    int maxWeight = 15;
    int profitmade =  maxProfit(maxWeight, weight, profit, 5);
    cout<<"Profit:"<<profitmade<<endl;
   

    // for(int j=0;j<5;j++){
    //     cout << ppw[j] << endl;
    // }

   

   

    // cout << "Max profit: " << currentProfit << endl;


    return 0;
}
