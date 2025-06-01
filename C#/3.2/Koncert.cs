namespace ConsoleApp21;

using System;

public class Koncert : IRezerwacja
{
    public string Nazwa { get; set; }
    public bool CzyZarezerwowane { get; private set; }

    public Koncert(string nazwa)
    {
        Nazwa = nazwa;
        CzyZarezerwowane = false;
    }

    public bool Zarezerwuj()
    {
        if (!CzyZarezerwowane)
        {
            CzyZarezerwowane = true;
            Console.WriteLine($"Zarezerwowano koncert: {Nazwa}");
            return true;
        }
        return false;
    }

    public bool AnulujRezerwacje()
    {
        if (CzyZarezerwowane)
        {
            CzyZarezerwowane = false;
            Console.WriteLine($"Anulowano rezerwację koncertu: {Nazwa}");
            return true;
        }
        return false;
    }
}
