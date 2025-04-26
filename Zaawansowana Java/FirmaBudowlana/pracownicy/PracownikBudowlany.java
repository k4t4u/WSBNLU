package pracownicy;

public class PracownikBudowlany {
    private final String imie;
    private final String nazwisko;
    private final String stanowisko;

    public PracownikBudowlany(String imie, String nazwisko, String stanowisko) {
        this.imie = imie;
        this.nazwisko = nazwisko;
        this.stanowisko = stanowisko;
    }

    public void Wyswietl() {
        System.out.println("Imię: " + imie);
        System.out.println("Nazwisko: " + nazwisko);
        System.out.println("Stanowisko: " + stanowisko);
    }
}
