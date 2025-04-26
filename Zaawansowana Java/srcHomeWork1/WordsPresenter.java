import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;

public class WordsPresenter extends JFrame {

    private final String[] plWords = {
            "kompilator", "interpretor", "zmienna", "pętla",
            "tablica", "wyjątek", "dziedziczenie", "pakiet",
            "wątek", "interfejs"
    };
    private final String[] enWords = {
            "compiler", "interpreter", "variable", "loop",
            "array", "exception", "inheritance", "package",
            "thread", "interface"
    };
    private int index = 0;

    private final JTextField enField = new JTextField(12);
    private final JTextField plField = new JTextField(12);
    private final JButton nextBtn   = new JButton("Pokaż następne słówko");

    public WordsPresenter() {
        super("Prezentacja słówek angielskich");
        buildUI();
        showPair();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setResizable(false);
        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    private void buildUI() {

        JPanel content = new JPanel(new BorderLayout());
        content.setBorder(new EmptyBorder(8, 8, 8, 8));
        setContentPane(content);

        JPanel panel = new JPanel(new GridBagLayout());
        panel.setBackground(new Color(240, 240, 240));
        panel.setBorder(new TitledBorder(new LineBorder(Color.GRAY, 1, true), ""));

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(6, 8, 6, 8);
        gbc.anchor = GridBagConstraints.BASELINE_LEADING;

        gbc.gridx = 0; gbc.gridy = 0;
        panel.add(new JLabel("Po angielsku"), gbc);

        gbc.gridx = 1;
        enField.setEditable(false);
        enField.setHorizontalAlignment(JTextField.CENTER);
        panel.add(enField, gbc);

        gbc.gridx = 2;
        panel.add(new JLabel("Po polsku"), gbc);

        gbc.gridx = 3;
        plField.setEditable(false);
        plField.setHorizontalAlignment(JTextField.CENTER);
        panel.add(plField, gbc);

        gbc.gridx = 0; gbc.gridy = 1; gbc.gridwidth = 4;
        gbc.anchor = GridBagConstraints.CENTER;
        gbc.fill   = GridBagConstraints.HORIZONTAL;
        panel.add(nextBtn, gbc);

        content.add(panel, BorderLayout.CENTER);

        nextBtn.addActionListener(e -> {
            index = (index + 1) % plWords.length;
            showPair();
        });
    }

    private void showPair() {
        enField.setText(enWords[index]);
        plField.setText(plWords[index]);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(WordsPresenter::new);
    }
}
