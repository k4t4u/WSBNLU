namespace ConsoleApp23;

public class Produkt : IIdentyfikacja, IZliczanie, IComparable<Produkt>
{
    public string Id { get; set; }
    public int Ilosc { get; set; }
    public string Nazwa { get; set; }

    public Produkt(string id, string nazwa, int ilosc)
    {
        Id = id;
        Nazwa = nazwa;
        Ilosc = ilosc;
    }

    public int CompareTo(Produkt other)
    {
        return Id.CompareTo(other.Id);
    }

    public override string ToString()
    {
        return $"Produkt: {Nazwa}, Id: {Id}, Ilość: {Ilosc}";
    }
}
