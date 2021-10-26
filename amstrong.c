#include <stdio.h>
int Armstrong(int number) {
  int sum = 0, rem;
  while (number != 0) {
    remainder = number % 10;
    sum = sum + (rem * rem* rem);
    number = number / 10;
  }
  return sum;
}
int main() { 
   int number, sum = 0;
  printf("\nEnter a number:");
  scanf("%d", &number);
  sum = Armstrong(number);

  if (number == sum) {
    printf("\n%d is an Armstrong Number", number);
  } else {
    printf("\n%d is not an Armstrong Number", number);
  }
  return (0);
}