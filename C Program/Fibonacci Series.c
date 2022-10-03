#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int f=0,s=1,sum;
    for(int i=1;i<=n;i++){
        printf("%d ",f);
        sum=f+s;
        f=s;
        s=sum;
    }
    return 0;
}
