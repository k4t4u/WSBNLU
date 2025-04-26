package zlecenia;

import parametry.Data;
import parametry.ParametryBudowlane;
import pracownicy.PracownikBudowlany;

public class ZlecenieNaFundamenty extends ZlecenieBudowlane {
    private final double kosztMaterialow;

    public ZlecenieNaFundamenty(String numer, PracownikBudowlany pracownik, Data dataZawarcia, String typZlecenia, int liczbaGodzin, double kosztMaterialow) {
        super(numer, pracownik, dataZawarcia, typZlecenia, liczbaGodzin);
        this.kosztMaterialow = kosztMaterialow;
    }

    @Override
    public double ObliczKosztCalosciZlecenia() {
        double kosztPracownika = GetLiczbaGodzin() * ParametryBudowlane.StawkaGodzinowaPracownika();
        System.out.println("Koszt pracownika (godziny * stawka): " + kosztPracownika);
        double kosztZlecenia = (kosztPracownika + kosztMaterialow) * ParametryBudowlane.MarzaDeweloperska();
        System.out.println("Koszt zlecenia z marżą: " + kosztZlecenia);
        return kosztZlecenia;
    }

    public double ObliczKosztRobocizny() {
        return GetLiczbaGodzin() * ParametryBudowlane.StawkaGodzinowaPracownika();
    }

    @Override
    public void DrukujDaneZlecenia() {
        super.DrukujDaneZlecenia();
        System.out.println("Koszt materiałów: " + kosztMaterialow + " zł");
    }
}