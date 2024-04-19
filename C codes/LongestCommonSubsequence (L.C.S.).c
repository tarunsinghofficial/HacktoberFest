#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

//FUNCTIONS 

void displayMemoizationTable(int length1, int length2);
int memoizationTable(char *str1, char *str2, int length1, int length2);
void insert(char *ans, int size, char ch);
void LCS(char answer[MAX_SIZE], char *str1, char *str2, int length1, int length2, int size);

//GLOBAL VARIABLES

int lengthOfLCS;
int memoTable[MAX_SIZE][MAX_SIZE];
char dir[MAX_SIZE][MAX_SIZE];
void insert(char *, int , char);

//SHOWING THE MEMOIZATION TABLE

void displayMemoizationTable(int length1, int length2)
{
    for(int i = 0 ;  i <= length1 ;  i++ )
    {
        for(int j = 0 ;  j <= length2 ;  j++ )
        {
            printf("|   %d   |", memoTable[i][j]);
        }
        printf("\n");
    }
}

//DIRECTIONS FOR TRACKING THE LCS

int memoizationTable(char *str1, char *str2, int length1, int length2)
{
    // U means UP , D means Diagonal , L means LEFT and  E when both Cells [i-1,j] and [i,j-1] are equal
    for(int i = 0; i <= length1; i++)
    {
        memoTable[i][0] = 0;
        dir[i][0] = 'U'; //UP
    }
    for(int i = 0; i <= length2; i++)
    {
        memoTable[0][i] = 0;
        dir[0][i] = 'L'; //LEFT
    }
    for(int i = 1; i <=length1; i++) 
    {
        for(int j = 1; j <=length2; j++)
        {
            if (str1[i-1] == str2[j-1]) 
            {
                memoTable[i][j] = memoTable[i-1][j-1]+1;
                
                dir[i][j] = 'D';//DIAGONAL
            }
            else if(memoTable[i-1][j] > memoTable[i][j-1]) 
            { 
                memoTable[i][j] = memoTable[i-1][j];
                dir[i][j] = 'U';
            }
            else if(memoTable[i-1][j] < memoTable[i][j-1])
            {
                memoTable[i][j] = memoTable[i][j-1];
                dir[i][j] = 'L';
            }
            else
            {
                memoTable[i][j] = memoTable[i][j-1];
                dir[i][j] = 'E';
            }
        }
    }
    return memoTable[length1][length2];
}

//INSERT FUNCTION

void insert(char *ans, int size, char ch)
{
    size = size + 1;
    for(int i = size - 1; i > 0; i--)
    {
        ans[i] = ans[i-1];
    }
    ans[0] = ch;
}

//LCS FUNCTION

void LCS(char answer[MAX_SIZE], char *str1, char *str2, int length1, int length2, int size)
{
    char ans[MAX_SIZE];
    for(int k = 0; k < size; k++)
    {
        ans[k] = answer[k];
    }
    int i = length1;
    int j = length2;
    while(i != 0 && j != 0)
    {
        switch(dir[i][j])
        {
            case 'D':
            insert(ans,size,str1[i-1]);
            size++;
            i--;
            j--;
            break;

            case 'U':
            i--;
            break;

            case 'L':
            j--;
            break;

            case 'E':
            LCS(ans, str1, str2, i-1, j, size);
            j--;
            break;
        }
    }
    for(int k =0; k < size; k++)
    {
        printf("%c", ans[k]);
    }
    printf("\n");
}

//MAIN FUNCTION

int main()
{
    int length1, length2;
   printf("\nPlease enter the length of String 1 :  ");
    scanf("%d", &length1);
    char str1[length1];
    printf("\nPlease enter String 1     :   \n");
    scanf("%s", str1);
    printf("\nPlease enter the length of String 2 :  ");
    scanf("%d", &length2);
    char str2[length2];
    printf("\nPlease enter String 2     :   \n");
     scanf("%s", str2);

    lengthOfLCS = memoizationTable(str1, str2, length1, length2);
    printf("\nThe length of the Longest Common Subsequence (L.C.S)  :    %d\n", lengthOfLCS);

    printf("\nThe MEMOIZATION TABLE is given below\n\n");
    displayMemoizationTable(length1, length2);

    char ans[MAX_SIZE];
    printf("\nAll the possible Longest Common Subsequences of both the Strings are/is :   \n");
    LCS(ans,str1, str2, length1, length2, 0);
}
