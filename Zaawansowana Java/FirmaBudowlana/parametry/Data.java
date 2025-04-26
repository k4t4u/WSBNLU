package parametry;

public class Data {
    private final int dzien;
    private final int miesiac;
    private final int rok;

    public Data(int dzien, int miesiac, int rok) {
        this.dzien = dzien;
        this.miesiac = miesiac;
        this.rok = rok;
    }

    public void Wyswietl() {
        System.out.println(dzien + "." + miesiac + "." + rok);
    }
}
