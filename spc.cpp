#include<iostream>
using namespace std;

int parityassignment(int sum, int oddoreven)
{
    if(sum % 2 == 0)
    {
        if(oddoreven)
        {
           return 1; 
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if(oddoreven)
        {
           return 0; 
        }
        else
        {
            return 1;
        }
    }
}
int paritycheck(int arr[],int n,int oddoreven)
{
    int sum=0;
    for(int i = 0; i<n;i++)
    {
        sum = sum + arr[i];
    }
    sum = sum%2;
    if(oddoreven) // odd parity =1 (1 0)
    {
        if(sum==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else    // even parity =0 (0 0)
    {
        if(sum==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
int main(){
    int n;
    cout << "Enter length of data: " ;

    cin >> n;
    int arr[n+1];
    int sum;
    sum = 0;
    cout << "Enter data bits seperated by new line"<<endl;
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
        if((arr[i] != 1) && (arr[i] !=0))
        {
            cout<< "Error: Enter data in binary form." << endl;
            return 0;
        }
        sum = sum + arr[i];
    } 

    cout << "Enter 0 for even parity or 1 for odd parity" << endl; 
    
    int oddoreven;

    cin >> oddoreven;
    if((oddoreven != 1) && (oddoreven !=0))
    {
        cout << "Enter valid input" << endl;
        return 0;
    }

    arr[n] = parityassignment(sum,oddoreven);

    cout << "Transmitting Message: " << endl;
    for(int i =0; i<=n ; i++)
    {
        cout << arr[i] << " ";
    }

    int error;
    cout <<endl << "For error free transmission press 0, To create error press 1: "<<endl;
    cin >> error;
    if(error)
    {
        arr[0] = arr[0] + 1;
        arr[0] = arr[0] % 2;
    }
    cout << "Recieved Message"<<endl;
    for(int i =0; i<=n ; i++)
    {
        cout << arr[i] << " ";
    }
    int check;
    check = paritycheck(arr,n+1,oddoreven);
    if(check)
    {
        cout<< endl <<"Error is present, Data should be sent again" << endl;
    }
    else
    {
        cout<< endl<<"Error is not present, Data transmission successfull" << endl;
    }
    return 0; 
}