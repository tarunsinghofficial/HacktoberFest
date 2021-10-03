// https://practice.geeksforgeeks.org/problems/peak-element/1

int peakElement(int arr[], int n)
{
   // Your code here
   int low = 0;
   int high = n-1;
   
   while(low<=high){
       int mid = (low+high)/2;
       
       if(
          (mid==0 || arr[mid]>=arr[mid-1]) &&
          (mid == n-1 || arr[mid]>=arr[mid+1])
         ){
             return mid;
         }
        else if(arr[mid]<=arr[mid+1]){
            low = mid+1;
        }else{
            high = mid-1;
        }
   }
   
   return -1;
}
