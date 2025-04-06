
public class Main {
    public static void main(String[] args) {

        AnalizatorTekstu analiza1 = new AnalizatorTekstu(null);
        analiza1.analiza();

        AnalizatorTekstu analiza2 = new AnalizatorTekstu();
        analiza2.analiza();

        analiza2.przelicznikKM();
    }
}
