public class SuperKomputer extends Komputer {

    private double mocGpu;
    private int liczbaGpu;

    public SuperKomputer(String numer, String nazwa, double ram, double liczbaProcesorow, double mocGpu, int liczbaGpu) {
        super(numer, nazwa, ram, liczbaProcesorow);
        this.mocGpu = mocGpu;
        this.liczbaGpu = liczbaGpu;
    }

    @Override
    public void Drukuj() {
        super.Drukuj();
        System.out.println("Moc pojedynczego GPU: " + mocGpu);
        System.out.println("Liczba GPU: " + liczbaGpu);
        System.out.println("Całkowita moc GPU: " + calkowitaMocGpu());
        System.out.println("Całkowity pobór mocy systemu: " + calkowitaMocKomputera());
        System.out.println("Wskaźnik wydajności: " + wartoscWydajnosci());
    }

    public double calkowitaMocGpu() {
        return mocGpu * liczbaGpu;
    }

    public double calkowitaMocKomputera() {
        return MaxPoborMocy() + calkowitaMocGpu();
    }

    public double wartoscWydajnosci() {
        return (getLiczbaProcesorow() * 1000 + calkowitaMocGpu() * 500) / getRam();
    }
}
