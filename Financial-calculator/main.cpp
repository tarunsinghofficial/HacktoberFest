#include<iostream>
using namespace std;

int main ()
{
    //Declaring the required variables.
    int operations;
    int income;
    int expenses;
    int assets;
    int debts;
    int revenue;

    //Getting user input.
    cout<<"\t-----Financial Calculator----- \n"<<endl;
    cout<<"Available operations \n"<<endl;
    cout<<" 1.Cash Flow \n 2.Net Worth \n 3.Net Income"<<endl;
    cout<<"Choose one of the options (Enter the serial number of the operations)"<<endl;
    cin>>operations;

    //Performing the operations based on user input.
 switch(operations)
 {
     case 1:

         cout<<"Please enter your income (in $):"<<endl;
         cin>>income;
         cout<<"Please enter your expenses (in $):"<<endl;
         cin>>expenses;
        cout<<"Your cash flow is: $"<<income-expenses <<endl;
        break;

     case 2:
        cout<<"Please enter your assets (in $):"<<endl;
        cin>>assets;
        cout<<"Please enter your debts (in $):"<<endl;
        cin>>debts;
        cout<<"Your Net Worth is: $"<<assets-debts <<endl;
        break;

     case 3:
        cout<<"Please enter your revenue (in $):"<<endl;
        cin>>revenue;
        cout<<"Please enter your expenses (in $):"<<endl;
        cin>>expenses;
        cout<<"Your net income is: $"<<revenue-expenses <<endl;
        break;

     default:
        cout<<"Invalid operation"<<endl;
        break;
 }
 //Program returns zero.
    return 0;
}
//End of program.
