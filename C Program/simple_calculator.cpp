#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int num1,num2;
	char Operator;
	cout<<"Enter First Integer: ";
	cin>>num1;
	cout<<"Enter Second Integer: ";
	cin>>num2;
	cout<<"Enter Operator: ";
	cin>>Operator;
	
	if (Operator=='+')
	cout<<num1<<" "<<Operator<<" "<<num2<<" = "<<num1+num2;
	else if (Operator=='-')
	cout<<num1<<" "<<Operator<<" "<<num2<<" = "<<num1-num2;
	else if (Operator=='*')
	cout<<num1<<" "<<Operator<<" "<<num2<<" = "<<num1*num2;
	else if (Operator=='/')
	{ if (num2==0)
	   cout<<"Denominator should not be zero";
      else 
	cout<<num1<<" "<<Operator<<" "<<num2<<" = "<<num1/num2;
    }
	else if (Operator=='%')
	cout<<num1<<" "<<Operator<<" "<<num2<<" = "<<num1%num2;
	else if (Operator=='&&')
	cout<<num1<<" "<<Operator<<" "<<num2<<" = "<<num1&&num2;
	else if (Operator=='||')
	cout<<num1<<" "<<Operator<<" "<<num2<<" = "<<num1||num2;
	return 0;
}
