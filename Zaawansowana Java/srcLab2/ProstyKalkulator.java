import javax.swing.*;
import java.awt.*;

public class ProstyKalkulator {

    private JTextField pole1;
    private JTextField pole2;
    private JLabel wynik1;

    ProstyKalkulator() {
        inicjalizuj();
    }

    private void inicjalizuj() {
        this.pole1 = new JTextField();
        this.pole2 = new JTextField();
        this.wynik1 = new JLabel("???");

        JButton buttonPlus = new JButton("+");
        JButton buttonMinus = new JButton("-");
        JButton buttonMnozenie = new JButton("*");

        JFrame frame = new JFrame("ProstyKalkulator");
        frame.setSize(1000, 500);

        frame.setLayout(new FlowLayout());
        frame.add(new JLabel("Operator 1"));
        frame.add(pole1);
        frame.add(new JLabel("Operator 2"));
        frame.add(pole2);
        frame.add(new JLabel("Przycisk operacji"));
        frame.add(buttonPlus);
        frame.add(buttonMinus);
        frame.add(buttonMnozenie);
        frame.add(new JLabel("Wynik: "));
        frame.add(wynik1);


        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.setVisible(true);

    }
}
