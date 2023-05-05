 int binarySearch(int arr[] , int num , int low , int high)//here high is size-1 and low is 0 initially
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