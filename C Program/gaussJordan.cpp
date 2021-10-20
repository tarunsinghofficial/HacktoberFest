#include <iostream>
#include <cmath>
using namespace std;

void gaussJorden(float **mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (fabs(mat[i][i]) < 0.005)
        {
            cerr << "Principal diagonal element cannot be zero." << endl;
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            float t = mat[j][i] / mat[i][i];
            for (int k = 0; k <= n; k++)
                mat[j][k] -= t * mat[i][k];
        }
    }
    cout << "The value of unknowns are: " << endl;
    for (int i = 0; i < n; i++)
        cout << "x" << i << " = " << mat[i][n] / mat[i][i] << endl;
}

int main()
{
    int n;
    cout << "Enter the number of unknowns: ";
    cin >> n;
    float **mat = new float *[n];
    for (int i = 0; i < n; i++)
        mat[i] = new float[n + 1];
    cout << "Enter the augmented matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
            cin >> mat[i][j];
    }
    gaussJorden(mat, n);
    return 0;
}
