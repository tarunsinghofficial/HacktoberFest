#include<iostream>
using namespace std;
void d();
void p();
bool go();
char turn;
bool draw =false;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int main()
{
cout<<"Tic tac Game"<<endl;
cout<<"Player 1 [x] and player 2 [o]"<<endl;
turn ='X';
while(!go())
{
    d();
    p();
    go();
}
if(turn == 'O' && !draw)
{
    d();
    cout<<endl<<"Player 1 winner"<<endl<<"Game over"<<endl;
}
else if(turn =='X' && !draw)
{
    d();
    cout<<endl<<"Player 2 winner"<<endl<<"Game over"<<endl;
}
else{
    d();
    cout<<endl<<"Draw"<<endl<<"Game over"<<endl;
}
}
void d()
{


cout<<"-----------------------"<<endl;
cout<<"    |     |      "<<endl;
cout<<" "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<endl;
cout<<"____|_____|______"<<endl;
cout<<"    |     |      "<<endl;
cout<<"  "<<board[1][0]<<" |  "<<board[1][1]<<"  |  "<<board[1][2]<<endl;
cout<<"____|_____|______"<<endl;
cout<<"    |     |      "<<endl;
cout<<" "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<endl;
cout<<"    |     |      "<<endl;
}
void p()
{
    int choice;
    int r=0,c=0;
    if(turn == 'X')
    {
        cout<<"player 1 turn [x]: ";
    }
    else if(turn == 'O')
    {
        cout<<"player 2 turn [o]: ";
    }
    cin>>choice;
    switch(choice)
    {
        case 1:r=0;c=0;break;
        case 2:r=0;c=1;break;
        case 3:r=0;c=2;break;
        case 4:r=1;c=0;break;
        case 5:r=1;c=1;break;
        case 6:r=1;c=2;break;
        case 7:r=2;c=0;break;
        case 8:r=2;c=1;break;
        case 9:r=2;c=2;break;
        default:
            cout<<"wrong choice"<<endl;
            p();

    }
    if(turn == 'X' && board[r][c] != 'X' && board[r][c] != 'O')
    {
        board[r][c] ='X';
        turn = 'O';
    }
    else if(turn == 'O' && board[r][c] != 'X' && board[r][c] != 'O')
    {
        board[r][c] ='O';
        turn = 'X';
    }
    else
    {
        cout<<"......."<<endl;
        p();

    }
}
bool go(){

for(int i=0;i<3;i++)
{
    if(board[i][0] == board[i][1] && board[i][1] == board[i][2]||(board[0][i]==board[1][i] && board[1][i] == board [2][i]))
      {
         return true;
      }
}
for(int i =0;i<3;i++)
{
    for (int j=0;j<3;j++)
    {

        if(board[i][j] != 'X' && board[i][j] != 'O')
    {
        return false;
    }
}
}

draw = true;



return true;


}
