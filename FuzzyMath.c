#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

/*<----- FUNCTION DECLARATIONS ------>*/

void trig();            
void arith();
void other();
void timeout();

/*<----- FUNCTION DECLARATIONS ------>*/

/*<----- PLEASE NOTE ------>*/



//The system() function works only in Windows, make sure you're on a Windows system.
//The system() function is responsible for clearing and pausing (for user input).


/*<----- PLEASE NOTE ------>*/

void main() 
{
    system("clear");
    int quit = 0;
    int ch; char swallow;
    while(!quit)    // Infinite loop that terminates only when condition is met
    {
    printf("Choose :\n1.Fuzzy Arithmetic\n2.Trigonometric Functions\n3.Other functions\n4.Exit\nEnter your choice: ");
    scanf("%d", &ch);
    system("clear");
    if(ch<1 || ch>4)
    {
                printf("Invalid Input!\n");
                scanf("%c",&swallow);
                continue; 
    }
    ch = ch +'0';
    if (ch < '1'|| '4' < ch ) 
    { 
                printf("Invalid Input!\n");
                scanf("%c",&swallow);
                continue;
    }
    switch(ch)
    {
            case '1':
             
            arith();
            timeout();
            break;

            case '2':
          
            trig();
            timeout();
            break;

            case '3':
          
            other();
            timeout();
            break;

            case '4':
            printf("Thank You!");
            quit = 1;
            break;  //Loop terminates
    }
    }
        
}  

void arith()
{
    //function 1
    int n1;
    printf("Enter number of elements for set A\n");
    scanf("%d", &n1);
    int i;
    float x1[n1], mx1[n1];
    printf("Enter the x values of set A\n");
    for(i=0;i<n1;i++)
    {
        scanf(" %f",&x1[i]);
    }
    printf("Enter membership grades for set A\n");
    for(i=0;i<n1;i++)
    {
        scanf(" %f",&mx1[i]);
    }
    
    //function 2
    int n2;
    printf("Enter number of elements for set B\n");
    scanf("%d", &n2);
    int j;
    float x2[n2], mx2[n2]; 
    printf("Enter the x values of set B\n");
    for(j=0;j<n2;j++)
    {
        scanf(" %f",&x2[j]);
    }
    printf("Enter membership grades for set B\n");
    for(j=0;j<n2;j++)
    {
        scanf(" %f",&mx2[j]);
    }
    
    printf("Select operation\n");
    printf("a - Addition\n");
    printf("b - Subtraction\n");
    printf("c - Multiplication\n");
    printf("d - Division\n");
    char sel;
    struct Result{
       float result; //to store end result values after operation
       float mxresult; //to store corresponding mx values
       bool valid; //a variable to eliminate copies
    } resultant [n1*n2];
    //making an array of this structure. at each index, one result of operation and a valid field is stored
    
    for(int r=0;r<n1*n2;r++){
        resultant[r].valid=true; //set all valid to true 
    }
    
    scanf(" %c", &sel);
    
    switch(sel)
    {
        case 'a':
        {
            for(i=0;i<n1;i++)//Addition
            {
                for(j=0;j<n2;j++)
                {   
                    resultant[n1*i+j].result=x1[i]+x2[j];
                    if(mx1[i]>=mx2[j])
                    resultant[n1*i+j].mxresult=mx2[j];
                    else
                    resultant[n1*i+j].mxresult=mx1[i];
                    
                }
            }
          // //the set of y values and corresponding mx values is formed
            break;
        } 
        case 'b':
        {
            for(i=0;i<n1;i++)//Subtraction
            {
                for(j=0;j<n2;j++)
                {
                    resultant[n1*i+j].result=x1[i]-x2[j];
                    if(mx1[i]>=mx2[j])
                    resultant[n1*i+j].mxresult=mx2[j];
                    else
                    resultant[n1*i+j].mxresult=mx1[i];
                }
            }
          // //the set of y values and corresponding mx values is formed
     break;
        }
        case 'c':
        {
            for(i=0;i<n1;i++)//Multiplication
            {
                for(j=0;j<n2;j++)
                {
                    resultant[n1*i+j].result=x1[i]*x2[j];
                    if(mx1[i]>=mx2[j])
                    resultant[n1*i+j].mxresult=mx2[j];
                    else
                    resultant[n1*i+j].mxresult=mx1[i];
                }
            }

              //now all copies will have valid set to false and the first occurrence of every y value will have the largest value (and valid = true)
              break;
        }
        case 'd':
        {
            for(i=0;i<n1;i++)//Division
            {
                for(j=0;j<n2;j++)
                {
                    resultant[n1*i+j].result=x1[i]/x2[j];
                    if(mx1[i]>=mx2[j])
                    resultant[n1*i+j].mxresult=mx2[j];
                    else
                    resultant[n1*i+j].mxresult=mx1[i];
                }
            }
              //now all copies will have valid set to false and the first occurrence of every y value will have the largest value (and valid = true)
        break;
        }
        default: printf("Invalid input\n");
        
    }
    // //the set of y values and corresponding mx values is formed
    // //we will now find copies of y values and assign them with valid==false while simulatneously assigning the largest mx value to the first y
    for(i=1;i<n1*n2;i++)
    {
        for(j=0;j<i;j++)
        {   //perform a linear search up until every element, scanning for copies
            if(resultant[j].result == resultant[i].result)
            {
                //copy found
                //compare mx values
                //if mx at current position is greater than the mx that has occured before, we need to assign this mx
                //to "eliminate" the copy, we set its valid to false
                if(resultant[i].mxresult > resultant[j].mxresult) 
              { resultant[j].mxresult=resultant[i].mxresult;
                 resultant[j].valid = false;
              }
              
                
            }
        }
    }
    for(i=0;i<n1*n2;i++)
     {
         if(resultant[i].valid)
         printf("%.2f ",resultant[i].result);
     }
     //loop to print y values
     printf("\n");
      for(i=0;i<n1*n2;i++)
     {
         if(resultant[i].valid)
         printf("%.2f ",resultant[i].mxresult);
     }
     //loop to print corresponding mxvalues
     
}

