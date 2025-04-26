package zlecenia;

import pracownicy.PracownikBudowlany;
import parametry.Data;

abstract public class ZlecenieBudowlane {
    private final String numer;
    private final PracownikBudowlany pracownik;
    private final Data dataZawarcia;
    private final String typZlecenia;
    private final int liczbaGodzin;

    public ZlecenieBudowlane(String numer, PracownikBudowlany pracownik, Data dataZawarcia, String typZlecenia, int liczbaGodzin) {
        this.numer = numer;
        this.pracownik = pracownik;
        this.dataZawarcia = dataZawarcia;
        this.typZlecenia = typZlecenia;
        this.liczbaGodzin = liczbaGodzin;
    }

    public void DrukujDaneZlecenia() {
        System.out.println("Numer zlecenia: " + numer);
        System.out.println("Pracownik odpowiedzialny:");
        pracownik.Wyswietl();
        System.out.println("Data zawarcia zlecenia:");
        dataZawarcia.Wyswietl();
        System.out.println("Typ zlecenia: " + typZlecenia);
        System.out.println("Liczba godzin do przepracowania: " + liczbaGodzin);
    }

    public abstract double ObliczKosztCalosciZlecenia();

    public int GetLiczbaGodzin() {
        return liczbaGodzin;
    }
    public void DrukujKosztZlecenia() {
        DrukujDaneZlecenia();
        System.out.println("Całkowity koszt zlecenia: " + ObliczKosztCalosciZlecenia() + " zł");
        System.out.println();
    }
}