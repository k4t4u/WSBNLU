public class Serwis {

    private String nazwaSerwisu;
    private String rodzajUslugi;
    private double cena;

    public Serwis(String nazwaSerwisu, String rodzajUslugi, double cena) {
        this.nazwaSerwisu = nazwaSerwisu;
        this.rodzajUslugi = rodzajUslugi;
        this.cena = cena;
    }

    public void wyswietl() {
        System.out.println("Serwis: " +nazwaSerwisu);
        System.out.println("Rodzaj uslugi: " +rodzajUslugi);
        System.out.println("Cena: " +cena +"PLN");
    }
}
