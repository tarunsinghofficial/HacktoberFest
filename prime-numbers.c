#include <stdio.h>

int main()
{
  int i, Number, count;

  printf("Prime Number from 1 to 300 are: \n");
  for(Number = 1; Number <= 300; Number++)
   {
      count = 0;
        for (i = 2; i <= Number/2; i++)
        {
  	        if(Number%i == 0)
  	        {
     	        count++;
  	            break;
	        }
        }
        if(count == 0 && Number != 1 )
        {
	        printf("\n%d\n ", Number);
        }
    }
    return 0;
}
