// Java program for implementation of Insertion Sort 

class InsertionSort {
    /*Function to sort array using insertion sort*/
    void sort(int arr[]) {
        int n = arr.length;
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1; 
  
            /* Move elements of arr[0..i-1], that are 
               greater than key, to one position ahead 
               of their current position */
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    /* A utility function to print array of size n*/
    static void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");

        System.out.println();
    }

    // Driver method 
    public static void main(String args[]) {
        int arr[] = {12, 11, 13, 5, 6};

        InsertionSort ob = new InsertionSort();
        ob.sort(arr);

        printArray(arr);
    }
}


Example:
        12,11,13,5,6

        Let us loop for i=1(second element of the array)to 4(last element of the array)

        i=1.Since 11 is smaller than 12,move 12 and insert 11 before 12
        11,12,13,5,6

        i=2. 13 will remain at its position as all elements in A[0..I-1]are smaller than 13
        11,12,13,5,6

        i=3. 5 will move to the beginning and all other elements from 11 to 13 will move one position ahead of their current position.
        5,11,12,13,6

        i=4. 6 will move to position after 5,and elements from 11 to 13 will move one position ahead of their current position.
        5,6,11,12,13

