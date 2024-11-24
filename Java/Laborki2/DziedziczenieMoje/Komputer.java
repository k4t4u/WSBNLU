public class Komputer extends Urzadzenie {

    private double ram;
    private double liczbaProcesorow;

    public Komputer(String numer, String nazwa, double ram, double liczbaProcesorow) {
        super(numer, nazwa);
        this.ram = ram;
        this.liczbaProcesorow = liczbaProcesorow;
    }

    public void Drukuj() {
        super.Drukuj();
        System.out.println("Ilość RAM: " + ram);
        System.out.println("Liczba procesorów: " + liczbaProcesorow);
        System.out.println("Maksymalny pobór mocy: " + MaxPoborMocy());
    }

    public double MaxPoborMocy() {
        return liczbaProcesorow * new ParametryTechniczne().Tdp();
    }

    public double getRam() {
        return ram;
    }

    public double getLiczbaProcesorow() {
        return liczbaProcesorow;
    }
}
