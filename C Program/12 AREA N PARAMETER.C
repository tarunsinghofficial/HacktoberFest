// WAP TO PRINT AREA AND PARAMETER OF CIRCLE,TRAINGLE,SQUARE..

#include<stdio.h>
int main()
{   
    // for Circle

    int r,areac,parameterc;  // r for radius
    printf("Enter Radius Of Circle");
    scanf("%d",&r);
    areac=3.14*r*r;
    parameterc=2*3.14*r;
    printf("Area Of Circle is %d \n",areac); 
    printf("Parameter Of Circle is %d",parameterc);

    // for Traingle

    int b,h,thirdside,areat,parametert; // b for base,h for height
    printf("\n Enter Base & Height & Third Side Of Traingle");
    scanf("%d %d %d",&b,&h,&thirdside);
    areat=0.5*b*h;
    parametert=b+h+thirdside;
    printf("Area of Traingle is %d\n",areat);
    printf("Parameter Of Traingle is %d",parametert);

    // for Sqaure

    int s,areas,parameters; // s for side
    printf("\n Enter Side Of Square");
    scanf("%d",&s);
    areas=s*s;
    parameters=4*s;
    printf("Area Of Square is %d\n",areas);
    printf("Parameter Of Square is %d",parameters);

    return 0;
}