import javax.swing.*;

class myForm {

  //main method
  public static void main(String[] args) {
    //creating frame
    JFrame obj = new JFrame("Form using swing");

    //creating labels
    JLabel form = new JLabel("Sign Up Form");
    JLabel name = new JLabel("Name:");
    JLabel age = new JLabel("Age:");
    JLabel gender = new JLabel("Gender:");
    JLabel email = new JLabel("Email:");
    JLabel psw = new JLabel("Password:");
    JLabel cb = new JLabel("Select programming language you want to learn:-");

    //creating textfields
    JTextField name_t = new JTextField(20);
    JTextField age_t = new JTextField(20);
    JTextField email_t = new JTextField(20);
    //creating passwordfield
    JPasswordField psw_t = new JPasswordField(20);

    //creating radio buttons
    JRadioButton rb_m = new JRadioButton("Male");
    JRadioButton rb_f = new JRadioButton("Female");
    JRadioButton rb_o = new JRadioButton("Other");

    //creating checkboxes
    JCheckBox cb_c = new JCheckBox("C");
    JCheckBox cb_cpp = new JCheckBox("C++");
    JCheckBox cb_java = new JCheckBox("Java");
    JCheckBox cb_py = new JCheckBox("Python");
    //creating signup button
    JButton login = new JButton("Sign up");

    //setting bounds of each component
    form.setBounds(110, 10, 100, 15);
    name.setBounds(15, 35, 70, 25);
    name_t.setBounds(85, 35, 140, 25);
    age.setBounds(15, 65, 70, 25);
    age_t.setBounds(85, 65, 140, 25);
    gender.setBounds(15, 95, 70, 25);
    rb_m.setBounds(60, 95, 65, 25);
    rb_f.setBounds(125, 95, 70, 25);
    rb_o.setBounds(205, 95, 65, 25);
    email.setBounds(15, 125, 70, 25);
    email_t.setBounds(85, 125, 140, 25);
    psw.setBounds(15, 155, 70, 25);
    psw_t.setBounds(85, 155, 140, 25);
    cb.setBounds(15, 185, 300, 25);
    cb_c.setBounds(15, 205, 65, 25);
    cb_cpp.setBounds(15, 225, 65, 25);
    cb_java.setBounds(15, 245, 65, 25);
    cb_py.setBounds(15, 265, 70, 25);
    login.setBounds(100, 295, 100, 25);

    //adding components into frame
    obj.add(form);
    obj.add(name);
    obj.add(name_t);
    obj.add(age);
    obj.add(age_t);
    obj.add(gender);
    obj.add(rb_m);
    obj.add(rb_f);
    obj.add(rb_o);
    obj.add(email);
    obj.add(email_t);
    obj.add(psw);
    obj.add(psw_t);
    obj.add(cb);
    obj.add(cb_c);
    obj.add(cb_cpp);
    obj.add(cb_java);
    obj.add(cb_py);
    obj.add(login);

    //customizing frame
    obj.setSize(350, 380);
    obj.setLayout(null);
    obj.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //closing the JFrame
    obj.setVisible(true);
  }
}
