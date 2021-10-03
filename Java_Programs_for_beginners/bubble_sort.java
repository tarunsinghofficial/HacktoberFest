class Bubble {
    void Sort(int array[]) {
        int n = array.length;
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (array[j] > array[j + 1]) {

                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;// swapping temp and array
                }
    }


    void printarrayay(int array[])//to print the array
    {
        int n = array.length;
        for (int i = 0; i < n; ++i)
            System.out.print(array[i] + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        BubbleSort obj = new BubbleSort();
        int array[] = {645, 67, 56, 32, 76, 90, 83, 73, 32, 12, 34};
        obj.bubbleSort(array);
        System.out.println("Array Sorted successfully");
        obj.printarray(array);
    }
}
