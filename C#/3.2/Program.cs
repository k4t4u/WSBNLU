using ConsoleApp21;

class Program
{
    static void Main(string[] args)
    {
        var systemKoncertow = new SystemRezerwacji<Koncert>();
        systemKoncertow.DodajWydarzenie(new Koncert("Metallica"));
        systemKoncertow.DodajWydarzenie(new Koncert("Coldplay"));

        var systemSpektakli = new SystemRezerwacji<Spektakl>();
        systemSpektakli.DodajWydarzenie(new Spektakl("Nemo"));
        systemSpektakli.DodajWydarzenie(new Spektakl("Dziady"));

        var systemSportowy = new SystemRezerwacji<WydarzenieSportowe>();
        systemSportowy.DodajWydarzenie(new WydarzenieSportowe("Polska - Niemcy"));
        systemSportowy.DodajWydarzenie(new WydarzenieSportowe("Barcelona - Real"));

        Console.WriteLine("xaxaxa REZERWACJE xaxaxa");
        systemKoncertow.ZarezerwujWszystko();
        systemSpektakli.ZarezerwujWszystko();
        systemSportowy.ZarezerwujWszystko();

        Console.WriteLine("\nxaxaxa ANULOWANIE xaxaxa");
        systemKoncertow.AnulujWszystko();
        systemSpektakli.AnulujWszystko();
        systemSportowy.AnulujWszystko();
    }
}