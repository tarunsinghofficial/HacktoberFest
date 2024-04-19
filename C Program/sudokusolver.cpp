#include<iostream>
#include<cmath>
using namespace std;
#define N 9
bool canplace(int board[N][N],int i,int j,int n,int number )
{
	for(int x =0;x<n;x++)
	{
		if(board[x][j]== number || board[i][x] == number)
		{
			return false;
		}
	}
	int rn = sqrt(n);
	int sx = (i /rn) *   rn;
	int sy = (j /rn) * rn;
	
	for(int x = sx;x < sx+rn;x++)
	{
		for(int y = sy;y < sy+rn;y++)
		{
			if(board[x][y] == number)
			{
				return false;
			}
		}
	}
	return true;
}
bool solvesudoku(int board[N][N],int i,int j,int n)
{
	if(i ==n)
	{
		return true;
	}
	if(j == n)
	{
		return solvesudoku(board,i+1,0,n);
	}
	if(board[i][j] != 0)
	{
		return solvesudoku(board,i,j+1,n);
	}
	for(int number =1;number<=9;number++)
	{
		if(canplace(board,i,j,n,number))
		{
			board[i][j] = number;
			bool couldsolve = solvesudoku(board ,i ,j+1,n);
			if(couldsolve == true)
			{
				return true;
			}
		}
	}
	board[i][j] = 0;
	return false;
}
int main()
{
	int n;
	cout<<"Enter Size of sudoku"<<endl;
	cin>>n;
	int board[N][N ];
	cout<<"Enter sudoku values"<<endl;
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<n;j++)
		{
			cin>>board[i][j];
		}
	}
	if(solvesudoku(board,0,0,n))
	{
		for(int i =0;i<n;i++)
		{
			for(int j =0;j<n;j++)
			{
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
	
}