/*<------- ARITHMETIC FUNCTION ------>*/


/*<-------- TRIG FUNCTION -------->*/
void trig()
{
     printf("Input the number of elements of the fuzzy set\n");
    int n;
    scanf("%d", &n);
    printf("Input the x values\n");
    float x[n],mx[n];//input x values in x, m(x) values in mx
    struct result{
        float yvalue,mxvalue;
        bool valid;
    };
    struct result y[n];
    for(int i=0;i<n;i++)
    y[i].valid=true;
    //y stores y values in first row, corresponding m(x) values in second row
    int i,j;//counter-variables for loop
    
    for(i=0;i<n;i++){
        scanf("%f", &x[i]);
    }
    printf("Input the membership grades values\n");
      for(i=0;i<n;i++){
        scanf("%f", &mx[i]);
    }
    //Input for fuzzy set
    printf("a - sine\nb -cosine\nc - tan\nInput your choice\n");
    char op;
    scanf(" %c",&op);
    //Input user choice
    if (op=='a')
{
   for(i=0;i<n;i++)
    {
        y[i].yvalue = sin(x[i]);
        y[i].mxvalue = mx[i];
        //compute y value for each x
    }
    }

else if (op=='b')
    {
    for(i=0;i<n;i++)
    {
        y[i].yvalue = cos(x[i]);
        y[i].mxvalue = mx[i];
        //compute y value for each x
    }
    }
    else if (op=='c')
    {
    for(i=0;i<n;i++)
    {
        y[i].yvalue = tan(x[i]);
        y[i].mxvalue = mx[i];
    }   //compute y value for each x
    }
    else
    printf("Invalid option");

     for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(y[i].yvalue==y[j].yvalue)
            {   
                //copy found
                if(y[i].mxvalue<y[j].mxvalue)
                {
                    y[i].mxvalue=y[j].mxvalue;
                }
                //assign mx if greater
                y[j].valid=false;
            }
        }
    }
    //copy exclusion
    for(i=0;i<n;i++)
    {   
    if(y[i].valid)
    printf("%.2f ",y[i].yvalue);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
    if(y[i].valid)
    printf("%.2f ",y[i].mxvalue);
    }
     printf("\n");
    //print loop
}
/*<-------- TRIG FUNCTION -------->*/

/*<---- OTHER FUNCTION ------>*/
void other()
{
    printf("Input the number of elements of the fuzzy set\n");
    int n,a;
    scanf("%d", &n);
    printf("Input the x values\n");
    float x[n],mx[n];//input x values in x, m(x) values in mx
    struct result{
        float yvalue,mxvalue;
        bool valid;
    };
    struct result y[n];
    for(int i=0;i<n;i++)
    y[i].valid=true;
    //y stores y values in first row, corresponding m(x) values in second row
    int i,j;//counter-variables for loop
    
    for(i=0;i<n;i++){
        scanf("%f", &x[i]);
    }
    printf("Input the membership grades values\n");
      for(i=0;i<n;i++){
        scanf("%f", &mx[i]);
    }
    //Input for fuzzy set
    printf("a- Exponent\nb- Logarithmic\nInput your choice\n");
    char op;
    scanf(" %c",&op);
    //Input user choice
    if (op=='a')
{
    printf("Enter base value:\n");
    scanf("%d", &a);

    for(i=0;i<n;i++)
    {
        y[i].yvalue = pow(a, x[i]);
        y[i].mxvalue = mx[i];
        //compute y value for each x
    } 
}

else if (op=='b')
    {
    for(i=0;i<n;i++)
    {
        y[i].yvalue = log(x[i]);
        y[i].mxvalue = mx[i];
        //compute y value for each x
    }
    }
else
    printf("Invalid option");
    //if-else ladder for choice

    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(y[i].yvalue==y[j].yvalue)
            {   
                //copy found
                if(y[i].mxvalue<y[j].mxvalue)
                {
                    y[i].mxvalue=y[j].mxvalue;
                }
                //assign mx if greater
                y[j].valid=false;
            }
        }
    }
    //copy exclusion
    for(i=0;i<n;i++)
    {   
    if(y[i].valid)
    printf("%.2f ",y[i].yvalue);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
    if(y[i].valid)
    printf("%.2f ",y[i].mxvalue);
    }
     printf("\n");
    //print loop
    
}


/*<----- OTHER FUNCTION ------>*/


void timeout()
{
    char swallow;
    printf("\n");
    system("pause");
    scanf("%c", &swallow);
    system("clear");
}
/*<------- TIMEOUT FUNCTION -------->*/