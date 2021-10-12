#include<stdio.h>
#include<string.h>
int arr[10],bur[10],star[10],finish[10],tat[10],wt[10],i,j,n,pn[10];
void swap(int *a, int *b) //function to swap two values
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void main()
{
    int totwt=0,tottat=0;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    printf("\nEnter the ProcessName, Arrival Time & Burst Time:\n");
    for(i=0; i<n; i++) {
        printf("P");
        scanf("%d%d%d",&pn[i],&arr[i],&bur[i]);
    }
    // Sorts processes according to their arrival time
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(arr[i]>arr[j]) {
                swap(&arr[i],&arr[j]);
                swap(&bur[i],&bur[j]);
                swap(&pn[i],&pn[j]);
            }
        }
    }
    //Calculates completion,waiting,turnaround time from given data
    for(i=0;i<n;i++) {
        if(i==0)
            star[i]=arr[i];
        else
            star[i]=finish[i-1];
        wt[i]=star[i]-arr[i];
        finish[i]=star[i]+bur[i];
        tat[i]=finish[i]-arr[i];
    }
    //Resorts the processes according to their no
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(pn[i]>pn[j]) {
                swap(&arr[i],&arr[j]);
                swap(&bur[i],&bur[j]);
                swap(&pn[i],&pn[j]);
                swap(&wt[i],&wt[j]);
                swap(&tat[i],&tat[j]);
            }
        }
    }
    printf("\nProcess  Burst Time  Arrival Time  Waiting Time  Turnaround Time");
    for(i=0; i<n; i++) {
        printf("\n  P%d\t    %3d\t\t%3d\t      %3d\t     %3d",pn[i],bur[i],arr[i],wt[i],tat[i]);
        totwt+=wt[i];
        tottat+=tat[i];
    }
    printf("\n\nAverage Waiting time:%.3f",(float)totwt/n);
    printf("\nAverage Turn Around Time:%.3f\n\n",(float)tottat/n);
}