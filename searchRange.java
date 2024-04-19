public class searchRange {
    public static void main(String[] args) {
        int []arr={1,2,3,4,5,6,7,8};
        int target=6;
        System.out.println(searchRange(arr,target,2,6));


    }
    static int searchRange(int []arr,int target,int start,int end){
        if(arr.length==0){
            return -1;
        }
        for(int i=start;i<=end;i++){
            int element=arr[i];
            if(target==element){
                return i;
            }
        }
        return -1;

    }
}
