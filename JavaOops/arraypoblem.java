public class arraypoblem {
    public static void main(String args[]){
        //arraylist a = new arraylist();
        int[] arr = {1,9,4,2,6,3,5};
        int n = arr.length/2;
        int l = arr.length;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1-i;j++){
                if(arr[j]>arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        int k=0;
        for(int i=n;i<l-1;i++){
            for(int j=n;j<l-1-k;j++){
                if(arr[j]<arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
            k++;
        }
        for(int i=0;i<l;i++){
            System.out.print(arr[i]+" ");
        }
    }
}
