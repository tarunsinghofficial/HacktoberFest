#include <iostream>
#include <iomanip>
using namespace std;

int add(int n1, int n2){
	int add;
	add = n1+n2;
	return add;
}

int sub(int n1, int n2){
	int sub;
	sub = n1-n2;
	return sub;	
}

int mul(int n1, int n2){
	int mul;
	mul = n1*n2;
	return mul;
}

int divide(int n1, int n2){
	int divide;
	divide = n1/n2;
	return divide;
}


int main(){
	cout<<"  "<<"Menu"<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<"+ Addition"<<endl<<"- Subtraction"<<endl<<"* Multiplication"<<endl<<"/ Divide"<<endl;
	
	cout<<"----------------------------------"<<endl;
	int num1,num2; 
	char optr;
	cout<<"Enter 1st Number = ";
	cin >> num1;
	cout<<endl;
	cout<<"Enter 2nd Number = ";
	cin >> num2;
	cout<<endl;
	cout<<"Enter the Operator = ";
	cin>>optr;
	cout<<"----------------------------------"<<endl;
	
	switch(optr){
		case '+':
		cout<<num1<<" + "<<num2<<" = "<<add(num1,num2)<<endl;
		cout<<"Thanks for using the calculator!!"<<endl;
		break;
		
		case '-':
		cout<<num1<<" - "<<num2<<" = "<<sub(num1,num2)<<endl;
		cout<<"Thanks for using the calculator!!"<<endl;
		break;
		case '*':
		cout<<num1<<" * "<<num2<<" = "<<mul(num1,num2)<<endl;
		cout<<"Thanks for using the calculator!!"<<endl;
		break;
		case '/':
		cout<<num1<<" / "<<num2<<" = "<<divide(num1,num2)<<endl;
		cout<<"Thanks for using the calculator!!"<<endl;
		break;
		default:
		cout<<"Please enter the correct operator for calculation!!"<<endl;
}
	


	
return 0;
} 