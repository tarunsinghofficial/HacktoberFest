import java.util.Scanner;

public class array{
    public static void main(String[] args) {
        Scanner input =  new Scanner(System.in);
        String[] myArray=new String[5];
        String name;
        //System.out.println(myArray.length);

        for (int i=0;i<=myArray.length-1;i++){
            name=input.next();
            myArray[i]=name;
        }
        for (int i=0;i<=myArray.length-1;i++){
            System.out.println(myArray[i]);
        }

        //converting Integer list to int Array
		List<Integer> list = new ArrayList<>();
		list.add(3);
		list.add(90);
		list.add(80);
		System.out.println(list);
		
		Object[] arr=list.toArray();
		for(Object obj:arr) {
			System.out.println(obj);
		}
    }
}
