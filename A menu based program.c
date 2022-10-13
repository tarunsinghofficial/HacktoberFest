/* A menu based program to perform the operation according to the 
choice of the user.*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
 char c;
 float r,pi,Area_circle,Circumference;
 int a,l,b,h,Volume,TSA,Area;
 do{
 printf(" 1. Volume of Cuboid \n 2. Total Surface Area of Cuboid \n 3. Area of Circle\n 4. Circumference of Circle\n 5. Exit\n");
 printf("Enter your choice=");
 scanf("%d",&a);
 switch(a)
 {
 case 1:
 printf("Enter length, breadth and height of cuboid=");
 scanf("%d%d%d",&l,&b,&h);
Volume= l*b*h;
 printf("The volume of cuboid=%d\n",Volume);
 break;
 case 2:
 printf("Enter length, breadth and height of cuboid=");
 scanf("%d%d%d",&l,&b,&h);
 TSA=2*(l*b+b*h+l*h);
 printf("The total surface area of cuboid=%d\n",TSA);
 break;
 case 3:
 printf("Enter radius of circle=");
 scanf("%f",&r);
 pi=3.14;
 Area_circle= pi*r*r;
 printf("The area of circle=%.2f \n",Area_circle);
 break;
 case 4:
 printf("Enter radius of circle=");
 scanf("%f",&r);
 pi=3.14;
 Circumference= 2*pi*r;
 printf("The circumference of Circle=%.2f\n",Circumference);
 break;
 case 5:
 exit(1);
 default:
 printf("Wrong Input \n");
 }
 printf("Do you want to continue? [Y/N]:");
 scanf(" %c",&c);
}while(c=='Y'|| c=='y');
return 0;
 getch();
 }

