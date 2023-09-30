#include<bits/stdc++.h>
#define maxi 1000
using namespace std;

struct Item     //Structure declaration
{   
    int weight; //variable to store weight of the item        
    int value;  //variable to store value of the item
    
};

bool compare(Item a,Item b)     //Comparator function to sort according to value by weight ratio
{
    double c = ( double)a.value / (double)a.weight; // checking value by weight ratio for item a
    double d = (double)b.value / (double)b.weight;  // checking value by weight ratio for item b
    return c > d;
}


int main()
{
    int n,capacity;         // Declaration of variables for no of items and capacity of bag
    int cur_weight=0;       // Initializing current value of weight to 0
    double total_profit=0;  // Initializing value of total_profit to 0

     cout<<"Enter the number of items you want :: ";
     cin>>n;        //taking no of items from user

     cout<<"\nEnter maximum capacity weight which you can carry :: ";
     cin>>capacity;     //taking capacity of bag from user

    Item obj[n];    //Declaring array of structure
    vector<vector<int>> DP(n + 1, vector<int>(capacity + 1));   //Declaring 2d array for 0-1 knapsack using dynamic Programming


    int choice;     // Declaring choice variable to take choice from the user

    do          //using do-while loop
    {
        cout<<"\n\n-------------------------------------------------"<<endl;    // Displaying Menu
        cout<<"1. Input"<<endl;
        cout<<"2. Display"<<endl;
        cout<<"3. Fractional Knapsack using Greedy Algorithm"<<endl;
        cout<<"4. 0-1 Knapsack using Dynamic Programming"<<endl;
        cout<<"5. 0-1 Knapsack using Greedy Algorithm"<<endl;
        cout<<"0. Exit the Program"<<endl;
        cout<<"-------------------------------------------------\n"<<endl;

        cout<<"Enter an choice\n";
        cin>>choice;                       // Taking choice from user 

        switch(choice)          //menu driven program using switch case
        {
            case 1:                     // case 1 for input
                for(int i=0;i<n;i++)
                {
                    cout<<"Weight["<<i<<"]:\t";
                    cin>>obj[i].weight;         //Taking weight from user for each item
                    cout<<"Value["<<i<<"]:\t";
                    cin>>obj[i].value;          // taking value from user for each item
                    cout<<endl;
                }
                break;          // end of case one


            case 2:                         // case 2 for display
                cout<<"\n(Weight,Value) pairs"<<endl;
                for (int i = 0; i < n; i++)
                {
                    cout<<i+1<<". ("<<obj[i].weight<<", "<<obj[i].value<<")  "<<endl;     //displaying weight and value of each item 

                }
                break;               // end of case two


            case 3:                         // case 3 for Fractional knapsack using Greedy algorithm
                sort(obj,obj+n,compare);    // calling sort function to sort items according to value by weight ratio
                for(int i=0;i<n;i++)           // using for loop for iterating over n items
                {
                     if (cur_weight + obj[i].weight <= capacity)    //checking if sum of current weight and object weight is less than bag capacity
                    {
                        cur_weight+= obj[i].weight;     // if true then adding object weight in bag
                        total_profit+=obj[i].value;     // also adding the object value to profit value
                        cout<<"Added object "<<(i+1)<<" ("<<obj[i].value<<" Rs., "<<obj[i].weight<<"Kg) completely in the bag. Space left: "<<cur_weight<<endl;
                    }
                    else
                    {
                        int remain = capacity - cur_weight;         // calculating remaining weight than the capacity of bag
                        double item_percent = (int) (((double)remain/(double)obj[i].weight)*100);   // calculating percentage of weight that must be added in the bag
                        total_profit += obj[i].value*((double)remain/(double)obj[i].weight);        // calculating total profit value of that percent weight of item
                        cout<<"Added "<<item_percent<<"% ("<<obj[i].value<<" Rs., "<<obj[i].weight<<" Kg) of object "<<i + 1<<" in the bag.\n";
                        break;
                    }
                }
                cout<<"\nFill the bag with objects worth "<<total_profit<<" Rs."<<endl;
                cout<<"Maximum Profit value by fractional knapsack using greedy algorithm is "<<total_profit<<"\n";      //printing final profit value
                break;           // end of case three


            case 4:                     // case 4 for 0-1 knapsack using Dynamic Programming
                for(int i = 0; i <= n; i++)     // using for loop for iterating over n items
                {
                    for(int w = 0; w <= capacity; w++)       // using for loop for iterating over capacity of bag
                    {
                        if (i == 0 || w == 0)      // if its first row and first column 
                        {
                           DP[i][w] = 0;        // then fill the first row and all columns with all zero's
                        }

                        else if (obj[i - 1].weight <= w)
                        {
                          DP[i][w] = max(obj[i - 1].value + DP[i - 1][w - obj[i-1].weight],DP[i - 1][w]);
                        }

                        else{
                            DP[i][w] = DP[i - 1][w];
                        }

                    }
                }
                cout<<"\nMaximum Profit value by 0-1 knapsack using dp is "<<DP[n][capacity]<<"\n"; //printing final profit value
                break;              // end of case four


            case 5:                             // case 5 for 0-1 knapsack using Greedy algorithm
                sort(obj,obj+n,compare);        // calling sort function to sort items according to value by weight ratio
                cur_weight=0;
                total_profit=0;
                for(int i=0;i<n;i++)            // using for loop for iterating over n items    
                {
                     if (cur_weight + obj[i].weight <= capacity)     //checking if sum of current weight and object weight is less than bag capacity
                     {
                        cur_weight+= obj[i].weight;         // if true then adding object weight in bag
                        total_profit+=obj[i].value;         // also adding the object value to profit value
                    }
                }
                cout<<"\nMaximum Profit value by 0-1 knapsack using greedy algorithm is "<<total_profit<<"\n";  //printing final profit value
                break;              // end of case five


            case 0:         //zeroth case to terminate the program
                cout<<"Program Executed Successfully.... \n******Thank You !!!******";
                return 0;       // end of program


            default:        //default case
                cout<<"Enter valid choice\n";
                break;          // end of default case
        }  //end of switch case
    }while(1);  //end of do-while loop
} //end of main function

