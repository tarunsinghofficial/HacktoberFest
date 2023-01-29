#include<stdio.h>
int main()
{
	int a,b,c=1,d;
	printf("Enter no.=");
	scanf("%d",&a);
	b=a;
	while(c<=10)
	{
		d=a*c;
		printf("%d X %d = %d\n",b,c,d);
		c++;
	}
	return 0;
}
