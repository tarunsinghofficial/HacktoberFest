//WAP TO FIND PEAK IN MOUNTAIN ARRAY

#include <iostream>
using namespace std;

int findpeakelement(int arr[], int size)
{
   int start = 0;
   int end = size - 1;
   int mid = start + (end - start) / 2;
   while (start < end)
   {
      if (arr[mid] < arr[mid + 1])
      {
         start = mid + 1;
      }
      else
      {
         end = mid;
      }
      mid = start + (end - start) / 2;
   }
   return start;
}

int main()
{
   int arr[9] = {24, 69, 78, 99, 79, 100, 67, 36, 26};
   cout << "peak element index :" << findpeakelement(arr, 9) << endl;
   return 0;
}