/*

OUTPUT OF KNAPSACK PROBLEM ::--

Enter the number of items you want :: 3

Enter maximum capacity weight which you can carry :: 50


-------------------------------------------------
1. Input
2. Display
3. Fractional Knapsack using Greedy Algorithm    
4. 0-1 Knapsack using Dynamic Programming        
5. 0-1 Knapsack using Greedy Algorithm
0. Exit the Program
-------------------------------------------------

Enter an choice
1
Weight[0]:      10
Value[0]:       60

Weight[1]:      20
Value[1]:       100

Weight[2]:      30
Value[2]:       120



-------------------------------------------------
1. Input
2. Display
3. Fractional Knapsack using Greedy Algorithm
4. 0-1 Knapsack using Dynamic Programming
5. 0-1 Knapsack using Greedy Algorithm
0. Exit the Program
-------------------------------------------------

Enter an choice
2

(Weight,Value) pairs
1. (10, 60)
2. (20, 100)
3. (30, 120)


-------------------------------------------------
1. Input
2. Display
3. Fractional Knapsack using Greedy Algorithm
4. 0-1 Knapsack using Dynamic Programming
5. 0-1 Knapsack using Greedy Algorithm
0. Exit the Program
-------------------------------------------------

Enter an choice
3
Added object 1 (60 Rs., 10Kg) completely in the bag. Space left: 10
Added object 2 (100 Rs., 20Kg) completely in the bag. Space left: 30
Added 66% (120 Rs., 30 Kg) of object 3 in the bag.

Fill the bag with objects worth 240 Rs.
Maximum value in fractional knapsack using greedy algorithm is 240


-------------------------------------------------
1. Input
2. Display
3. Fractional Knapsack using Greedy Algorithm
4. 0-1 Knapsack using Dynamic Programming
5. 0-1 Knapsack using Greedy Algorithm
0. Exit the Program
-------------------------------------------------

Enter an choice
4

Maximum value in 0-1 knapsack using dp is 220


-------------------------------------------------
1. Input
2. Display
3. Fractional Knapsack using Greedy Algorithm
4. 0-1 Knapsack using Dynamic Programming
5. 0-1 Knapsack using Greedy Algorithm
0. Exit the Program
-------------------------------------------------

Enter an choice
5

Maximum value in 0-1 knapsack using greedy algorithm is 160


-------------------------------------------------
1. Input
2. Display
3. Fractional Knapsack using Greedy Algorithm
4. 0-1 Knapsack using Dynamic Programming
5. 0-1 Knapsack using Greedy Algorithm
0. Exit the Program
-------------------------------------------------

Enter an choice
0
Program Executed Successfully.... 
******Thank You !!!******


*/
