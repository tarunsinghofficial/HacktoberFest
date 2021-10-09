#include<stdio.h>
main(){
    int num = 5;
    int temp = num;
    for (int i=1; i<num-1; i++){

        for (int j=num; j>=temp; j--){
            printf("%2d", j);
        }
        temp--;
    printf("\n");
}}
