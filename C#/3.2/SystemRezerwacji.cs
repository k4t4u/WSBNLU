namespace ConsoleApp21;

using System.Collections.Generic;

public class SystemRezerwacji<T> where T : IRezerwacja
{
    private List<T> wydarzenia = new List<T>();

    public void DodajWydarzenie(T wydarzenie)
    {
        wydarzenia.Add(wydarzenie);
    }

    public void ZarezerwujWszystko()
    {
        foreach (var w in wydarzenia)
        {
            bool wynik = w.Zarezerwuj();
            if (!wynik)
                Console.WriteLine("Rezerwacja nie powiodła się.");
        }
    }

    public void AnulujWszystko()
    {
        foreach (var w in wydarzenia)
        {
            bool wynik = w.AnulujRezerwacje();
            if (!wynik)
                Console.WriteLine("Anulowanie nie powiodło się.");
        }
    }
}
