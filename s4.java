/*Write a program to enter a string and display the piglatin form of each word
 krishna->ishnakray
 break from vowel
   */
  import java.util.*;
  class s4
  {
      public static void main()
      {
          Scanner in=new Scanner(System.in);
          System.out.println("Enter the string");
          String s=in.nextLine()+" ".toLowerCase();String w="";String pig="";
          for(int i=0;i<s.length();i++)
          {if(s.charAt(i)==' ')
              {     int ind=0;
                    for(int j=0;j<w.length();j++)
                    {if(w.charAt(j)=='a'||w.charAt(j)=='e'||w.charAt(j)=='i'||w.charAt(j)=='o'||w.charAt(j)=='u')
                    {   ind=1;
                      pig=pig+w.substring(j)+w.substring(0,j)+"ay ";
                      break;}}
                    if(ind==0)
                    pig=pig+w+"ay ";
                    w="";}
           else
            w=w+s.charAt(i);}
            System.out.print(pig);}}
