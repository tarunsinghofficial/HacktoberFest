package Basic_Java_Project;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.*;

public class Attendance {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter Total Class Strength");
        int n=s.nextInt();
        ArrayList<Integer> attendance=new ArrayList<>();
        for (int i = 1; i <=n; i++) {
            System.out.println("Roll number "+i);
            int temp=s.nextInt();  // enter 0 or 1
            if(temp==0 || temp==1){
                attendance.add(temp);
                continue;
            }
            else{
                i--;
                System.out.println("Invalid Action, Enter 0 or 1");
                continue;
            }

            
        }
        System.out.println();
        System.out.print("Attendance for Date ");
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");  
        LocalDateTime now = LocalDateTime.now();  
        System.out.println(dtf.format(now));  
        
        for (int i = 0; i < n; i++) {
            String ans;
            if(attendance.get(i)==0){
                ans="Absent";
            }
            else{
                ans="Present";
            }
            int j=i+1;
            System.out.println("Roll Number "+j+" "+ans);
        }
        s.close();
    }
}
