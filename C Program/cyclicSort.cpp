/*#Cyclic sort in CPP
Pseudocode :

Begin
for
start:= 0 to n - 2 do
key := array[start]
location := start
for i:= start + 1 to n-1 do
  if array[i] < key then
     location: =location +1
done
if location = start then
    ignore lower part, go for next iteration
while key = array[location] do
   location = location
done
if location != start then
    swap array[location] with key
while location != start do
    location start


for i:= start + 1 to n-1 do
     if array[i] < key then
          location: =location +1
done
while key= array[location]
      location := location +1
 if key != array[location]
      Swap array[location] and key
   done
 done
End
-------------------------------------------------------------------------------------------------------------
Code:*/



#include <iostream>
using namespace std;
 
void cyclicSort(int arr[], int n){
  int i = 0;
  while(i < n)
  {
    // as array is of 1 based indexing so the
    // correct position or index number of each
    // element is element-1 i.e. 1 will be at 0th
    // index similarly 2 correct index will 1 so
    // on...
    int correct = arr[i] - 1 ;
    if(arr[i] != arr[correct]){
 
      // if array element should be lesser than
      // size and array element should not be at
      // its correct position then only swap with
      // its correct position or index value
      swap(arr[i], arr[correct]) ;
    }else{
 
      // if element is at its correct position
      // just increment i and check for remaining
      // array elements
      i++ ;
    }
  }
 
}
 
void printArray(int arr[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}
 
int main() {
 
  int arr[] = { 3, 2, 4, 5, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout<< "Before sorting array: \n";
  printArray(arr, n);
  cyclicSort(arr, n);
  cout << "Sorted array: \n";

  printArray(arr, n);
  return 0;
 
}
/*Time Complexity Analysis: 

Worst Case: O(n2) 
Average Case: O(n2) 
Best Case: O(n2)
Auxiliary Space: O(1)
*/

