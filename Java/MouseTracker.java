import java.awt.event.*;
import javax.swing.*;

public class MouseTracker extends JFrame implements MouseListener, MouseMotionListener {
    MouseTracker() {
        setTitle("Mouse Tracker");
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        addMouseListener(this);
        addMouseMotionListener(this);
        setVisible(true);
    }

    public static void main(String[] args) {
        new MouseTracker();
    }

    // MouseListener methods
    public void mouseClicked(MouseEvent e) {
        System.out.println("Mouse Clicked at: (" + e.getX() + ", " + e.getY() + ")");
    }

    public void mousePressed(MouseEvent e) {
        System.out.println("Mouse Pressed at: (" + e.getX() + ", " + e.getY() + ")");
    }

    public void mouseReleased(MouseEvent e) {
        System.out.println("Mouse Released at: (" + e.getX() + ", " + e.getY() + ")");
    }

    public void mouseEntered(MouseEvent e) {
        System.out.println("Mouse Entered at: (" + e.getX() + ", " + e.getY() + ")");
    }

    public void mouseExited(MouseEvent e) {
        System.out.println("Mouse Exited at: (" + e.getX() + ", " + e.getY() + ")");
    }

    // MouseMotionListener methods
    public void mouseDragged(MouseEvent e) {
        System.out.println("Mouse Dragged at: (" + e.getX() + ", " + e.getY() + ")");
    }

    public void mouseMoved(MouseEvent e) {
        System.out.println("Mouse Moved at: (" + e.getX() + ", " + e.getY() + ")");
    }
}
