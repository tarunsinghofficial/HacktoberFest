#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int num1,num2;
	char Operator;
	cout<<"Enter 1st number: ";
	cin>>num1;
	cout<<"Enter 2nd number: ";
	cin>>num2;
	cout<<"Enter Operator: ";
	cin>>Operator;
	switch(Operator)
	{
		case '+':
			cout<<num1<<" "<<"+"<<" "<<num2<<" = "<<num1+num2;
			break;
		case '-':
			cout<<num1<<" "<<"-"<<" "<<num2<<" = "<<num1-num2;
			break;
	        case '*':
			cout<<num1<<" "<<"*"<<" "<<num2<<" = "<<num1*num2;
			break;
		case '/':
	                if(num2 == 0) cout<<"Error,Denominator is 0!";
			else
			cout<<num1<<" "<<"/"<<" "<<num2<<" = "<<num1/num2;
			break;
		case '%':
			cout<<num1<<" "<<"%"<<" "<<num2<<" = "<<num1%num2;
			break;
		default:
			cout<<"Invalid Operator,Please enter again!";
	}
	return 0;	
}
