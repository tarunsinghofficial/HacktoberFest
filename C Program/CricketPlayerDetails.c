#include<stdio.h>
struct cricketer
{
    int runs,wickets;
    char name[25];
}player[100],t;
 
void main()
{
    int i,j,n;
    printf("Enter the no of cricket players\n");
    scanf("%d",&n);
    printf("Enter player info as name , wickets taken , runs scored\n");
    for(i=0;i<n;i++)
    {
        scanf("%s %d %d",player[i].name,&player[i].wickets,&player[i].runs);
    }
    
        
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(player[j].runs>player[j+1].runs)
            {
                t=player[j];
                player[j]=player[j+1];
                player[j+1]=t;
            }
        }
    }
    
    printf("\nCricketer info in terms of runs scored from lowest to highest\n");
    printf("\nNAME\t\tWICKETS\t\t\tRUNS_SCORED\n");
    printf("-------------------------------------------------------------------------------\n");
 
    for(i=0;i<n;i++)
    {
        printf("%s\t\t\t%d\t\t\t%d\n",player[i].name,player[i].wickets,player[i].runs);
    }
}
