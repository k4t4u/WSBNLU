import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;

class ParaSlow {
    private final String polish;
    private final String english;

    ParaSlow(String polish, String english) {
        this.polish    = polish;
        this.english = english;
    }
    String getPolish()    { return polish; }
    String getEnglish() { return english; }
}

public class WordsPresenter2 extends JFrame {

    private final List<ParaSlow> pary = new ArrayList<>();
    private int index = 0;

    private final JTextField enField = new JTextField(12);
    private final JTextField plField = new JTextField(12);
    private final JButton    nextBtn = new JButton("Pokaż następne słówko");

    public WordsPresenter2() {
        super("Prezentacja słówek englishch");
        initData();
        buildUI();
        showPair();

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setResizable(false);
        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    private void initData() {
        pary.add(new ParaSlow("kompilator",    "compiler"));
        pary.add(new ParaSlow("interpretor",   "interpreter"));
        pary.add(new ParaSlow("zmienna",       "variable"));
        pary.add(new ParaSlow("pętla",         "loop"));
        pary.add(new ParaSlow("tablica",       "array"));
        pary.add(new ParaSlow("wyjątek",       "exception"));
        pary.add(new ParaSlow("dziedziczenie", "inheritance"));
        pary.add(new ParaSlow("pakiet",        "package"));
        pary.add(new ParaSlow("wątek",         "thread"));
        pary.add(new ParaSlow("interfejs",     "interface"));
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
            index = (index + 1) % pary.size();
            showPair();
        });
    }

    private void showPair() {
        ParaSlow para = pary.get(index);
        enField.setText(para.getEnglish());
        plField.setText(para.getPolish());
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(WordsPresenter::new);
    }
}
