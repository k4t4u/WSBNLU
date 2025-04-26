package sprzet;

import parametry.ParametryBudowlane;

public class Koparka extends SprzetBudowlany {
    public Koparka(int dziennyCzasPracy) {
        super("sprzet.Koparka", dziennyCzasPracy);
    }

    @Override
    public double ObliczKosztEksploatacjiDzienny() {
        return ParametryBudowlane.KosztNaDzienKoparka() * ParametryBudowlane.MarzaDeweloperska();
    }
}
