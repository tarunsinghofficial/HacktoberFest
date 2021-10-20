import java.awt.BorderLayout;
import javax.swing.JFrame;
import javax.swing.JLabel;
public class paint{
    public static void main(String[] args) {
        JFrame app =new JFrame("My App");
        PaintPanel pPanel = new PaintPanel();
        app.add(pPanel, BorderLayout.CENTER);
         // create a label and place it in SOUTH of BorderLayout
        app.add(new JLabel("Drag the mouse to draw"),BorderLayout.SOUTH);
        app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        app.setSize(400, 200);
        app.setVisible(true);
    }
}