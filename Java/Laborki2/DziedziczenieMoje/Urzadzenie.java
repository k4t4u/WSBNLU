public class Urzadzenie {

    private String numer;
    private String nazwa;

    public Urzadzenie(String numer, String nazwa) {
        this.numer = numer;
        this.nazwa = nazwa;
    }

    public void Drukuj() {
        System.out.println("Numer: " + numer);
        System.out.println("Nazwa: " + nazwa);
    }
}
