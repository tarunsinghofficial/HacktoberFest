#include <iostream>
#include <cmath>
using namespace std;

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
    for (int i = 0; i < n; i++)
    {
        if (fabs(mat[i][i]) < 0.005)
        {
            cerr << "Principal diagonal element cannot be zero." << endl;
            return 1;
        }
        for (int j = i + 1; j < n; j++)
        {
            float t = mat[j][i] / mat[i][i];
            for (int k = 0; k <= n; k++)
                mat[j][k] -= t * mat[i][k];
        }
    }
    float *solution = new float[n];
    for (int i = n - 1; i >= 0; i--)
    {
        solution[i] = mat[i][n];
        for (int j = i + 1; j < n; j++)
            solution[i] -= mat[i][j] * solution[j];
        solution[i] /= mat[i][i];
    }
    cout << "The value of unknowns are: " << endl;
    for (int i = 0; i < n; i++)
        cout << "x" << i << " = " << solution[i] << endl;
    return 0;
}
