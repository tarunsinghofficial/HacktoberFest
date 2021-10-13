
package java_Programs_for_beginners;

/**
 *
 * @author zam
 */
public class Array1D {
    public static void main(String[] args) {
        
    //membut array
    int []dataArray = {10 , 20 , 30 , 40};
    String[] dataString={"i" , "learning","java","oop"};
    
    for(int i=0 ; i < dataArray.length ; i++){
        System.out.println(dataArray[i]);
    }
    for(int i =0 ; i < dataString.length ; i ++){
        System.out.print(dataString[i]);     
        System.out.print(" ");
    }
   
    }
}
