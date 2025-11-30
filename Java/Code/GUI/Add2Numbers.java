import javax.swing.*;
import java.awt.event.*;
public class Add2Numbers extends JFrame implements ActionListener {
    JLabel l1,l2,l3,r;
    JTextField t1,t2;//to read no. 1 and no. 2
    JButton b;//add
    public Add2Numbers() {
        setSize(700,400);
        setLayout(null);

        l1=new JLabel("Number 1");
        l2=new JLabel("Number 2");
        l3=new JLabel("Result");
        r=new JLabel("");
        t1=new JTextField();
        t2=new JTextField();
        b=new JButton("ADD");

        l1.setBounds(100,100,100,30);
        t1.setBounds(200,100,100,30);
        l2.setBounds(100,150,100,30);
        t2.setBounds(200,150,100,30);
        b.setBounds(150,200,100,30);
        l3.setBounds(100,250,100,30);
        r.setBounds(100,300,100,30);
        add(l1);
        add(t1);
        add(l2);
        add(t2);
        add(b);
        add(l3);
        add(r);

        b.addActionListener(this);
    }
    public void actionPerformed(ActionEvent e) {
        int n1=Integer.parseInt(t1.getText());
        int n2=Integer.parseInt(t2.getText());
        int n3=n1+n2;
        r.setText(String.valueOf(n3));
    }
    public static void main(String args[]) {
        Add2Numbers a=new Add2Numbers();
        a.setVisible(true);
    }
}