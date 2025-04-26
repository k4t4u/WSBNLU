import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;

public class WordsPanel extends JFrame {

    private final JTextField enField  = new JTextField(10);
    private final JTextField plField  = new JTextField(10);
    private final JButton    nextBtn  = new JButton("Pokaż następne słówko");

    public WordsPanel() {
        super("Prezentacja słówek angielskich");
        buildUI();
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
        panel.setBorder(new TitledBorder(
                new LineBorder(Color.GRAY, 1, true),
                "", TitledBorder.DEFAULT_JUSTIFICATION,
                TitledBorder.DEFAULT_POSITION,
                panel.getFont().deriveFont(Font.BOLD)));

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(6, 8, 6, 8);
        gbc.anchor = GridBagConstraints.BASELINE_LEADING;

        gbc.gridx = 0; gbc.gridy = 0;
        panel.add(new JLabel("Po angielsku"), gbc);

        gbc.gridx = 1;
        panel.add(enField, gbc);

        gbc.gridx = 2;
        panel.add(new JLabel("Po polsku"), gbc);

        gbc.gridx = 3;
        panel.add(plField, gbc);

        gbc.gridx = 0;
        gbc.gridy = 1;
        gbc.gridwidth = 4;
        gbc.anchor = GridBagConstraints.CENTER;
        gbc.fill   = GridBagConstraints.HORIZONTAL;
        panel.add(nextBtn, gbc);

        content.add(panel, BorderLayout.CENTER);

        enField.setHorizontalAlignment(JTextField.CENTER);
        plField.setHorizontalAlignment(JTextField.CENTER);

        enField.setEditable(false);
        plField.setEditable(false);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(WordsPanel::new);
    }
}
