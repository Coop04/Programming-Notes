import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SimpleCalculator extends JFrame implements ActionListener {
    private JTextField display;
    private JButton[] digitButtons;
    private JButton[] operationButtons;
    private JButton equalsButton;
    private JButton clearButton;
    private String currentInput;
    private double result;
    private String lastOperation;

    public SimpleCalculator() {
        setTitle("Simple Calculator");
        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        display = new JTextField();
        display.setEditable(false);
        add(display, BorderLayout.NORTH);

        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(4, 4));

        digitButtons = new JButton[10];
        for (int i = 0; i < 10; i++) {
            digitButtons[i] = new JButton(String.valueOf(i));
            digitButtons[i].addActionListener(this);
            buttonPanel.add(digitButtons[i]);
        }

        operationButtons = new JButton[5];
        String[] operationSymbols = {"+", "-", "*", "/", "%"};
        for (int i = 0; i < operationButtons.length; i++) {
            operationButtons[i] = new JButton(operationSymbols[i]);
            operationButtons[i].addActionListener(this);
            buttonPanel.add(operationButtons[i]);
        }

        equalsButton = new JButton("=");
        equalsButton.addActionListener(this);
        buttonPanel.add(equalsButton);

        clearButton = new JButton("C");
        clearButton.addActionListener(this);
        buttonPanel.add(clearButton);

        add(buttonPanel, BorderLayout.CENTER);

        currentInput = "";
        result = 0.0;
        lastOperation = "";
    }

    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();

        if (Character.isDigit(command.charAt(0))) {
            currentInput += command;
            display.setText(currentInput);
        } else if (command.equals("C")) {
            currentInput = "";
            display.setText("");
        } else if (command.equals("=")) {
            try {
                double input = Double.parseDouble(currentInput);
                if (lastOperation.equals("+")) {
                    result += input;
                } else if (lastOperation.equals("-")) {
                    result -= input;
                } else if (lastOperation.equals("*")) {
                    result *= input;
                } else if (lastOperation.equals("/")) {
                    if (input == 0) {
                        throw new ArithmeticException("Cannot divide by zero");
                    }
                    result /= input;
                } else if (lastOperation.equals("%")) {
                    result %= input;
                } else {
                    result = input;
                }
                display.setText(String.valueOf(result));
                currentInput = "";
            } catch (NumberFormatException ex) {
                display.setText("Invalid input");
            } catch (ArithmeticException ex) {
                display.setText("Error: " + ex.getMessage());
            }
        } else {
            lastOperation = command;
            result = Double.parseDouble(currentInput);
            currentInput = "";
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            SimpleCalculator calculator = new SimpleCalculator();
            calculator.setVisible(true);
        });
    }
}