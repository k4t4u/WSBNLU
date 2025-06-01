using ConsoleApp23;

class Program
{
    static void Main(string[] args)
    {
        var magazyn = new Magazyn<Produkt>();

        // Dodawanie produktów
        magazyn.Dodaj(new Produkt("P001", "Młotek", 10));
        magazyn.Dodaj(new Produkt("P002", "Śrubokręt", 15));
        magazyn.Dodaj(new Produkt("P003", "Klucz", 8));

        magazyn.WyswietlWszystko();

        // Wyszukiwanie
        var znaleziony = magazyn.Wyszukaj("P002");
        Console.WriteLine("\nZnaleziono: " + (znaleziony != null ? znaleziony.ToString() : "Brak"));

        // Usuwanie
        bool usunieto = magazyn.Usun("P003");
        Console.WriteLine($"\nUsunięto P003: {(usunieto ? "Tak" : "Nie")}");

        // Po usunięciu
        magazyn.WyswietlWszystko();
    }
}