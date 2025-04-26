package kosztorysy;

import sprzet.SprzetBudowlany;
import zlecenia.ZlecenieBudowlane;

import java.util.ArrayList;
import java.util.List;

public class KosztorysBudowlany {
    private final ZlecenieBudowlane zlecenie;
    private final List<SprzetBudowlany> sprzety = new ArrayList<>();
    private final int dniPracy;

    public KosztorysBudowlany(ZlecenieBudowlane zlecenie, int dniPracy) {
        this.zlecenie = zlecenie;
        this.dniPracy = dniPracy;
    }

    public void DodajSprzet(SprzetBudowlany sprzet) {
        this.sprzety.add(sprzet);
    }

    public double ObliczKosztSprzetu() {
        double kosztSprzetu = 0.0;
        for (SprzetBudowlany sprzet : sprzety) {
            kosztSprzetu += sprzet.ObliczKosztEksploatacjiDzienny() * dniPracy;
        }
        return kosztSprzetu;
    }

    public double ObliczCalkowityKoszt() {
        double kosztZlecenia = zlecenie.ObliczKosztCalosciZlecenia();
        return kosztZlecenia + ObliczKosztSprzetu();
    }


    public void DrukujKosztorys() {
        System.out.println("Kosztorys zlecenia:");
        zlecenie.DrukujDaneZlecenia();

        System.out.println("Koszt sprzętu (liczba dni: " + dniPracy + "):");

        for (SprzetBudowlany sprzet : sprzety) {
            sprzet.DrukujKosztEksploatacji();
            double kosztSprzetu = sprzet.ObliczKosztEksploatacjiDzienny() * dniPracy;
            System.out.println("Koszt użycia " + sprzet.getNazwa()
                    + " przez " + dniPracy + " dni: " + kosztSprzetu + " zł\n");
        }

        System.out.println("Całkowity koszt zlecenia: " + ObliczCalkowityKoszt() + " zł");
    }
}
