#include <bits/stdc++.h>
using namespace std;

#define human 'X'
#define bot 'O'
#define SIDE 3

vector<vector<pair<int,int>>> winCombos = {
    {{0,0},{0,1},{0,2}},
    {{1,0},{1,1},{1,2}},
    {{2,0},{2,1},{2,2}},
    {{0,0},{1,0},{2,0}},
    {{0,1},{1,1},{2,1}},
    {{0,2},{1,2},{2,2}},
    {{0,0},{1,1},{2,2}},
    {{0,2},{1,1},{2,0}}
};
// function to show board
void showBoard(char mat[][SIDE]) 
{ 
	printf("\n");
	printf("\t\t\t\t %c | %c | %c \n", mat[0][0], mat[0][1], mat[0][2]); 
	printf("\t\t\t\t-----------\n"); 
	printf("\t\t\t\t %c | %c | %c \n", mat[1][0], mat[1][1], mat[1][2]); 
	printf("\t\t\t\t-----------\n"); 
	printf("\t\t\t\t %c | %c | %c \n\n", mat[2][0], mat[2][1], mat[2][2]);  
} 

// A function to show the instructions 
void showInstructions() 
{ 
	printf("\nChoose a cell numbered from 0 to 8 as below and play\n\n"); 
	
	printf("\t\t\t\t 0 | 1 | 2 \n"); 
	printf("\t\t\t\t-----------\n"); 
	printf("\t\t\t\t 3 | 4 | 5 \n"); 
	printf("\t\t\t\t-----------\n"); 
	printf("\t\t\t\t 6 | 7 | 8 \n\n"); 
} 

void humanTurn(char mat[][SIDE])
{
    
    showBoard(mat);
    printf("Enter the postition : ");
    int pos=-1;
    scanf("%d",&pos);
    char ch = getchar();
    int x = pos / SIDE;
	int	y = pos % SIDE;

    while(pos<0 || pos>8 || mat[x][y]!=' ')
    {
        printf("Enter a valid postion\n");
        printf("Enter the postition : ");
        scanf("%d",&pos);
        char ch = getchar();
        x = pos / SIDE;
        y = pos % SIDE;
    }
    mat[x][y]=human;
}
//Check available cell
int countMoves(char mat[][SIDE])
{
    int ctr=0;
    for(int i=0;i<SIDE;i++)
    {
        for(int j=0;j<SIDE;j++)
        {
            if(mat[i][j]!=' ')
            ctr++;
        }
    }
    return ctr;
}
// Check terminal condition
int endGame(char mat[][SIDE])
{
    // +10 human winner
    // -10 bot winner
    //  2 draw and no moves left
    //  0 draw ,moves left
    
    int res = 0;

    for(int i=0;i<8;i++)
    {
        char x = mat[winCombos[i][1].first][winCombos[i][1].second];
        if(mat[winCombos[i][0].first][winCombos[i][0].second]==x
        && mat[winCombos[i][2].first][winCombos[i][2].second]==x
        && x!=' '){
            if(x==human)
            return res = +10;
            else if(x==bot)
            return res = -10;
        }
        
    }

    int moves = countMoves(mat);
    if(moves==(SIDE*SIDE))
    return 2;
    else
    return res;
}

int minimax(char mat[][SIDE],int depth,int player,int alpha,int beta)
{
    int res = endGame(mat);
    if(res!=0)
    {
        if(res==2)
        return 0;
        else if(res==10)
        return res-depth;
        else if(res==-10)
        return res+depth;
    }

    if(player==bot) 
    {
        //minimizing player
        int best = INT_MAX;
        for(int i=0;i<SIDE;i++)
        {
            for(int j=0;j<SIDE;j++)
            {
                if(mat[i][j]==' ')
                {
                    mat[i][j]=bot;
                    best = min(best,minimax(mat,depth+1,human,alpha,beta));
                    mat[i][j]=' ';
                    beta = min(beta,best);
                    if(alpha>=beta)
                    break;
                }
            }
        }
        return best;
    }
    else
    {
        //maximizing player
        int best = INT_MIN;
        for(int i=0;i<SIDE;i++)
        {
            for(int j=0;j<SIDE;j++)
            {
                if(mat[i][j]==' ')
                {
                    mat[i][j]=human;
                    best = max(best,minimax(mat,depth+1,bot,alpha,beta));
                    mat[i][j]=' ';
                    alpha = max(alpha,best);
                    if(alpha>=beta)
                    break;
                    
                }
            }
        }
        return best;   
    } 
}

void botTurn(char mat[][SIDE])
{
    pair<int,int> bestMove;
    int best = INT_MAX;
    
    for(int i=0;i<SIDE;i++)
    {
        for(int j=0;j<SIDE;j++)
        {
            if(mat[i][j]==' ')
            {
                mat[i][j]=bot;
                int x = minimax(mat,0,human,INT_MIN,INT_MAX);
                
                mat[i][j]=' ';
                if(x<best)
                {
                    best = x;
                    bestMove = {i,j};
                }
            }
        }
    }
    cout << "\n";
   
    mat[bestMove.first][bestMove.second] = bot;
}

void declareWinner(int score)
{
    
    if(score==10)
    printf("\t\t\t\tYOU WON!\n\n");
    else if(score==-10)
    printf("\t\t\t\tAI WON!\n\n");
    else 
    printf("\t\t\t\tMATCH TIED!\n\n");
}

int main()
{

    printf("\n-------------------------------------------------------------------\n\n");
	printf("\t\t\t Tic-Tac-Toe\n"); 
	printf("\n-------------------------------------------------------------------\n\n");
    showInstructions();
    char cont='y';
	do {


        int turn = 0;
        char mat[SIDE][SIDE]=
        {
            {' ',' ',' '},
            {' ',' ',' '},
            {' ',' ',' '}
        };

		char choice=' ';
	 	
        printf("Do you want to start first?(y/n) : ");
	 	scanf(" %c", &choice);
        while(choice!='n' && choice!='y')
        {
            printf("Invalid choice\n");
            printf("Do you want to start first?(y/n) : ");
	 	    scanf(" %c", &choice);
        }

		if(choice=='n')
			turn = 1;
		else if(choice=='y')
			turn = 0;
			


        while(endGame(mat)==0)
        {
            if(!turn)
            {
                humanTurn(mat);
                turn=1;
            }
            else
            {
                botTurn(mat);
                turn=0;
            }
            
        }
        showBoard(mat);
        declareWinner(endGame(mat));
        
		printf("\nDo you want to quit(y/n) : ");
       		scanf(" %c", &cont);
	} while(cont=='n');

    return 0;
}
