
public class Main {

    public static void main(String[] args) {
        System.out.println("Laborki 2\n\n");

        Komputer k1 = new Komputer("1", "Komputer 1", 8, 4);
        k1.Drukuj();
        System.out.println("-------------------------\n");

        Telefon t1 = new Telefon("2", "Samsung", 1200, 6);
        t1.Drukuj();
        System.out.println("-------------------------\n");

        IPhone i1 = new IPhone("3", "iPhone 14", 2400, 6, "12345");
        i1.Drukuj();
        System.out.println("-------------------------\n");

        SuperKomputer sk1 = new SuperKomputer("4", "SuperKomputer 1", 16, 8, 300, 4);
        sk1.Drukuj();
    }
}
