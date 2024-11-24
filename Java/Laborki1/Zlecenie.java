public class Zlecenie {

    private Rezerwacja rezerwacja;
    private Serwis serwis;
    private Lokalizacja lokalizacja;


    public Zlecenie(Rezerwacja rezerwacja, Serwis serwis, Lokalizacja lokalizacja) {
        this.rezerwacja = rezerwacja;
        this.serwis = serwis;
        this.lokalizacja = lokalizacja;
    }


    public void wyswietl() {
        System.out.println("=== Informacje o Zleceniu ===");
        rezerwacja.wyswietl();
        System.out.println();
        serwis.wyswietl();
        System.out.println();
        lokalizacja.wyswietl();
    }
}
