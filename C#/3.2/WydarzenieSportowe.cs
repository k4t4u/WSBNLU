namespace ConsoleApp21;

public class WydarzenieSportowe : IRezerwacja
{
    public string Mecz { get; set; }
    public bool RezerwacjaAktywna { get; private set; }

    public WydarzenieSportowe(string mecz)
    {
        Mecz = mecz;
        RezerwacjaAktywna = false;
    }

    public bool Zarezerwuj()
    {
        if (!RezerwacjaAktywna)
        {
            RezerwacjaAktywna = true;
            Console.WriteLine($"Zarezerwowano mecz: {Mecz}");
            return true;
        }
        return false;
    }

    public bool AnulujRezerwacje()
    {
        if (RezerwacjaAktywna)
        {
            RezerwacjaAktywna = false;
            Console.WriteLine($"Anulowano rezerwację meczu: {Mecz}");
            return true;
        }
        return false;
    }
}
