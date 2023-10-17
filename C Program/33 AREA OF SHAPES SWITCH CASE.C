// WAP TO CALCULATE AREA OF CIRCLE,TRAINGLE,SQUARE USING SWITCH CASE

#include<stdio.h>
int main()
{
    int a,r,b,h,s,areac,areat,areas; // r for radius,b for base,h fot height,s for side
    printf("Press 1 for circle,Press 2 for Traingle,Press 3 for square");
    scanf("%d",&a);
    switch (a)
    {
        case 1: printf("Enter radius Of Circle");
                scanf("%d",&r);
                areac=3.14*r*r;
                printf("Area Of Circle Is %d",areac);
                break;
        case 2: printf("Enter Base and Height Of Traingle");
                scanf("%d %d",&b,&h);
                areat=0.5*b*h;
                printf("Area Of Traingle Is %d",areat);
                break;
        case 3: printf("Enter Side Of Sqaure");
                scanf("%d",&s);
                areas=s*s;
                printf("Area Of Square Is %d",areas);
                break;
        default:printf("Invalid Choice");
    }
}