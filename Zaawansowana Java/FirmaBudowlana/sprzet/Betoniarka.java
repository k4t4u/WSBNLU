package sprzet;

import parametry.ParametryBudowlane;

public class Betoniarka extends SprzetBudowlany {
    public Betoniarka(int dziennyCzasPracy) {
        super("sprzet.Betoniarka", dziennyCzasPracy);
    }

    @Override
    public double ObliczKosztEksploatacjiDzienny() {
        return ParametryBudowlane.KosztNaDzienBetoniarka() * ParametryBudowlane.MarzaDeweloperska();
    }
}
