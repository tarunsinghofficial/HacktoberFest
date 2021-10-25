// A basic calandar program by sahana

#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include <conio.h>

struct Date{
  int dd;
  int mm;
  int yy;  
};
struct Date date; // it's a global datatype date

COORD xy = {0,0};//x and y co ordinates
//setting  the cursor
void gotoxy(int,int);

//check for a leap year
int LeapYear(int);
//to count for the month
void countMonth(int*,int*);

void reduceMonth(int*,int*);

int NumberOfDays(int,int);

char *getName(int);
//print the name of the month and year 

void print_date(int,int);
//to get a day when given it's number

int getDayNumber(int, int ,int);

char *getDay(int, int,int);

void printMonth(int, int, int, int);

int main()
{
    system("title Wizard");
    system("color bc");//color help
    int choice;
    char ch;
    while(1)
    {
        system("color bc");
        ch = 'a';
        system("cls");//to clear the screen on cmd like text related to color
        printf("1.Find out the day\n");
        printf("2.Print  all the day of the months\n");
        printf("3.Exit\n");
        printf("enter your choice \n");
        scanf("%d",&choice);
        system("cls");
        switch(choice)
        {
            case 1: system("color 5f");
                   printf("Enter the date (DD MM YYYY): ");
                   scanf("%d %d  %d",&date.dd,&date.mm,&date.yy);
                   system("cls"); //becoz it's CLI application that we are building so will use cls after ip
                   printf("Day is :%s",getDay(date.dd, date.mm, date.yy));
                   printf("\n Press any key to continue....");
                   getch();
                   break;
           case 2 :system("color 9f");
                   printf("Enter month and year (MM YYYY): ");
                   scanf("%d %d ",&date.mm,&date.yy);
                   system("cls");
                   while(ch != 'q'){
                       printMonth(date.mm,date.yy, 20, 5);
                       ch =getch();
                       if(ch=='n'){
                           countMonth(&date.mm, &date.yy);
                           system("cls");
                           printMonth(date.mm,date.yy,20,5);
                       }
                       else if(ch == 'p'){
                           reduceMonth(&date.mm, &date.yy);
                           system("cls");
                           printMonth(date.mm,date.yy,20,5);
                       }
                   } 
                     break;
          case 3:system("color 07");
                   exit(0);
        }
    }
    return 0;
}
//Setting the cursor
void gotoxy(int x, int y)  //X and Y coordinates
{
    xy.X = x;
    xy.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),  xy);
}

//Checking for a leap year
int LeapYear(int year)
{
    if(year%400 == 0 || (year%100!=0 && year%4 == 0))
        return 1;
    return 0;
}

//Increasing month number
void countMonth(int *mm, int *yy)
{
    ++*mm;
    if(*mm > 12)
    {
        ++*yy;
        *mm = *mm-12;
    }
}

//Decreasing month number
void reduceMonth(int *mm, int *yy)
{
    --*mm;
    if(*mm < 1)
    {
        --*yy;
        *mm = *mm+12;
    }
}

//Number of days in a month
int NumberOfDays(int month, int year)
{
    switch(month)
    {
        case 1: return(31);
        case 2: if(LeapYear(year)==1)
                    return(29);
                else
                    return(28);
        case 3: return(31);
        case 4: return(30);
        case 5: return(31);
        case 6: return(30);
        case 7: return(31);
        case 8: return(31);
        case 9: return(30);
        case 10: return(31);
        case 11: return(30);
        case 12: return(31);
        default: return(-1); 
    }
}

//Name of the day based on number
char *getName(int day)
{
    switch(day)
    {
        case 0: return("Sunday\t");
        case 1: return("Monday\t");
        case 2: return("Tuesday\t");
        case 3:return("Wednesday\t");
        case 4: return("Thursday\t");
        case 5: return("Friday\t");
        case 6: return("Saturday\t");
        default: return("Error in get name\t");
    }
}

//Printing name of month and year
void print_date(int mm, int yy)
{
    printf("++++++++++++++++++++++++\n");
    gotoxy(25, 6);
    switch (mm)
    {
    case 1: printf("Jan");
        break;
    case 2: printf("Feb");
        break;
    case 3: printf("Mar");
        break;
    case 4: printf("Apr");
        break;
    case 5: printf("May");
        break;
    case 6: printf("Jun");
        break;
    case 7: printf("Jul");
        break;
    case 8: printf("Aug");
        break;
    case 9: printf("Sep");
        break;
    case 10: printf("Oct");
        break;
    case 11: printf("Nov");
        break;
    case 12: printf("Dec");
        break;
    
    default: printf("Error getting name\t");
        break;
    }
    printf(" ,%d", yy);
    gotoxy(20, 7);
    printf("-------------------------\n");
}

//getting day number
int getDayNumber(int day, int mon, int year)
{
    int res = 0, t1, t2, y=year;
    year = year - 1600;
    while(year >= 100)
    {
        res = res+5;
        year = year-100;
    }
    res = (res%7);
    t1 = ((year-1)/4);
    t2 = (year-1)-t1;
    t1 = (t1*2)+t2;
    t1 = t1%7;
    res = res+t1;
    res = res%7;
    t2=0;
    for(t1 = 1;t1<mon;t1++)
    {
        t2 += NumberOfDays(t1, y);
    }

    t2 = t2+day;
    t2 = t2%7;
    res = res+t2;
    res = res%7;

    if(y > 2000)
        res += 1;
    res = res%7;
    return res;
}  

//Get day func
char *getDay(int dd,int mm,int yy){
    int day;
    if(!(mm>=1 && mm<=12)){
        return("Invalid month value");
    }
    if(!(dd>=1 && dd<=NumberOfDays(mm,yy))){
        return("Invalid date");
    }
    if(yy>=1600){
        day = getDayNumber(dd,mm,yy);
        day = day%7;
        return(getName(day));
    }
}

//prints the month with all days
void printMonth(int mon,int year,int x,int y){
    system("color 9f");
    int nod, day, cnt, d = 1, x1 = x, y1 = y;
    if(!(mon>=1 && mon<=12)){
        printf("INVALID MONTH");
        getchar();
        return;
    }
    if(!(year>=1600)){
        printf("INVALID YEAR");
        getchar();
        return;
    }
    gotoxy(20,y);
    print_date(mon,year);
    y += 3;
    gotoxy(x,y);
    printf("S   M   T   W   T   F   S   ");
    y++;
    nod = NumberOfDays(mon,year);
    day = getDayNumber(d,mon,year);
    switch(day){ //locates the starting day in calender
        case 0 :
            x=x;
            cnt=1;
            break;
        case 1 :
            x=x+4;
            cnt=2;
            break;
        case 2 :
            x=x+8;
            cnt=3;
            break;
        case 3 :
            x=x+12;
            cnt=4;
            break;
        case 4 :
            x=x+16;
            cnt=5;
            break;
        case 5 :
            x=x+20;
            cnt=6;
            break;
        case 6 :
            x=x+24;
            cnt=7;
            break;
        default :
            printf("INVALID DATA FROM THE getOddNumber()MODULE");
            return;
    }
    gotoxy(x,y);

    printf("%02d",d);
    for(d=2;d<=nod;d++){
        if(cnt%7==0){
            y++;
            cnt=0;
            x=x1-4;
        }
        x = x+4;
        cnt++;
        gotoxy(x,y);
        printf("%02d",d);
    }
    gotoxy(8, y+2);
    printf("Press 'n'  to Next, Press 'p' to Previous and 'q' to Quit");
}