import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ObliczListener implements ActionListener {

    private JTextField pole1;
    private JTextField pole2;
    private JLabel wynik;

    public ObliczListener(JTextField pole1, JTextField pole2, JLabel wynik1) {
        this.pole1 = pole1;
        this.pole2 = pole2;
        this.wynik = wynik1;
    }


    @Override
    public void actionPerformed(ActionEvent e) {
        e.getActionCommand();

        switch (e.getActionCommand()) {
            case "+":
                wynik.setText(String.valueOf(Integer.parseInt(pole1.getText()) + Integer.parseInt(pole2.getText())));
                break;
            case "-":
                wynik.setText(String.valueOf(Integer.parseInt(pole1.getText()) - Integer.parseInt(pole2.getText())));
                break;
            case "*":
                wynik.setText(String.valueOf(Integer.parseInt(pole1.getText()) * Integer.parseInt(pole2.getText())));
                break;
        }
    }
}
