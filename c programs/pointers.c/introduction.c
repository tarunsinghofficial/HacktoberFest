#include<stdio.h>
#include<conio.h>
#include<stdint.h>
int main()
{
  char a = 'A';
  char *ptr = &a;
  
  printf(" 1 | %c,%c,%llu", a, *ptr, (uint64_t) ptr);

}
