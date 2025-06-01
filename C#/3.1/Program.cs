using System;
using ConsoleApp20;

class Program
{
    static void Main(string[] args)
    {
        var zarzadzanie = new ZarzadzanieFakturami();

        // Subskrypcja zdarzeń
        zarzadzanie.FakturaDodana += komunikat => Console.WriteLine("[INFO] " + komunikat);
        zarzadzanie.FakturaUsunieta += komunikat => Console.WriteLine("[INFO] " + komunikat);

        // Dodanie faktur
        zarzadzanie.DodajFakture("Jan Kowalski", "Warszawa", 1000, 23);
        zarzadzanie.DodajFakture("Anna Nowak", "Kraków", 500, 8);

        // Wyświetlenie konkretnej faktury
        var faktura = zarzadzanie.WyswietlFakture("FV" + DateTime.Now.Ticks); // Nie znajdzie, ale to test
        if (faktura != null)
            Console.WriteLine(faktura);
        else
            Console.WriteLine("Nie znaleziono faktury.");

        // Aktualizacja danych klienta
        bool zaktualizowano = zarzadzanie.AktualizujDaneKlienta(zarzadzanie.WyswietlFakture("FV1")?.NumerFaktury ?? "", "Nowy Klient", "Nowy Adres");
        Console.WriteLine(zaktualizowano ? "Zaktualizowano dane klienta." : "Nie znaleziono faktury.");

        // Usuwanie faktury
        foreach (var f in new[] { "FV1", "FV2" })
            zarzadzanie.UsunFakture(f);
    }
}