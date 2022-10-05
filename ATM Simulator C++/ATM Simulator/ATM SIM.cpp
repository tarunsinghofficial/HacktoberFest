//Project: C++ ATM Program
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <time.h>
#include <string.h>
using namespace std;

void showMenu();
int mainMenuSelection(int);
void welcomeScreen();
void receipt();
void showLogo();
double enterAmountScreen(double);

void waiting(unsigned int mseconds)
	{
		clock_t goal = mseconds + clock();
		while (goal > clock());
	}
	
int main()
{
int choice, account;
string pin = "";
char ast;

	cout << fixed << showpoint << setprecision(2);

	welcomeScreen();
	
	system("cls");
	showLogo();
	cout << "\n\n\t\t\t  Please type your Bank Account Number : ";
	cin >> account;
	cout << "\n\t\t\t  Please type Personal Identification Number(PIN) : ";
	ast = _getch();
	//cin >> pin;
	
	while(ast!=13)
	{
      pin.push_back(ast);
      cout << '*';
      ast = _getch();

	}
 if (account!=221215 && pin!="221215")
 {
 	cout << "\n\t\t\tInvalid Bank Account and PIN. Please try again!"<<endl;
	getch();
 	
 }	
 else
  {
	//Create a do\while loop
	do
		{
			//Display the menu and get the user's choice.
			showMenu();
			cin >> choice;
			//Validate the menu selection.
			while (choice < 1 || choice > 5)
			{
				cout << "\n\t\t\tPlease enter your choice 1, 2, 3, 4, or 5: ";
				cin >> choice;
			}
			//Function to choose in the main menu selection1353
			
		int withdrawChoice, depositChoice;
		int checkBalanceChoice, fundsTransferChoice;
		double money = 0.0;
		char conf;
			if (choice==1)
			{			
					system("cls");
					showLogo();
					cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WITHDRAWAL TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
					cout << "\n\n\t\t\t [ 1 ] From Checking" << endl;
					cout << "\t\t\t [ 2 ] From Savings" << endl;
					cout << "\t\t\t [ 3 ] Quick Cash" << endl;
					cout << "\t\t\t [ 4 ] Back to Main Menu" << endl;
					cout << "\t\t\t _____________________________________________"<<endl;
					cout << "\t\t\t Enter your withdraw transaction: ";
					cin >> withdrawChoice;
						while (withdrawChoice <1 || withdrawChoice >4 )
							{
								system("cls");
								showLogo();
								cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WITHDRAWAL TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
								cout << "\n\n\t\t\t Invalid Transaction!\n\t\t\t Please re-enter 1, 2, 3 or 4 :  ";
								cin >> withdrawChoice;
							}
						if (withdrawChoice == 4)
						{
							showMenu();
						}
						//Quick Cash
						else if (withdrawChoice == 3) 
						{
							//fn1353
							int amount1;
							system("cls");
							showLogo();
							cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 QUICK CASH TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
							cout << "\n\n\t\t\t REMAINING BALANCE : Php 10000"<<endl;
							cout << "\n\t\t\t Enter the Amount (Php) : ";
							cin >> amount1;
							cout << "\n\t\t\t Your remaining quick cash balance: Php "<<10000 - amount1<<endl;
							waiting(3000);
							receipt();
						cout << "\n\t\t\t|TRANSACTION:\t\t    QUICK WITHDRAWAL  |"
						 	 << "\n\t\t\t|AMOUNT:\t\t    "<<amount1<<".00\t      |"
						 	 << "\n\t\t\t|CURRENT BAL:\t\t    "<<20000 - amount1<<".00\t      |"
							 << "\n\t\t\t|AVAILABLE BAL:\t\t    "<<20000 - amount1<<".00\t      |"
							 << "\n\t\t\t|\t\t\t\t\t      |\n\t\t\t|HUWAG IPAALAM ANG PIN SA IBA.\t\t      |"
							 << "\n\t\t\t|\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2|";
							waiting(10000);
							showMenu();
						}
						else if (withdrawChoice == 2)
						{
							int amount2;
							system("cls");
							showLogo();
							cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CASH SAVINGS TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
							cout << "\n\n\t\t\t AVAILABLE BALANCE : Php 10000" << endl;
							cout << "\t\t\t Enter the amount : ";
							cin >> amount2;
							cout << "\t\t\t Your remaining savings balance: Php "<<10000 - amount2<<endl;
							waiting(5000);
							system("cls");
							receipt();
						cout << "\n\t\t\t|TRANSACTION:\t\t    SAVINGS WITHDRAWAL|"
						 	 << "\n\t\t\t|AMOUNT:\t\t    "<<amount2<<".00\t      |"
						 	 << "\n\t\t\t|CURRENT BAL:\t\t    "<<20000 - amount2<<".00\t      |"
							 << "\n\t\t\t|AVAILABLE BAL:\t\t    "<<20000 - amount2<<".00\t      |"
							 << "\n\t\t\t|\t\t\t\t\t      |\n\t\t\t|HUWAG IPAALAM ANG PIN SA IBA.\t\t      |"
							 << "\n\t\t\t|\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2|";
							waiting(10000);
							//brought to you by code-projects.org
							showMenu();
						}
						else if (withdrawChoice == 1)
						{
							int amount3;
							system("cls");
							showLogo();
							cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CASH CHECKING TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
							cout << "\n\n\t\t\t AVAILABLE BALANCE : Php 20000" << endl;
							cout << "\t\t\t Enter the amount : ";
							cin >> amount3;
							cout << "\t\t\t Your remaining check balance: Php "<<20000 - amount3<<endl;
							waiting(3000);
							system("cls");
							receipt();
						cout << "\n\t\t\t|TRANSACTION:\t\t    CASH WITHDRAWAL   |"
						 	 << "\n\t\t\t|AMOUNT:\t\t    "<<amount3<<".00\t      |"
						 	 << "\n\t\t\t|CURRENT BAL:\t\t    "<<20000 - amount3<<".00\t      |"
							 << "\n\t\t\t|AVAILABLE BAL:\t\t    "<<20000 - amount3<<".00\t      |"
							 << "\n\t\t\t|\t\t\t\t\t      |\n\t\t\t|HUWAG IPAALAM ANG PIN SA IBA.\t\t      |"
							 << "\n\t\t\t|\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2|";
							waiting(10000);
							showMenu();							
						}
			}
			else if(choice==2)
			{
						system("cls");
						showLogo();
						cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 DEPOSIT TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
						cout << "\n\n\t\t\t [ 1 ] To Checking" << endl;
						cout << "\t\t\t [ 2 ] To Savings" << endl;
						cout << "\t\t\t [ 3 ] Back to Main Menu" << endl;
						cout << "\t\t\t _____________________________________________"<<endl;
						cout << "\t\t\t Enter your deposit transaction: ";
						cin >> depositChoice;
						while (depositChoice < 1 || depositChoice > 3)
							{
								system("cls");
								showLogo();
								cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 DEPOSIT TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
								cout << "\n\n\t\t\t Invalid Transaction!\n\t\t\t Please re-enter 1, 2 or 3 :  ";
								cin >> depositChoice;
							}
						if (depositChoice == 3)
						{
							showMenu();
						}
						else if (depositChoice == 2)
						{
							int depamount1;
							system("cls");
							showLogo();
							cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SAVINGS DEPOSIT TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
							cout << "\n\n\t\t\t Enter the deposit amount : Php ";
							cin >> depamount1;
							cout << "\t\t\t Your New Balance: Php "<<depamount1+10000<<endl;
							waiting(5000);
							system("cls");
							showMenu();						
			
						}
						else if (depositChoice == 1)
						{
							int depamount2;
							system("cls");
							showLogo();
							cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CHECK DEPOSIT TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
							cout << "\n\n\t\t\t Enter the deposit amount : Php ";
							cin >> depamount2;
							cout << "\t\t\t Your New Balance: Php "<<depamount2+20000<<endl;
							waiting(5000);
							system("cls");
							showMenu();						
						}					
			}
			else if (choice==3)
			{					
						system("cls");
						showLogo();
						cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CHECK BALANCE TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
						cout << "\n\n\t\t\t [ 1 ] From Checking" << endl;
						cout << "\t\t\t [ 2 ] From Savings" << endl;
						cout << "\t\t\t [ 3 ] Back to Main Menu" << endl;
						cout << "\t\t\t _____________________________________________"<<endl;
						cout << "\t\t\t Enter Your Check Balance Choice: ";
						cin >> checkBalanceChoice;
							while (checkBalanceChoice < 1 || checkBalanceChoice > 3)
							{
								system("cls");
								showLogo();
								cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CHECK BALANCE TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
								cout << "\n\n\t\t\t Invalid Transaction!\n\t\t\t Please re-enter 1, 2 or 3 :  ";
								cin >> checkBalanceChoice;
							}
						if (checkBalanceChoice == 3)
						{
							showMenu();
						}
						else if (checkBalanceChoice ==2)
						{
							system("cls");
							showLogo();
							cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BALANCE SAVINGS TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
							cout << "\n\n\t\t\t NEW AVAILABLE BALANCE : Php 10000";
							waiting(3000);
							showMenu();
						}
						else if (checkBalanceChoice ==1)
						{
							system("cls");
							showLogo();
							cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BALANCE CHECK TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
							cout << "\n\n\t\t\t NEW CHECK BALANCE : Php 20000";
							waiting(3000);
							showMenu();
						}
			}
			else if (choice==4)
			{	
						system("cls");
						showLogo();
						cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FUND TRANSFER TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
						cout << "\n\n\t\t\t [ 1 ] Transfer from Savings to Checking" << endl;
						cout << "\t\t\t [ 2 ] Transfer from Checking to Savings" << endl;
						cout << "\t\t\t [ 3 ] Back to Main Menu" << endl;
						cout << "\t\t\t _____________________________________________"<<endl;
						cout << "\t\t\t Enter Your Funds Transfer Transaction: ";
						cin >> fundsTransferChoice;
						while (fundsTransferChoice < 1 || fundsTransferChoice > 3)
							{
								system("cls");
								showLogo();
								cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FUND TRANSFER TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
								cout << "\n\n\t\t\t Invalid Transaction!\n\t\t\t Please re-enter 1, 2 or 3 :  ";
								cin >> fundsTransferChoice;
							}
						if (fundsTransferChoice == 3)
						{
							showMenu();
						}
						else if (fundsTransferChoice ==2)
						{
							int accntNo, checkNo, amntNo;
							system("cls");
							showLogo();
							cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CHECK TRANSFER TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
							cout << "\n\n\t\t\t NEW CHECK BALANCE : Php 20000";
							cout << "\n\t\t\t Account Number (for Transfer) : ";
							cin >> accntNo;
							cout << "\n\t\t\t Check Number : ";
							cin >> checkNo;
							cout << "\n\t\t\t Amount Transfer : Php ";
							cin >> amntNo;
							while (amntNo < 2000 || amntNo > 20000)
							{
								system("cls");
								showLogo();
								cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CHECK TRANSFER TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
								cout << "\n\n\t\t\t Invalid Amount!\n\t\t\t Please try again!";
								cout << "\n\t\t\t Please enter Amount Transfer : Php ";
								cin >> amntNo;
								
							}
							waiting(1000);
							cout << "\n\n\t\t\t The amount of Php "<<amntNo<<" has been transfered to \n\t\t\t "<<accntNo<<" with a check # "<<checkNo<<endl;
							waiting(10000);
							showMenu();
						}
						else if (fundsTransferChoice ==1)
						{
							int accntNo, checkNo, amntNo;
							system("cls");
							showLogo();
							cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SAVINGS TRANSFER TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2";
							cout << "\n\n\t\t\t NEW SAVINGS BALANCE : Php 10000";
							cout << "\n\t\t\t Account Number (for Transfer) : ";
							cin >> accntNo;
							cout << "\n\t\t\t Amount Transfer : Php ";
							cin >> amntNo;
							while (amntNo < 2000 || amntNo > 10000)
							{
								system("cls");
								showLogo();
								cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SAVINGS TRANSFER TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2";
								cout << "\n\n\t\t\t Invalid Amount!\n\t\t\t Please try again!";
								cout << "\n\t\t\t Please enter Amount Transfer : Php ";
								cin >> amntNo;
								
							}
							waiting(1000);
							cout << "\n\n\t\t\t The amount of Php "<<amntNo<<" has been transfered to "<<accntNo;
							waiting(10000);
							showMenu();
						}
			}		
			else if (choice ==5)
			{
						cout << " \n\t\t\t Brought To You By code-projects.org" << endl << endl;
						getch();
			}
		} while (choice != 5);
 }
		return 0;

}
	//Function to display the welcome screen
	void welcomeScreen()
	{
		cout<<"\n\t\t\t _____________________________________________"
			<<"\n\t\t\t|\t\t\t\t\t      |\n\t\t\t| \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  |"
		    <<"\n\t\t\t| \xB2\xB2\t     \xB2\xB2\t\xB2\xB2\t   \xB2\xB2\t\xB2\xB2\t   \xB2\xB2 |"
		    <<"\n\t\t\t| \xB2\xB2\t     \xB2\xB2\t\xB2\xB2\t   \xB2\xB2\t\xB2\xB2\t   \xB2\xB2 |"
		    <<"\n\t\t\t| \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t\xB2\xB2\t   \xB2\xB2\t\xB2\xB2\t   \xB2\xB2 |"
		    <<"\n\t\t\t| \xB2\xB2\t     \xB2\xB2\t\xB2\xB2\t   \xB2\xB2\t\xB2\xB2\t   \xB2\xB2 |"
		    <<"\n\t\t\t| \xB2\xB2\t     \xB2\xB2\t\xB2\xB2\t   \xB2\xB2\t\xB2\xB2\t   \xB2\xB2 |"
		    <<"\n\t\t\t| \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  |"
		    <<"\n\t\t\t|\t\t\t\t\t      |\n\t\t\t|=============== ATM SIMULATION ==============|";		
		cout << "\n\n\t\t\tPlease INSERT your Card [Press ENTER to insert card] ";
		cin.get();
	}

	void showLogo()
	{
			cout<<"\n\t\t\t + ************** WELCOME TO *************** + ";
			cout<<"\n\t\t\t _____________________________________________"
				<<"\n\t\t\t|\t\t\t\t\t      |\n\t\t\t| \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  |"
			    <<"\n\t\t\t| \xB2\xB2\t     \xB2\xB2\t\xB2\xB2\t   \xB2\xB2\t\xB2\xB2\t   \xB2\xB2 |"
			    <<"\n\t\t\t| \xB2\xB2\t     \xB2\xB2\t\xB2\xB2\t   \xB2\xB2\t\xB2\xB2\t   \xB2\xB2 |"
			    <<"\n\t\t\t| \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t\xB2\xB2\t   \xB2\xB2\t\xB2\xB2\t   \xB2\xB2 |"
			    <<"\n\t\t\t| \xB2\xB2\t     \xB2\xB2\t\xB2\xB2\t   \xB2\xB2\t\xB2\xB2\t   \xB2\xB2 |"
			    <<"\n\t\t\t| \xB2\xB2\t     \xB2\xB2\t\xB2\xB2\t   \xB2\xB2\t\xB2\xB2\t   \xB2\xB2 |"
			    <<"\n\t\t\t| \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  |"
			    <<"\n\t\t\t|\t\t\t\t\t      |\n\t\t\t|=============== ATM SIMULATION ==============|";		
	}

	void showMenu()
		{
			system("cls");
			showLogo();
			cout << endl <<" \t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
			cout << "\n\n\t\t\t [ 1 ] Withdrawal" << endl;
			cout << "\t\t\t [ 2 ] Deposit" << endl;
			cout << "\t\t\t [ 3 ] Check Balance" << endl;
			cout << "\t\t\t [ 4 ] Funds Transfer" << endl;
			cout << "\t\t\t [ 5 ] Exit ATM" << endl;
			cout << "\t\t\t _____________________________________________"<<endl;
			cout << "\t\t\t Enter your choice: ";
		}
	
	void receipt()
	{
			system("cls");
			showLogo();
			char date[9];
			char time[9];
			_strdate(date);
			_strtime(time);
			cout << "\n\n\t\t\t\t\t PRINTING RECEIPT . . .\n";
			waiting(3000);
			system("cls");
			showLogo();
			cout << endl <<"\n\n\t\t\t|\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANCO DE ORO \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2|";
			cout << "\n\t\t\t|\t\t\t\t\t      |"
				 << "\n\t\t\t|\t     ATM TRANSACTION RECORD\t      |"
				 << "\n\t\t\t|\t\t\t\t\t      |"
				 << "\n\t\t\t|DATE:\t\t\t    "<<date<<"\t      |"
				 << "\n\t\t\t|TIME:\t\t\t    "<<time<<"\t      |"
				 << "\n\t\t\t|LOCATION:\t\t    MASBATE \t      |"
				 << "\n\t\t\t|CARD NUM:\t\t    ************1215  |";
	}
			
		//Function to enter amount screen
		double enterAmountScreen(double money)
		{
			system("cls");
			int decision;
				cout << endl << "\t\tEnter Amount Screen" << endl;
				cout << "[ 1 ] Enter Amount:";
				cout << endl << "[ 2 ] Back to Main Menu:";
				cout << endl << "Enter your decision for the amount screen: ";
				cin >> decision;
				if (decision == 2)
					{
						showMenu();
					}
				else
					{
						cout << "Please enter the amount: ";
						cin >> money;
					}
			return money;
		}
