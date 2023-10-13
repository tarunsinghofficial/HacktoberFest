import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;

public class EncoderGUI extends JFrame {
    private static HuffmanEncoder encoder;
    private static Message msg;
    private static boolean hasBeenCompressed = false;
    private static boolean fileCompressed = false;
    private String src = new String(), dst = new String();
    private JPanel jPanel1;
    private JButton[] allButtons;
    private JButton compressButton, compressedSizeButton, compressionRatioButton,
                    decompressButton, displayButton, displayButton1, huffCodeButton,
                    jButton4, openButton, openButton1, originalCodeButton, saveFileButton,
                    showSizeButton, showBytes, compressBits, compBytes;
    private JLabel introLabel, jLabel1, jLabel2, jLabel3;
    private JTextField jTextField2, jTextField3, jTextField4;

    public EncoderGUI() {
        initComponents();
        setTitle("Huffman Encoding App");
        addWindowListener(new WindowListener());
        this.setLocationRelativeTo(null);
        JButton[] buttonArray = { compressButton, compressedSizeButton,
                compressionRatioButton, huffCodeButton, showSizeButton,
                originalCodeButton, openButton, saveFileButton,
                displayButton, openButton1, showBytes, decompressButton,
                compressBits, compBytes };

        for(JButton b : buttonArray) {
            if(b == originalCodeButton)
                b.setFont(new Font("Serif", Font.ITALIC, 14));
            else if(b == compressButton || b == decompressButton || b == compressBits) {
                b.setFont(new Font("Serif", Font.ITALIC, 20));
            }
            else if(b == openButton || b == saveFileButton ||
                    b == displayButton)
                b.setFont(new Font("Serif", Font.ITALIC, 16));
            else
                b.setFont(new Font("Serif", Font.ITALIC, 16));
            b.setBackground(new Color(0, 140, 186));
            b.setForeground(new Color(255, 255, 255));
            b.setFocusable(false);
        }
        compressionRatioButton.setFont(new Font("Serif", Font.ITALIC, 14));
        setResizable(false);
    }
    
    private class WindowListener extends WindowAdapter {
        public void windowOpened(WindowEvent e) {
              ThreadedText thread = new ThreadedText("Huffman Encoder", introLabel);
              thread.t.start(); 
        }
    }

    private void openButtonActionPerformed(ActionEvent evt) {
        JFileChooser fchooser = new JFileChooser();
        fchooser.showOpenDialog(null);
        if(fchooser.getSelectedFile() != null) {
            File f0 = fchooser.getSelectedFile();
            String filename = f0.getAbsolutePath();
            jTextField2.setText(filename);
            if(f0.exists() && filename.substring(filename.length()-3, filename.length()).equals("txt")) {
                msg = new Message(convertFileToString(f0));
            }
        }
    }

