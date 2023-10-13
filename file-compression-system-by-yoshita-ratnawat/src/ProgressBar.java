import java.awt.event.*;
import javax.swing.*;

public class ProgressBar extends JFrame {
    Thread t;
    private JPanel jPanel1;
    private JProgressBar jProgressBar1;
    private ProgressBar ref = this;

    public ProgressBar() {
        initComponents();
        t = new pbThread(jProgressBar1);
        addWindowListener(new MyWindow());
        setTitle("Please wait");
        setLocationRelativeTo(null);
    }

    private class MyWindow extends WindowAdapter {
        public void windowOpened(WindowEvent e) {
            t.start();
        }
    }

    private class pbThread extends Thread {
        JProgressBar bar;

        pbThread(JProgressBar b) {
            bar = b;
        }

        public void run() {
            int min = 0;
            int max = 50;
            bar.setMinimum(min);
            bar.setMaximum(max);
            bar.setValue(0);

            for (int i = min; i < max; i++) {
                bar.setValue(i);
                try {
                    t.sleep(50);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            JOptionPane.showMessageDialog(null, "Compressed File saved succefully");
            ref.dispose();
        }
    }


    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jProgressBar1 = new javax.swing.JProgressBar();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jPanel1.setBackground(new java.awt.Color(31, 40, 51));

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
                jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(jProgressBar1, javax.swing.GroupLayout.DEFAULT_SIZE, 508, Short.MAX_VALUE)
        );
        jPanel1Layout.setVerticalGroup(
                jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(jPanel1Layout.createSequentialGroup()
                                .addGap(28, 28, 28)
                                .addComponent(jProgressBar1, javax.swing.GroupLayout.DEFAULT_SIZE, 43, Short.MAX_VALUE)
                                .addGap(38, 38, 38))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }
}