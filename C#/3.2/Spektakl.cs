namespace ConsoleApp21;

public class Spektakl : IRezerwacja
{
    public string Tytul { get; set; }
    public bool Zarezerwowany { get; private set; }

    public Spektakl(string tytul)
    {
        Tytul = tytul;
        Zarezerwowany = false;
    }

    public bool Zarezerwuj()
    {
        if (!Zarezerwowany)
        {
            Zarezerwowany = true;
            Console.WriteLine($"Zarezerwowano spektakl: {Tytul}");
            return true;
        }
        return false;
    }

    public bool AnulujRezerwacje()
    {
        if (Zarezerwowany)
        {
            Zarezerwowany = false;
            Console.WriteLine($"Anulowano rezerwację spektaklu: {Tytul}");
            return true;
        }
        return false;
    }
}