#include <iostream>

using namespace std;

// Method 1 O(n2);
void method11(int arr[], int size)
{
    int j = 0;
    int i = 0;
    for (i = 0; i < size; i++)
    {
        int suml = 0, sumr = 0;

        j = i - 1;

        while (j >= 0)
        {
            suml += arr[j];
            j--;
        }

        j = i + 1;
        while (j < size)
        {
            sumr += arr[j];
            j++;
        }
        if (suml == sumr)
        {
            cout << "Ans is: " << i << endl;
            break;
        }
    }

    if (i == size - 1)
    {
        cout << "Not found" << endl;
    }
}

void method2(int arr[],int size){
    
}

int main()
{
    int arr[6] = {1, 7, 3, 6, 5, 6};
    int size = 6;
    // method11(arr, size);
}
