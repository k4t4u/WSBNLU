package zlecenia;

import parametry.Data;
import parametry.ParametryBudowlane;
import pracownicy.PracownikBudowlany;

public class ZlecenieNaElewacje extends ZlecenieBudowlane {
    private final double kosztFarby;
    private final double kosztRusztowan;

    public ZlecenieNaElewacje(String numer, PracownikBudowlany pracownik, Data dataZawarcia, String typZlecenia, int liczbaGodzin, double kosztFarby, double kosztRusztowan) {
        super(numer, pracownik, dataZawarcia, typZlecenia, liczbaGodzin);
        this.kosztFarby = kosztFarby;
        this.kosztRusztowan = kosztRusztowan;
    }

    @Override
    public double ObliczKosztCalosciZlecenia() {
        double kosztPracownika = GetLiczbaGodzin() * ParametryBudowlane.StawkaGodzinowaPracownika();
        double sumaKosztow = kosztPracownika + kosztFarby + kosztRusztowan;
        return sumaKosztow * ParametryBudowlane.MarzaDeweloperska();
    }

    public double ObliczKosztMalowania() {
        double kosztPracMalarskich = (GetLiczbaGodzin() * 0.5) * ParametryBudowlane.StawkaGodzinowaPracownika();
        return kosztFarby + kosztPracMalarskich;
    }

    @Override
    public void DrukujDaneZlecenia() {
        super.DrukujDaneZlecenia();
        System.out.println("Koszt farby: " + kosztFarby + " zł");
        System.out.println("Koszt rusztowań: " + kosztRusztowan + " zł");
    }
}
