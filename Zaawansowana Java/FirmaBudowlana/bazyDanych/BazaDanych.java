package bazyDanych;

import parametry.Zbior;
import pracownicy.PracownikBudowlany;
import sprzet.SprzetBudowlany;
import zlecenia.ZlecenieBudowlane;

public class BazaDanych {
    private Zbior<PracownikBudowlany> pracownicy;
    private Zbior<SprzetBudowlany> sprzety;
    private Zbior<ZlecenieBudowlane> zlecenia;

    public BazaDanych() {
        pracownicy = new Zbior<>();
        sprzety = new Zbior<>();
        zlecenia = new Zbior<>();
    }

    public Zbior<PracownikBudowlany> getPracownicy() {
        return pracownicy;
    }

    public Zbior<SprzetBudowlany> getSprzety() {
        return sprzety;
    }

    public Zbior<ZlecenieBudowlane> getZlecenia() {
        return zlecenia;
    }
}
