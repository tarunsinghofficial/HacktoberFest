import javax.swing.JOptionPane;

public class dialogs{
    public static void main(String[] args) {
        String input = JOptionPane.showInputDialog(null, "Enter Number:");
        int num=Integer.parseInt(input);
        JOptionPane.showMessageDialog(null, num*num-23+21-num);
    }
}