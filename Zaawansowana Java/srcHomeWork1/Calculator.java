import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Calculator extends JFrame implements ActionListener {

    private final JTextField display = new JTextField("0");
    private double result = 0.0;
    private String pendingOp = "=";
    private boolean startNumber = true;

    public Calculator() {
        super("Kalkulator");
        createUI();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setResizable(false);
        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    private void createUI() {
        display.setEditable(false);
        display.setHorizontalAlignment(SwingConstants.RIGHT);
        display.setFont(display.getFont().deriveFont(Font.BOLD, 24f));
        display.setPreferredSize(new Dimension(240, 40));

        JPanel grid = new JPanel(new GridLayout(4, 4, 4, 4));
        String[] keys = {
                "1", "2", "3", "+",
                "4", "5", "6", "-",
                "7", "8", "9", "*",
                "0", "C", ".", "/"
        };
        for (String k : keys) {
            addButton(grid, k);
        }

        JPanel bottom = new JPanel(new GridLayout(1, 2, 4, 4));
        addButton(bottom, "+/-");
        addButton(bottom, "=");

        JPanel main = new JPanel(new BorderLayout(4, 4));
        main.setBorder(BorderFactory.createEmptyBorder(8, 8, 8, 8));
        main.add(display, BorderLayout.NORTH);
        main.add(grid,     BorderLayout.CENTER);
        main.add(bottom,   BorderLayout.SOUTH);
        setContentPane(main);
    }

    private void addButton(JPanel panel, String label) {
        JButton b = new JButton(label);
        b.setFont(b.getFont().deriveFont(Font.PLAIN, 18f));
        b.addActionListener(this);
        panel.add(b);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String cmd = e.getActionCommand();

        if ("0123456789.".contains(cmd)) {
            if (startNumber) {
                display.setText(cmd.equals(".") ? "0." : cmd);
                startNumber = false;
            } else if (!(cmd.equals(".") && display.getText().contains("."))) {
                display.setText(display.getText() + cmd);
            }
        } else if ("+-*/=".contains(cmd)) {
            calculate(Double.parseDouble(display.getText()));
            pendingOp = cmd;
            startNumber = true;
        } else if (cmd.equals("C")) {
            result = 0.0;
            pendingOp = "=";
            display.setText("0");
            startNumber = true;
        } else if (cmd.equals("+/-")) {
            if (!display.getText().equals("0")) {
                double val = Double.parseDouble(display.getText()) * -1;
                display.setText(format(val));
            }
        }
    }

    private void calculate(double x) {
        switch (pendingOp) {
            case "+" -> result += x;
            case "-" -> result -= x;
            case "*" -> result *= x;
            case "/" -> result = x == 0 ? Double.NaN : result / x;
            case "=" -> result = x;
        }
        display.setText(format(result));
    }

    private String format(double v) {
        if (Double.isNaN(v) || Double.isInfinite(v)) return "BŁĄD";
        String s = String.valueOf(v);
        if (s.endsWith(".0"))
            return s.substring(0, s.length() - 2);
        return s;
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Calculator::new);
    }
}
