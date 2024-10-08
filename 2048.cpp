#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

void moveUp(int a[4][4])
{
    for (int j = 0; j < 4; j++)
    {
        int pos = 0;
        for (int i = 1; i < 4; i++)
        {
            if (a[i][j] != 0)
            {
                if (a[pos][j] == a[i][j])
                {
                    a[pos][j] *= 2;
                    a[i][j] = 0;
                    pos++;
                }
                else if (a[pos][j] == 0)
                {
                    a[pos][j] = a[i][j];
                    a[i][j] = 0;
                }
                else
                {
                    a[++pos][j] = a[i][j];
                    if (pos != i) a[i][j] = 0;
                }
            }
        }
    }
}

void moveDown(int a[4][4])
{
    for (int j = 0; j < 4; j++)
    {
        int pos = 3;
        for (int i = 2; i >= 0; i--)
        {
            if (a[i][j] != 0)
            {
                if (a[pos][j] == a[i][j])
                {
                    a[pos][j] *= 2;
                    a[i][j] = 0;
                    pos--;
                }
                else if (a[pos][j] == 0)
                {
                    a[pos][j] = a[i][j];
                    a[i][j] = 0;
                }
                else
                {
                    a[--pos][j] = a[i][j];
                    if (pos != i) a[i][j] = 0;
                }
            }
        }
    }
}

void moveLeft(int a[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        int pos = 0;
        for (int j = 1; j < 4; j++)
        {
            if (a[i][j] != 0)
            {
                if (a[i][pos] == a[i][j])
                {
                    a[i][pos] *= 2;
                    a[i][j] = 0;
                    pos++;
                }
                else if (a[i][pos] == 0)
                {
                    a[i][pos] = a[i][j];
                    a[i][j] = 0;
                }
                else
                {
                    a[i][++pos] = a[i][j];
                    if (pos != j) a[i][j] = 0;
                }
            }
        }
    }
}

void moveRight(int a[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        int pos = 3;
        for (int j = 2; j >= 0; j--)
        {
            if (a[i][j] != 0)
            {
                if (a[i][pos] == a[i][j])
                {
                    a[i][pos] *= 2;
                    a[i][j] = 0;
                    pos--;
                }
                else if (a[i][pos] == 0)
                {
                    a[i][pos] = a[i][j];
                    a[i][j] = 0;
                }
                else
                {
                    a[i][--pos] = a[i][j];
                    if (pos != j) a[i][j] = 0;
                }
            }
        }
    }
}

void addBlock(int a[4][4])
{
    int li, ri;
    srand(time(0));
    while (true)
    {
        li = rand() % 4;
        ri = rand() % 4;
        if (a[li][ri] == 0)
        {
            a[li][ri] = rand() % 2 == 0 ? 2 : 4;
            break;
        }
    }
}

void display(int a[4][4])
{
    cout << "\n\t\tPress Esc anytime to quit the game\n\n\n";
    for (int i = 0; i < 4; i++)
    {
        cout << "\t\t\t\t-----------------\n\t\t\t\t";
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] == 0) cout << "|   ";
            else cout << "| " << a[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << "\t\t\t\t-----------------\n";
}

bool isSame(int tmp[4][4], int a[4][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (tmp[i][j] != a[i][j])
                return false;
    return true;
}

bool canMove(int a[4][4])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (a[i][j] == 0) return true;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (a[i][j] == a[i + 1][j] || a[i][j] == a[i][j + 1])
                return true;

    return false;
}

int main()
{
    cout << "\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress any key to continue";
    getch();
    system("cls");

    int a[4][4] = {0}, tmp[4][4] = {0};
    srand(time(0));

    a[rand() % 4][rand() % 4] = 2;
    while (true)
    {
        int r1 = rand() % 4, r2 = rand() % 4;
        if (a[r1][r2] == 0)
        {
            a[r1][r2] = 4;
            break;
        }
    }

    display(a);

    while (true)
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                tmp[i][j] = a[i][j];

        int ch = getch();
        system("cls");

        if (ch == 72) moveUp(a);
        else if (ch == 80) moveDown(a);
        else if (ch == 75) moveLeft(a);
        else if (ch == 77) moveRight(a);
        else if (ch == 27) break;

        if (!isSame(tmp, a)) addBlock(a);
        display(a);

        if (!canMove(a))
        {
            cout << "\n\n\t\t\tGAME OVER!!\n\n\n";
            getch();
            break;
        }
    }

    return 0;
}
