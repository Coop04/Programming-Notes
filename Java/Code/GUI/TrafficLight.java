import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class TrafficLight extends JPanel implements ActionListener {
    JRadioButton r1,r2,r3;
    Color red_c,yellow_c,green_c;
    public TrafficLight() {
        setBounds(0,0,700,500);

        r1=new JRadioButton("RED");
        r2=new JRadioButton("YELLOW");
        r3=new JRadioButton("Green");
        r1.setSelected(true);
        red_c=Color.red;
        yellow_c=getBackground();
        green_c=getBackground();
        ButtonGroup g=new ButtonGroup();
        g.add(r1);
        g.add(r2);
        g.add(r3);

        add(r1);
        add(r2);
        add(r3);

        r1.addActionListener(this);
        r2.addActionListener(this);
        r3.addActionListener(this);
    }
    public void actionPerformed(ActionEvent e) {
        if(r1.isSelected()==true) {
            red_c=Color.red;
            yellow_c=getBackground();
            green_c=getBackground();
        }
        else if(r2.isSelected()==true) {
            red_c=getBackground();
            yellow_c=Color.yellow;
            green_c=getBackground();
        }
        else {
            red_c=getBackground();
            yellow_c=getBackground();
            green_c=Color.green;
        }
        repaint();
    }
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.drawOval(50,50,50,50);
        g.drawOval(50,150,50,50);
        g.drawOval(50,250,50,50);

        g.setColor(red_c);
        g.fillOval(50,50,50,50);
        g.setColor(yellow_c);
        g.fillOval(50,150,50,50);
        g.setColor(green_c);
        g.fillOval(50,250,50,50);
    }
    public static void main(String args[]) {
        JFrame f=new JFrame();
        f.setSize(700,500);
        f.setVisible(true);
        f.setLayout(null);

        TrafficLight t=new TrafficLight();
        f.add(t);
    }
}