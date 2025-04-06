import javax.swing.*;
import java.awt.*;

public class ZaawansowanyKalkulator {

    private JTextField pole1;
    private JTextField pole2;
    private JLabel wynik1;

    ZaawansowanyKalkulator() {
        inicjalizuj();
    }

    private void inicjalizuj() {
        this.pole1 = new JTextField(10);
        this.pole2 = new JTextField(10);
        this.wynik1 = new JLabel("???");

        ObliczListener obliczListener = new ObliczListener(pole1, pole2, wynik1);

        JButton buttonPlus = new JButton("+");
        JButton buttonMinus = new JButton("-");
        JButton buttonMnozenie = new JButton("*");

        buttonPlus.addActionListener(obliczListener);
        buttonMinus.addActionListener(obliczListener);
        buttonMnozenie.addActionListener(obliczListener);

        JFrame zaawansowanyKalkulator = new JFrame("ZaawansowanyKalkulator");
        zaawansowanyKalkulator.setSize(1000, 500);
        zaawansowanyKalkulator.setLayout(new GridLayout(3,3));

        zaawansowanyKalkulator.add(new JLabel("Operator 1"));
        zaawansowanyKalkulator.add(new JLabel("Operator 2"));
        zaawansowanyKalkulator.add(new JLabel("Wynik: "));

        zaawansowanyKalkulator.add(pole2);
        zaawansowanyKalkulator.add(pole1);
        zaawansowanyKalkulator.add(wynik1);

        zaawansowanyKalkulator.add(buttonPlus);
        zaawansowanyKalkulator.add(buttonMinus);
        zaawansowanyKalkulator.add(buttonMnozenie);

        zaawansowanyKalkulator.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        zaawansowanyKalkulator.setVisible(true);
    }
}
