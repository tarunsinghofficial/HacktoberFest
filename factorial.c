#include <stdio.h>
int main()
{
  int n,pdt=1;
  printf("enter the number");
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    {
      pdt=pdt*i;
    }
  printf("The factorial value is %d",pdt);
  return 0;
}
