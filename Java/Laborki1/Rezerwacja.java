public class Rezerwacja {

    private String nazwaKlienta;
    private String dataRezerwacji;
    private int numerKasy;

    public Rezerwacja(String nazwaKlienta, String dataRezerwacji, int numerKasy) {
        this.nazwaKlienta = nazwaKlienta;
        this.dataRezerwacji = dataRezerwacji;
        this.numerKasy = numerKasy;
    }

    public void wyswietl() {
        System.out.println("Rezerwacja dla: " + nazwaKlienta);
        System.out.println("Data rezerwacji: " + dataRezerwacji);
        System.out.println("numerKasy: " + numerKasy);
    }
}
