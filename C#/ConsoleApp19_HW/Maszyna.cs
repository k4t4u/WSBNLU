namespace ConsoleApp19_HW;

public class Maszyna : WypozyczeniePojazdu
{
    public int IloscMotoGodzin { get; set; }
    public static decimal KwotaRabat = 5000m;

    public decimal Rabat
    {
        get { return WartoscBrutto < KwotaRabat ? 0.10m : 0.20m; }
    }

    public Maszyna(string numerId, int ilosc, decimal cenaNetto, decimal vat, int iloscMotoGodzin)
        : base(numerId, ilosc, cenaNetto, vat)
    {
        IloscMotoGodzin = iloscMotoGodzin;
    }

    public override string ToString()
    {
        return base.ToString() + $", Motogodziny: {IloscMotoGodzin}, Rabat: {Rabat * 100}%";
    }
}