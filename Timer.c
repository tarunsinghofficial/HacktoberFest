//TIMER//
#include<stdio.h>
#include<windows.h>
int main()
{
	int h,m,s;
	start:
	printf("\n Input the value in hour minute and seconds\n");
	scanf("%d%d%d",&h,&m,&s);
	if( h>24 || m>60 || s>60 )
	{
		system("cls");
		printf("Error wrong input");
		goto start;
	}
	while(1)
	{
		s--;
		if(s<0)
		{
			m--;
			s==59;
		}
		if(m<0)
		{
			h--;
			m=59;
		}
		if(h==0 && m==0 && s==0)
		{
			Beep(700,1000);
			exit(0);
		}
		printf("\n timer	:\n");
		printf("%02d:%02d:%02d",h,m,s);
		sleep(1);
		system("cls");
		
	}
	return(0);
}