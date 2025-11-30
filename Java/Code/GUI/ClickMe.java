import javax.swing.*;
import java.awt.event.*;
class ClickMe extends JFrame implements ActionListener{
    JButton b;
    JLabel l;

    public ClickMe() {
        setSize(700,500);
        setLayout(null);

        b=new JButton("Click Me");
        b.setBounds(100,100,100,30);
        add(b);

        l=new JLabel("");
        l.setBounds(250,100,100,30);
        add(l);

        b.addActionListener(this);
    }
    public void actionPerformed(ActionEvent e) {
        l.setText("Clicked");
    }
    public static void main(String args[]) {
        ClickMe c=new ClickMe();
        c.setVisible(true);
    }
}