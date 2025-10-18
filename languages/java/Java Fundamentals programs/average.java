import java.util.Scanner;
import javax.swing.JOptionPane;

public class average{
    public static void main(String[] args) {
        int total=0;
        int avg;

        for(int x=0; x<=9;x++){
        String mark= JOptionPane.showInputDialog(null,"Enter Mark:");
            //total+=mark;
        }
        avg=total/10;
        JOptionPane.showMessageDialog(null, avg);
    }
}