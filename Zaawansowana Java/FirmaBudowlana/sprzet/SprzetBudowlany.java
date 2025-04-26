package sprzet;

abstract public class SprzetBudowlany {
    private final String nazwa;
    private final int dziennyCzasPracy;

    public SprzetBudowlany(String nazwa, int dziennyCzasPracy) {
        this.nazwa = nazwa;
        this.dziennyCzasPracy = dziennyCzasPracy;
    }

    public String getNazwa() {
        return nazwa;
    }

    public int getDziennyCzasPracy() {
        return dziennyCzasPracy;
    }

    public void DrukujDaneSprzetu() {
        System.out.println("Sprzęt: " + getNazwa());
        System.out.println("Dzienny czas pracy: " + getDziennyCzasPracy() + " h");
    }

    public abstract double ObliczKosztEksploatacjiDzienny();

    public void DrukujKosztEksploatacji() {
        DrukujDaneSprzetu();
        System.out.println("Dzienne koszty eksploatacji: " + ObliczKosztEksploatacjiDzienny() + " zł");
        System.out.println();
    }
}