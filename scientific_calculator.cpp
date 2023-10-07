#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
#include<windows.h>
#define PI 3.14159265
using namespace std;
int main()
{
	double ch, a, b = 0;
	double result = 1;
	system("COLOR DE");
	while(ch != 17)
	{
		cout<< "1. Addition       2. Subtraction       3. Multiplication       4. Division\n5. Square root       6. Cube Root       7. x^2         8. x^3\n9. x^y         10. x!         11. e^x         12. log(x)\n13. ln(x)         14. sin(x)        15. cos(x)        16. tan(x)\n17. arctan(x)       18. arccos(x)       19. arcsin(x)       20. Exit\n\nEnter your choice: ";
		cin>> ch;
		if(ch > 20 || ch < 1 || ch != (double) ch)
		{
			cout<< "Wrong Input!\n";
			cin.clear();
			break;
		}
		if(ch == 1)
		{
			cout<< "Enter 1st Number: ";
			cin>> a;
			cout<< "Enter 2nd Number: ";
			cin>> b;
			if (a != (double) a || b != (double) b)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			cout<< "\n"<< a<< " + "<< b<< " = "<< a+b<< endl;
			a = 0;
			b = 0;
		}
		else if(ch == 2)
		{
			cout<< "Enter 1st Number: ";
			cin>> a;
			cout<< "Enter 2nd Number: ";
			cin>> b;
			if (a != (double) a || b != (double) b)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			cout<< "\n"<< a<< " - "<< b<< " = "<< a-b<< endl;
			a = 0;
			b = 0;
		}
		else if(ch == 3)
		{
			cout<< "Enter 1st Number: ";
			cin>> a;
			cout<< "Enter 2nd Number: ";
			cin>> b;
			if (a != (double) a || b != (double) b)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			cout<< "\n"<< a<< " * "<< b<< " = "<< a*b<< endl;
			a = 0;
			b = 0;
		}
		else if(ch == 4)
		{
			cout<< "Enter 1st Number: ";
			cin>> a;
			cout<< "Enter 2nd Number: ";
			cin>> b;
			if (a != (double) a || b != (double) b)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			cout<< "\n"<< a<< " / "<< b<< " = "<< (double)a/b<< endl;
			a = 0;
			b = 0;
		}
		else if(ch == 5)
		{
			cout<< "Enter Number: ";
			cin>> a;
			if (a != (double) a)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			cout<< "Square Root of "<< a<< " = "<< sqrt(a)<< endl;
			a = 0;
		}
		else if(ch == 6)
		{
			cout<< "Enter Number: ";
			cin>> a;
			if (a != (double) a)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			cout<< "Cube Root of "<< a<< " = "<< cbrt(a)<< endl;
			a = 0;
		}
		else if(ch == 7)
		{
			cout<< "Enter Number: ";
			cin>> a;
			if (a != (double) a)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			cout<< a<< "^2 = "<< pow(a, 2)<< endl;
			a = 0;
		}
		else if(ch == 8)
		{
			cout<< "Enter Number: ";
			cin>> a;
			if (a != (double) a)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			cout<< a<< "^3 = "<< pow(a, 3)<< endl;
			a = 0;
		}
		else if(ch == 9)
		{
			cout<< "Enter Number (x): ";
			cin>> a;
			cout<< "Enter Number (y): ";
			cin>> b;
			if (a != (double) a || b != (double) b)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			cout<< a<< "^"<< b<< " = "<< pow(a, b)<< endl;
			a = 0;
			b = 0;
		}
		else if(ch == 10)
		{
			cout<< "Enter Number: ";
			cin>> a;
			if (a != (double) a)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			for(int i=1; i<=a; i++)
			{
				result *= i;
			}
			cout<< a<<"! = "<< result<< endl;
			a = 0;
			result = 1;
		}
		else if(ch == 11)
		{
			cout<< "Enter Number: ";
			cin>> a;
			if (a != (double) a)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			cout<< "e^"<< a<< " = "<< exp(a)<< endl;
			a = 0;
		}
		else if(ch == 12)
		{
			cout<< "Enter Number: ";
			cin>> a;
			if (a != (double) a)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			cout<< "log("<< a<< ") = "<< log10(a)<< endl;
			a = 0;
		}
		else if(ch == 13)
		{
			cout<< "Enter Number: ";
			cin>> a;
			if (a != (double) a)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			cout<< "ln("<< a<< ") = "<< log(a)<< endl;
			a = 0;
		}
		else if(ch == 14)
		{
			cout<< "Enter Number (in Degrees): ";
			cin>> a;
			if (a != (double) a)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			b = a;
			a = (double) (a * PI) / 180;
			cout<< "sin("<< b<< ") = "<< sin(a)<< endl;
			a,b = 0;
		}
		else if(ch == 15)
		{
			cout<< "Enter Number (in Degrees): ";
			cin>> a;
			if (a != (double) a)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			b = a;
			a = (double) (a * PI) / 180;
			cout<< "cos("<< b<< ") = "<< cos(a)<< endl;
			a,b = 0;
		}
		else if(ch == 16)
		{
			cout<< "Enter Number (in Degrees): ";
			cin>> a;
			if (a != (double) a)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			b = a;
			a = (double) (a * PI)/180;
			cout<< "tan("<< b<< ") = "<< tan(a)<< endl;
			a,b = 0;
		}
		else if(ch == 17)
		{
			cout<< "Enter Number (in Degrees): ";
			cin>> a;
			if (a != (double) a)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			b = a;
			a = (double) (a * PI)/180;
			cout<< "arctan("<< b<< ") = "<< atan(a)<< endl;
			a,b = 0;
		}
		else if(ch == 18)
		{
			cout<< "Enter Number (in Degrees): ";
			cin>> a;
			if (a != (double) a)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			b = a;
			a = (double) (a * PI) / 180;
			cout<< "arccos("<< b<< ") = "<< acos(a)<< endl;
			a,b = 0;
		}
		else if(ch == 19)
		{
			cout<< "Enter Number (in Degrees): ";
			cin>> a;
			if (a != (double) a)
			{
				cout<< "Wrong Input!\n";
				cin.clear();
				break;
			}
			b = a;
			a = (double) (a * PI) / 180;
			cout<< "arcsin("<< b<< ") = "<< asin(a)<< endl;
			a,b = 0;
		}
		else if(ch == 20)
		{
			break;
		}
		cout<< endl;
	}
	if(ch == 20)
	{
		cout<< "Exiting...\n";
		Sleep(1500);
	}
	system("pause");
	return 0;
}
