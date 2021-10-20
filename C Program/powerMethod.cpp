#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter the order of matrix: ";
    cin >> n;
    float tol;
    cout << "Enter tolerence: ";
    cin >> tol;
    float **mat = new float *[n];
    for (int i = 0; i < n; i++)
        mat[i] = new float[n];
    cout << "Enter the matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }
    float *X = new float[n];
    X[0] = 1;
    for (int i = 1; i < n; i++)
        X[i] = 0;
    float lambda, maxDiff;
    float *tempX = new float[n];
    float *diff = new float[n];
    do
    {
        for (int i = 0; i < n; i++)
        {
            float sum = 0;
            for (int j = 0; j < n; j++)
                sum += mat[i][j] * X[j];
            tempX[i] = sum;
        }
        lambda = tempX[0];
        for (int i = 1; i < n; i++)
        {
            if (tempX[i] > lambda)
                lambda = tempX[i];
        }
        for (int i = 0; i < n; i++)
        {
            float nextValue = tempX[i] / lambda;
            diff[i] = fabs(X[i] - nextValue);
            X[i] = nextValue;
        }
        maxDiff = diff[0];
        for (int i = 1; i < n; i++)
        {
            if (diff[i] > maxDiff)
                maxDiff = diff[i];
        }
    } while (maxDiff >= tol);
    cout << "Hence the lambda is: " << lambda << endl;
    cout << "The Eigen vector is:" << endl;
    for (int i = 0; i < n; i++)
        cout << X[i] << endl;
    return 0;
}
