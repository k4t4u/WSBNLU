import java.util.InputMismatchException;
import java.util.Scanner;

public class AnalizatorTekstu {

    public String Tekst;

    public AnalizatorTekstu(String tekst) {
        this.Tekst = tekst;
    }

    public AnalizatorTekstu() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Podaj tekst: ");
        Tekst = sc.nextLine();
    }

    public void analiza() {
        System.out.println("Tekst: " + Tekst);
        if (Tekst != null && !Tekst.isEmpty()) {
            System.out.println("Długość tekstu:" + Tekst.length());
            System.out.println("Pierwsza litera: " + Tekst.charAt(0));
            System.out.println("Ostatnia litera: " + Tekst.charAt(Tekst.length() - 1));
        }
    }

    public void przelicznikKM() {
        double km = 0.0;
        double mile = 0.0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Podaj ilość km: ");
        while (true) {
            try {
                km = sc.nextDouble();
                if (km <= 0) {
                    throw new UjemnaLiczbaException("Liczba nie moze byc ujemna.");
                }
                break;

            } catch (InputMismatchException e) {
                System.out.println("Niepoprawne dane.");
                sc.nextLine();
            } catch (UjemnaLiczbaException e) {
                e.getMessage();
                System.out.println(e);
            }
        }
        mile = km * 1.852;
        System.out.println("Podana ilość KM w przelizceniu na mile to: " + mile);
        sc.close();
    }
}
