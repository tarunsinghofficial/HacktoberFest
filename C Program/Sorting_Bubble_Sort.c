#include <stdio.h>

int main()
{
int total_count, counter, counter1, swap_var;
int array[20];
  
printf("How many number you want to input?\n");
scanf("%d", &total_count);
  
printf("Please enter %d integers that has to be sorted\n", total_count);
  for (counter = 0; counter < total_count; counter++)
  scanf("%d", &array[counter]);
  
  for (counter = 0 ; counter < total_count - 1; counter++)
  {
  for (counter1 = 0 ; counter1 < total_count - counter - 1; counter1++)
  {
  if (array[counter1] > array[counter1+1]) /* For decreasing order use < */
  {
  swap_var        = array[counter1];
  array[counter1]   = array[counter1+1];
  array[counter1+1] = swap_var;
  }
  }
  }
  printf("Below is the list of elements sorted in ascending order:\n");
  for (counter = 0; counter < total_count; counter++)
  printf("%d\n", array[counter]);
  return 0;
}
