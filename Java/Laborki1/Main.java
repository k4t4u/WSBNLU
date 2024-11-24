
public class Main {

    public static void main(String[] args) {
        System.out.println("Laborki 1\n\n");


        Zlecenie zlecenie1 = new Zlecenie(
                new Rezerwacja("Janek Jankowski", "10.10.2010",5),
                new Serwis("Instalacja oprogramowania", "Na miejscu", 95350),
                new Lokalizacja("Radom", "Pany", "99"));

        zlecenie1.wyswietl();
    }
}