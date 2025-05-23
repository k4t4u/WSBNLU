namespace ConsoleApp19_HW;

public class Samochod : WypozyczeniePojazdu
{
    public int IloscPrzejechanychKm { get; set; }
    public static int IloscKmRabat = 1000;

    public decimal Rabat
    {
        get { return IloscPrzejechanychKm < IloscKmRabat ? 0.05m : 0.10m; }
    }

    public Samochod(string numerId, int ilosc, decimal cenaNetto, decimal vat, int iloscKm)
        : base(numerId, ilosc, cenaNetto, vat)
    {
        IloscPrzejechanychKm = iloscKm;
    }

    public override string ToString()
    {
        return base.ToString() + $", Przejechane km: {IloscPrzejechanychKm}, Rabat: {Rabat * 100}%";
    }
}