namespace ConsoleApp23;

using System.Collections.Generic;
using System.Linq;

public class Magazyn<T> where T : IIdentyfikacja, IZliczanie, IComparable<T>
{
    private List<T> przedmioty = new List<T>();

    public void Dodaj(T item)
    {
        przedmioty.Add(item);
    }

    public bool Usun(string id)
    {
        var item = przedmioty.FirstOrDefault(p => p.Id == id);
        if (item != null)
        {
            przedmioty.Remove(item);
            return true;
        }
        return false;
    }

    public T Wyszukaj(string id)
    {
        return przedmioty.FirstOrDefault(p => p.Id == id);
    }

    public void WyswietlWszystko()
    {
        Console.WriteLine("xaxaxaxa Stan magazynu xaxaxaxa");
        foreach (var p in przedmioty.OrderBy(p => p))
        {
            Console.WriteLine(p);
        }
    }
}
