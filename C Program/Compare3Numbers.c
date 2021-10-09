#include<stdio.h>
main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);

    if (a>b){
        if (b>c){
            printf("Greater is %d",a);
        }else{
            printf("Greater is %d",c);
        }
    }else if(b>a){
        if (a>c){
            printf("Greater is %d",b);
        }else{
            printf("Greater is %d",c);
        }
    }
}
