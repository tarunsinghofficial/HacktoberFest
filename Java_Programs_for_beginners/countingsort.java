import java.util.Arrays;

class countingsort
{
    void countingsort(int arr[])
    {
        int max= Arrays.stream(arr).max().getAsInt() ;
        int min=Arrays.stream(arr).min().getAsInt() ;
        int range=max-min+1;
        int count[]=new int[range];
        int len=arr.length;
        for (int i=0;i<len;i++) {
            count[arr[i]-min]++;

        }
        for (int i=1;i<range;i++)
        {
            count[i]+=count[i-1];
        }
        int answer[]=new int[len];
        for (int i=len-1;i>=0;i--)
        {
            answer[count[arr[i]-min]-1]=arr[i];
            count[arr[i]-min]--;
        }
        for (int ele:answer)
        {
            System.out.print(ele+" ");
        }
    }
    public static void main(String[] args) {
        int arr[]=new int[]{5,3,7,1,10};
        countingsort count=new countingsort();
        count.countingsort(arr);
    }
}