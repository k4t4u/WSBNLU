public class Lokalizacja {

    private String miasto;
    private String ulica;
    private String numer;

    public Lokalizacja(String miasto, String ulica, String numer) {
        this.miasto = miasto;
        this.ulica = ulica;
        this.numer = numer;
    }

    public void wyswietl() {
        System.out.println("Miasto: " + miasto);
        System.out.println("Ulica: " + ulica);
        System.out.println("Numer: " + numer);
    }
}
