public class IPhone extends Telefon {

    private String appleID;

    public IPhone(String numer, String nazwa, double pojemnoscBaterii, double przekatnaWyswietlacza, String appleID) {
        super(numer, nazwa, pojemnoscBaterii, przekatnaWyswietlacza);
        this.appleID = appleID;
    }

    public void Drukuj() {
        super.Drukuj();
        System.out.println("Apple ID: " + appleID);
    }
}
