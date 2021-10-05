#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define X 5
#define Y 120
//Defining functions
void generator(int arr[], int size, int n);
void display(int best,  int worst, int average);
void swap(int *x, int *y);
void store(int arr[], int n);
void heapify(int arr[], int i, int *count);
int partition (int arr[], int low, int high, int *count);
void quickie(int arr[], int low, int high, int *count);
int partitie(int arr[], int low, int high, int *count);
void BubbleSort();
void HeapSort();
void InsertionSort();
void QuickSort();
void MergeSort();

int P5[Y][X];
int length = -1;

void generator(int arr[], int start, int n)
{
    if(start == n)
    {
        store(arr, n);
    }

    else
    {
        for(int i = start; i < n; i++)
        {
            //Swapping for various permutations
            swap(&arr[start], &arr[i]);

            //Fixing first element of current array
            //and recursively permutating the rest
            generator(arr, start+1, n);

            //Backtracking
            swap(&arr[start], &arr[i]);
        }
    }
}
void display(int best, int worst, int average)
{
    printf("\nBest Case Comparisons : %d", best);
    printf("\nWorst Case Comparisons : %d", worst);
    printf("\nAverage Case Comparisons : %d\n\n", average);
}

void store(int arr[], int n)
{
    length++;
    for(int i = 0; i < n; i++)
    {
        P5[length][i] = arr[i];
    }
}

//Swapping two locations
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//Improved bubbe sort
void BubbleSort()
{
    int min = 100, max = 0, avg = 0;
    int count = 0;
    int swapped;

    for(int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X - 1; j++)
        {
            swapped = 0;
            for (int k = 0; k < X - 1 - j; k++)
            {
                count++;
                avg++;
                if (P5[i][k] > P5[i][k + 1])
                {

                    swap(&P5[i][k], &P5[i][k+1]);
                    swapped = 1;
                }
            }
            if (swapped == 0)
                break;
        }

        if(count < min)
        {
            min = count;
        }

        if(max < count)
        {
            max = count;
        }

        count = 0;
    }

    avg = avg / Y;

    printf("\nBubble Sort");
    display(min, max, avg);
}

void heapify(int arr[], int i, int *count)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < X && arr[l] > arr[largest])
        largest = l;

    if(l < X)
    {
        *count = *count + 1;
    }
    if (r < X && arr[r] > arr[largest])
        largest = r;
    if(r < X)
    {
        *count = *count + 1;
    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, largest, count);
    }
}

//Heap Sort
void HeapSort()
{
    int min = 100, max = 0, count = 0, avg = 0;
    for(int i = 0; i < Y; i++)
    {
        for (int j = 1; j >= 0; j--)
        {
            heapify(P5[i], j, &count);
        }
        for (int k = 4; k > 0; k--)
        {
            swap(&P5[i][0], &P5[i][k]);
            heapify(P5[i], k, &count);
        }

        avg = avg + count;

        if(count < min)
        {
            min = count;
        }

        if(max < count)
        {
            max = count;
        }

        count = 0;
    }

    avg = avg / Y;

    printf("\nHeap Sort");
    display(min, max, avg);
}

//Insertion Sort
void InsertionSort()
{
    int count = 0, max = 0, min = 100, avg = 0;
    int key;

    for(int i = 0; i < Y; i++)
    {
        for (int j = 1; j < X; j++)
        {
            key = P5[i][j];
            int k = j - 1;

            while (k >= 0 && P5[i][k] > key)
            {
                count++;
                avg++;
                P5[i][k + 1] = P5[i][k];
                k = k - 1;
            }
            if(k >= 0)
            {
                count++;
                avg++;
            }
            P5[i][k + 1] = key;
        }

        if(count < min)
        {
            min = count;
        }

        if(max < count)
        {
            max = count;
        }

        count = 0;
    }
    avg = avg / Y;
    printf("\nInsertion Sort");
    display(min, max, avg);
}

int partitie(int arr[], int low, int high, int *count)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);

    // Swap A[random] with A[high]
    swap(&arr[random], &arr[low]);

    return partition(arr, low, high, count);
}

int partition (int arr[], int low, int high, int *count)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        *count = *count + 1;
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickie(int arr[], int low, int high, int *count)
{
    if (low < high)
    {
        int pi = partitie(arr, low, high, count);
        quickie(arr, low, pi - 1, count);
        quickie(arr, pi + 1, high, count);
    }
}

//Quick Sort
void QuickSort()
{
    int count = 0, min = 100, max = 0, avg = 0;

    for(int i = 0; i < Y; i++)
    {
        count = 0;

        quickie(P5[i], 0, X-1, &count);

        avg = avg + count;

        if(count < min)
        {
            min = count;
        }

        if(max < count)
        {
            max = count;
        }
    }

    avg = avg / Y;

    printf("\nQuick Sort");
    display(min, max, avg);
}

//Merges two array to form one sorted array
void merge(int arr[], int l, int m, int r, int *count)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        *count = *count + 1;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }

        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

//Merge sort on each row of the permutation matrix
void mergeie(int arr[], int l, int r, int *count)
{
    if (l < r)
    {
        //mid element
        int m = (l + r) / 2;

        //Sort first and second halves
        mergeie(arr, l, m, count);
        mergeie(arr, m + 1, r, count);

        merge(arr, l, m, r, count);
    }
}

void MergeSort()
{
    int count = 0, max = 0, min = 100, avg = 0;

    for(int i = 0; i < Y; i++)
    {
        count = 0;

        mergeie(P5[i], 0, X-1, &count);

        avg = avg + count;

        if(count < min)
        {
            min = count;
        }

        if(max < count)
        {
            max = count;
        }
    }

    avg = avg / Y;

    printf("\nMerge Sort");
    display(min, max, avg);
}

//Driver Code
int main()
{
    int flag = 0;
    int arr[] = {43, 65, 75, 21, 29};
    while(flag != 6)
    {
        printf("Choose the sort you want to perform: ");
        printf("\n1. Bubble Sort");
        printf("\n2. Heap Sort");
        printf("\n3. Insertion Sort");
        printf("\n4. Quick Sort");
        printf("\n5. Merge Sort");
        printf("\n6. Exit\n");

        scanf("%d", &flag);
        switch(flag)
        {
            case 1:
            length = -1;
            generator(arr, 0, X);
            BubbleSort();
            break;

            case 2:
            length = -1;
            generator(arr, 0, X);
            HeapSort();
            break;

            case 3:
            length = -1;
            generator(arr, 0, X);
            InsertionSort();
            break;

            case 4:
            length = -1;
            generator(arr, 0, X);
            QuickSort();
            break;

            case 5:
            length = -1;
            generator(arr, 0, X);
            MergeSort();
            break;

            default:
            if(flag != 6)
            {
                printf("\nWrong Input\n");
            }
        }
    }

    return 0;
}