    private void displayButtonActionPerformed(ActionEvent evt) {
        if(!jTextField2.getText().isEmpty()) {
            try {
                String pathfile = jTextField2.getText();
                File f = new File(pathfile);
                if(f.exists()) {
                    BufferedReader bufReader = new BufferedReader(new FileReader(f));
                    String str = new String();
                    Displayer area = new Displayer();
                    while((str = bufReader.readLine()) != null) {
                        area.displayArea.append(str + '\n');
                    }
                }
            } catch(IOException io) {
                JOptionPane.showMessageDialog(null, "Invalid File", "Error", JOptionPane.ERROR_MESSAGE);
            }
        } else {
            JOptionPane.showMessageDialog(null, "Please fill the text field", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void compressionRatioButtonActionPerformed(ActionEvent evt) {
        if(hasBeenCompressed)
            JOptionPane.showMessageDialog(null, "Compression done: " +
                    String.format("%.4f", encoder.howMuchCompressed()) + "%");
        else
            JOptionPane.showMessageDialog(null, "No compression has taken place", "ERROR"
                    , JOptionPane.ERROR_MESSAGE);
    }

    private void compressButtonActionPerformed(ActionEvent evt) {
        if(dst.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Please specify a location to save compressed file");
            return;
        }
        new ProgressBar().setVisible(true);
        HuffCompression.compress(src, dst);
        fileCompressed = true;
    }

    private void originalCodeButtonActionPerformed(ActionEvent evt) {
        if(ensureValidityOfPath())
            new OrgCode().setVisible(true);
        else
            JOptionPane.showMessageDialog(null, "Invalid Path", "ERROR"
                    ,JOptionPane.ERROR_MESSAGE);
    }

    private void huffCodeButtonActionPerformed(ActionEvent evt) {
        if(hasBeenCompressed)
            new HuffCode().setVisible(true);
        else
            JOptionPane.showMessageDialog(null, "No compression has taken place", "ERROR"
                    , JOptionPane.ERROR_MESSAGE);
    }

    private void showSizeButtonActionPerformed(ActionEvent evt) {
        if(ensureValidityOfPath())
            JOptionPane.showMessageDialog(null, "Size: " + msg.getSize() + "bits", "Original Size",
                    JOptionPane.INFORMATION_MESSAGE);
        else
            JOptionPane.showMessageDialog(null, "Invalid Path", "ERROR"
                    ,JOptionPane.ERROR_MESSAGE);
    }

    private void compressedSizeButtonActionPerformed(ActionEvent evt) {
        if(hasBeenCompressed) {
            JOptionPane.showMessageDialog(null, "Compressed Size: " + encoder.getSizeOfSequence()
                    + "bits", "Compressed Size", JOptionPane.INFORMATION_MESSAGE);
        } else {
            JOptionPane.showMessageDialog(null, "No compression has taken place", "ERROR"
                    ,JOptionPane.ERROR_MESSAGE);
        }
    }

    private void saveFileButtonActionPerformed(ActionEvent evt) {
        if(!jTextField2.getText().isEmpty()) {
            JFileChooser chooser = new JFileChooser();
            chooser.setDialogTitle("Specify a path");
            int userSelection = chooser.showSaveDialog(this);
            if(userSelection == 0) {
                src = jTextField2.getText();
                dst = chooser.getSelectedFile().getAbsolutePath();
                jTextField3.setText(dst);
            }
        } else
            JOptionPane.showMessageDialog(null, "No file has been selected", "ERROR"
                    ,JOptionPane.ERROR_MESSAGE);
    }

    private void openButton1ActionPerformed(ActionEvent evt) {
        JFileChooser fchooser = new JFileChooser();
        fchooser.showOpenDialog(null);
        File f0 = null;
        if(fchooser.getSelectedFile() != null) {
            f0 = fchooser.getSelectedFile();
            jTextField4.setText(f0.getAbsolutePath());
        } else {
            JOptionPane.showMessageDialog(null, "Invalid file or directory", "ERROR"
                    ,JOptionPane.ERROR_MESSAGE);
        }
    }


    private void displayButton1ActionPerformed(ActionEvent evt) {
        if(!jTextField4.getText().isEmpty()) {
            try {
                String pathfile = jTextField4.getText();
                File f = new File(pathfile);
                if(f.exists()) {
                    BufferedReader bufReader = new BufferedReader(new FileReader(f));
                    String str = new String();
                    Displayer area = new Displayer();
                    while((str = bufReader.readLine()) != null) {
                        area.displayArea.append(str + '\n');
                    }
                }
            } catch(IOException io) {
                JOptionPane.showMessageDialog(null, "Invalid File", "Error", JOptionPane.ERROR_MESSAGE);
            }
        } else {
            JOptionPane.showMessageDialog(null, "Please fill the text field", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void decompressButtonActionPerformed(ActionEvent evt) {
        String path = jTextField4.getText();
        if(!path.isEmpty()) {
            File f = new File(path);
            String ext;
            int i;
            for(i = path.length()-1; i >= 0 ; i--) {
                if(path.charAt(i) == '.') break;
            }
            ext = path.substring(i, path.length());
            System.out.println(ext);
            String dir = f.getParent() + "\\decompressed" + ext;
            HuffCompression huffCompression = new HuffCompression();
            huffCompression.decompress(path, dir);
            JOptionPane.showMessageDialog(null, "File has been decompressed and saved at" +
                    " the location: " + dir);
        } else JOptionPane.showMessageDialog(null, "no file has been selected for decompression");
    }

    private static class HuffCode extends JFrame {
        JTable codes;
        JScrollPane scrlPane;
        String[] headings = {"Character", "Frequency", "Bit Sequence"};

        HuffCode() {
            setTable();
            setSize(600, 550);
            setTitle("Huff Code");
            setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
            setLocationRelativeTo(null);
        }

        public void setTable() {
            CharLinkedList charset = encoder.get_charset();
            String[][] records = new String[charset.size()][headings.length];
            CharNode node = charset.getLink();
            for(int i = 0; i < charset.size(); i++) {
                if(node != null) {
                    records[i][0] = node.ch + "";
                    records[i][1] = Integer.toString(node.frequency);
                    records[i][2] = node.bit_size;
                }
                node = node.next;
            }
            codes = new JTable(records, headings);
            codes.setEnabled(false);
            scrlPane = new JScrollPane(codes);
            add(scrlPane);
        }
    }

    private static class OrgCode extends JFrame {
        JTable codes;
        JScrollPane scrlPane;
        String[] headings = {"Character", "Frequency", "Bit Sequence"};

        OrgCode() {
            setTable();
            setSize(600, 550);
            setTitle("Original Code");
            setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
            setLocationRelativeTo(null);
        }

        public void setTable() {
            String[][] records = new String[msg.getCharacters().length][headings.length];
            char[] chars = msg.getCharacters();
            for(int i = 0; i < chars.length; i++) {
                records[i][0] = chars[i] + "";
                records[i][1] = Integer.toString(msg.calcFrequencyOfChar(chars[i]));
                records[i][2] = msg.convertBinary(i);
            }
            codes = new JTable(records, headings);
            codes.setEnabled(false);
            scrlPane = new JScrollPane(codes);
            add(scrlPane);
        }
    }

    private boolean ensureValidityOfPath() {
        String path = jTextField2.getText();
        return !path.isEmpty() && new File(path).exists();
    }

    private String convertFileToString(File f0) {
        String str, contents = "";
        boolean first = true;
        try {
            BufferedReader bufReader = new BufferedReader(new FileReader(f0));
            while((str = bufReader.readLine()) != null) {
                if(!first) contents += '\n';
                contents += str;
                first = false;
            }
        } catch(IOException e) {
            e.printStackTrace();
        }
        return contents;
    }

    private void showBytesActionPerformed(ActionEvent evt) {
        if(!jTextField2.getText().isEmpty()) {
            File f = new File(jTextField2.getText());
            JOptionPane.showMessageDialog(null, "Current Size: " + (f.length() * 0.001) + " KB");
        } else {
            JOptionPane.showMessageDialog(null, "No file has been selected");
        }
    }

    private void compBytesActionPerformed(ActionEvent evt) {
        if(!jTextField3.getText().isEmpty() && fileCompressed) {
            File f = new File(jTextField3.getText());
            JOptionPane.showMessageDialog(null, "Compressed Size: " + (f.length() * 0.001) + " KB");
        } else {
            JOptionPane.showMessageDialog(null, "No file has been selected");
        }
    }

    private void compressBitsActionPerformed(ActionEvent evt) {
        if(!ensureValidityOfPath())
            JOptionPane.showMessageDialog(null, "Invalid Path", "ERROR",
                    JOptionPane.ERROR_MESSAGE);
        else {
            File f0 = new File(jTextField2.getText());
            String contents = convertFileToString(f0);
            encoder = new HuffmanEncoder(new Message(contents));
            encoder.compress();
            hasBeenCompressed = true;
            JOptionPane.showMessageDialog(null, "Compression done succesfully");
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new EncoderGUI().setVisible(true);
            }
        });
    }

    /*
     * ALL THE GUI CODE IS INSIDE initComponents() Method
     */
    private void initComponents() {

        jButton4 = new JButton();
        jPanel1 = new JPanel();
        jLabel1 = new JLabel();
        jTextField2 = new JTextField();
        openButton = new JButton();
        compressButton = new JButton();
        showSizeButton = new JButton();
        huffCodeButton = new JButton();
        displayButton = new JButton();
        compressionRatioButton = new JButton();
        originalCodeButton = new JButton();
        compressedSizeButton = new JButton();
        jTextField3 = new JTextField();
        saveFileButton = new JButton();
        jLabel2 = new JLabel();
        introLabel = new JLabel();
        jTextField4 = new JTextField();
        jLabel3 = new JLabel();
        openButton1 = new JButton();
        displayButton1 = new JButton();
        decompressButton = new JButton();
        compressBits = new javax.swing.JButton();
        showBytes = new javax.swing.JButton();
        compBytes = new javax.swing.JButton();

        jButton4.setText("jButton2");

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jPanel1.setBackground(new java.awt.Color(31, 40, 51));

        jLabel1.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(255, 255, 255));
        jLabel1.setText("Select a File To Compress:");

        openButton.setText("Browse");
        openButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                openButtonActionPerformed(evt);
            }
        });

        compressButton.setFont(new java.awt.Font("Tahoma", 1, 13)); // NOI18N
        compressButton.setText("Compress");
        compressButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                compressButtonActionPerformed(evt);
            }
        });

        showSizeButton.setText("Show Original Size");
        showSizeButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                showSizeButtonActionPerformed(evt);
            }
        });

        huffCodeButton.setText("Huff Code");
        huffCodeButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                huffCodeButtonActionPerformed(evt);
            }
        });

        displayButton.setText("Show Contents");
        displayButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                displayButtonActionPerformed(evt);
            }
        });

        compressionRatioButton.setText("Compression Bit Ratio");
        compressionRatioButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                compressionRatioButtonActionPerformed(evt);
            }
        });

        originalCodeButton.setText("Original Code");
        originalCodeButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                originalCodeButtonActionPerformed(evt);
            }
        });

        compressedSizeButton.setText("Compressed Size");
        compressedSizeButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                compressedSizeButtonActionPerformed(evt);
            }
        });

        saveFileButton.setText("Save");
        saveFileButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                saveFileButtonActionPerformed(evt);
            }
        });

        jLabel2.setFont(new java.awt.Font("Tahoma", 0, 14));
        jLabel2.setForeground(new java.awt.Color(255, 255, 255));
        jLabel2.setText("Specify a Location to Save a Compressed File:");

        introLabel.setFont(new java.awt.Font("Tahoma", 1, 24));
        introLabel.setForeground(new java.awt.Color(240, 240, 240));
        introLabel.setText("");


        jLabel3.setFont(new java.awt.Font("Tahoma", 0, 14));
        jLabel3.setForeground(new java.awt.Color(255, 255, 255));
        jLabel3.setText("Select a File To Decompress:");

        openButton1.setText("Browse");
        openButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                openButton1ActionPerformed(evt);
            }
        });

        decompressButton.setFont(new java.awt.Font("Tahoma", 1, 13)); // NOI18N
        decompressButton.setText("Decompress");
        decompressButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                decompressButtonActionPerformed(evt);
            }
        });

        compressBits.setFont(new java.awt.Font("Tahoma", 1, 13)); // NOI18N
        compressBits.setText("Compress Bits");
        compressBits.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                compressBitsActionPerformed(evt);
            }
        });

        showBytes.setFont(new java.awt.Font("Tahoma", 1, 13)); // NOI18N
        showBytes.setText("View Size");
        showBytes.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                showBytesActionPerformed(evt);
            }
        });

        compBytes.setFont(new java.awt.Font("Tahoma", 1, 13)); // NOI18N
        compBytes.setText("CompSize");
        compBytes.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                compBytesActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
                jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(jPanel1Layout.createSequentialGroup()
                                .addContainerGap()
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addGroup(jPanel1Layout.createSequentialGroup()
                                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                        .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 384, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 261, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                .addGap(0, 0, Short.MAX_VALUE))
                                        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                                        .addGroup(jPanel1Layout.createSequentialGroup()
                                                                .addComponent(compressedSizeButton)
                                                                .addGap(18, 18, 18)
                                                                .addComponent(showSizeButton)
                                                                .addGap(18, 18, 18)
                                                                .addComponent(originalCodeButton, javax.swing.GroupLayout.PREFERRED_SIZE, 123, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                .addGap(18, 18, 18)
                                                                .addComponent(huffCodeButton, javax.swing.GroupLayout.PREFERRED_SIZE, 123, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                .addGap(18, 18, 18)
                                                                .addComponent(compressionRatioButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                                        .addGroup(jPanel1Layout.createSequentialGroup()
                                                                .addComponent(jTextField2)
                                                                .addGap(18, 18, 18)
                                                                .addComponent(openButton, javax.swing.GroupLayout.PREFERRED_SIZE, 138, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                .addGap(18, 18, 18)
                                                                .addComponent(displayButton, javax.swing.GroupLayout.PREFERRED_SIZE, 144, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                        .addGroup(jPanel1Layout.createSequentialGroup()
                                                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                                        .addComponent(jTextField4)
                                                                        .addComponent(jTextField3))
                                                                .addGap(18, 18, 18)
                                                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                                                        .addComponent(saveFileButton, javax.swing.GroupLayout.PREFERRED_SIZE, 138, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                        .addComponent(openButton1, javax.swing.GroupLayout.PREFERRED_SIZE, 138, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                                .addGap(162, 162, 162)))
                                                .addGap(24, 24, 24))
                                        .addGroup(jPanel1Layout.createSequentialGroup()
                                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                                        .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 261, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addGroup(jPanel1Layout.createSequentialGroup()
                                                                .addComponent(compressButton, javax.swing.GroupLayout.PREFERRED_SIZE, 135, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                .addGap(18, 18, 18)
                                                                .addComponent(decompressButton, javax.swing.GroupLayout.PREFERRED_SIZE, 135, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                .addGap(18, 18, 18)
                                                                .addComponent(compressBits, javax.swing.GroupLayout.PREFERRED_SIZE, 193, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                                .addGap(18, 18, 18)
                                                                .addComponent(showBytes)
                                                                .addGap(18, 18, 18)
                                                                .addComponent(compBytes)))
                                                .addContainerGap(18, Short.MAX_VALUE))))
                        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(introLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 291, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(242, 242, 242))
        );
        jPanel1Layout.setVerticalGroup(
                jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                        .addGroup(jPanel1Layout.createSequentialGroup()
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                        .addGroup(jPanel1Layout.createSequentialGroup()
                                                .addGap(13, 13, 13)
                                                .addComponent(introLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 51, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addGap(18, 18, 18)
                                                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 29, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(jTextField2, javax.swing.GroupLayout.PREFERRED_SIZE, 31, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(openButton, javax.swing.GroupLayout.PREFERRED_SIZE, 31, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(displayButton, javax.swing.GroupLayout.PREFERRED_SIZE, 31, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 19, Short.MAX_VALUE)
                                                .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 29, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(jTextField4, javax.swing.GroupLayout.PREFERRED_SIZE, 31, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(openButton1, javax.swing.GroupLayout.PREFERRED_SIZE, 31, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                .addGap(18, 18, 18)
                                                .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 29, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(jTextField3, javax.swing.GroupLayout.PREFERRED_SIZE, 31, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(saveFileButton, javax.swing.GroupLayout.PREFERRED_SIZE, 31, javax.swing.GroupLayout.PREFERRED_SIZE))
                                                .addGap(80, 80, 80))
                                        .addGroup(jPanel1Layout.createSequentialGroup()
                                                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                                        .addComponent(compressButton, javax.swing.GroupLayout.PREFERRED_SIZE, 47, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(decompressButton, javax.swing.GroupLayout.PREFERRED_SIZE, 47, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(compressBits, javax.swing.GroupLayout.PREFERRED_SIZE, 47, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(showBytes, javax.swing.GroupLayout.PREFERRED_SIZE, 47, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                        .addComponent(compBytes, javax.swing.GroupLayout.PREFERRED_SIZE, 47, javax.swing.GroupLayout.PREFERRED_SIZE))))
                                .addGap(18, 18, 18)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                        .addComponent(compressedSizeButton)
                                        .addComponent(showSizeButton)
                                        .addComponent(originalCodeButton)
                                        .addComponent(huffCodeButton)
                                        .addComponent(compressionRatioButton))
                                .addContainerGap())
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
