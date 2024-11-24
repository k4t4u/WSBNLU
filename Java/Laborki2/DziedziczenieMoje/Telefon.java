public class Telefon extends Urzadzenie {

    private double pojemnoscBaterii;
    private double przekatnaWyswietlacza;

    public Telefon(String numer, String nazwa, double pojemnoscBaterii, double przekatnaWyswietlacza) {
        super(numer, nazwa);
        this.pojemnoscBaterii = pojemnoscBaterii;
        this.przekatnaWyswietlacza = przekatnaWyswietlacza;
    }

    public void Drukuj() {
        super.Drukuj();
        System.out.println("Pojemność baterii: " + pojemnoscBaterii);
        System.out.println("Przekątna wyświetlacza: " + przekatnaWyswietlacza);
        System.out.println("Czas pracy baterii: " + CzasPracyBaterii());
    }

    public double CzasPracyBaterii() {
        return pojemnoscBaterii / (przekatnaWyswietlacza * new ParametryTechniczne().SredniaEnergiaNaCal());
    }
}
