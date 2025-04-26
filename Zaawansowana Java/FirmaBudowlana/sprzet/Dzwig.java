package sprzet;

import parametry.ParametryBudowlane;

public class Dzwig extends SprzetBudowlany {
    public Dzwig(int dziennyCzasPracy) {
        super("Dźwig", dziennyCzasPracy);
    }

    @Override
    public double ObliczKosztEksploatacjiDzienny() {
        return ParametryBudowlane.KosztNaDzienDzwig() * ParametryBudowlane.MarzaDeweloperska();
    }
}
