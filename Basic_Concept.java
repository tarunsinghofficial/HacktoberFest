import java.util.*;


class FirstClass{

    public static int printMyName(String name){
        System.out.println("Name is "+name);
        return 1;
    }

    public static void ArrayConcept(){
        //Declaration
        int arr[]=new int[4];
        int D2a[][]=new int[3][4];
        //int[] arr Both are correct
        // Java ke andr automatic initialisation hoti hai 0 or null means 0.0 values ke sath
        System.out.println("Enter array Elements");
        Scanner sc= new Scanner(System.in);
        /*for(int i=0;i<3;i++)
            for(int j=0;j<4;j++)
                D2a[i][j]=sc.nextInt();
        */
        System.out.println(arr.length);// LENGTH
        System.out.println(D2a.length);//Length of row
        System.out.println(D2a[0].length);//Length od column

        //Sorting
        //Arrays.sort(arr);
        //Arrays.toString(arr);

        /*
        String original = "edcba";
        char[] chars = original.toCharArray();
        Arrays.sort(chars);
        String sorted = new String(chars);
        System.out.println(sorted);
        */

    }

    public static void StringConcept(){
        String name="Suraj"+" "+"Singh";
        String name1="Suraj"+" "+"Singh";
        System.out.println("Your name is "+name);
        for(int i=0;i<name.length();i++){
            System.out.println(name.charAt(i));
        }
        //1- s1>s2 :+ve value
        //2- s1<s2 :-ve value
        //3- s1==s2 : zero return
        if(name1.compareTo(name)==0){
            System.out.println("Strings are equal");
        }

        if(new String("Tony")== new String("Tony")){  //Thats why use .compareTo not ==
            System.out.println("Equal");
        }else{
            System.out.println("Not Equal");
        }

        //substring(beg index,ending index)
        String s=name.substring(1, 7);
        System.out.println("Substring is "+s);

        //StringBuilder
        StringBuilder sb=new StringBuilder("Tony");
        //set char at index
        sb.setCharAt(0,'P');
        System.out.println(sb.toString());
        //sb.delete(2,3);
        //sb.insert(0,'d');
        //sb.append("s");
        //sb.length();


    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);  //For Taking input object is created
        String name=sc.nextLine();    //Taking Input
        //YE SAB BHI USE KAR SAKTE 
        //sc.nextInt();
        //sc.nextDouble();
        System.out.println(name);
        System.out.println("Hello World");
        System.out.println("New Function");
        //New Function
        String newName=sc.nextLine();
        int j=printMyName(newName);
        System.out.println("Returned value - "+j);
        System.out.println("Array  Concept");
        ArrayConcept();
        StringConcept();
    }




}