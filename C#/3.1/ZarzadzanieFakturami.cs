namespace ConsoleApp20;

public delegate void InformacjaOFakturze(string komunikat);

public class ZarzadzanieFakturami : BazaFaktur
{
    public event InformacjaOFakturze FakturaDodana;
    public event InformacjaOFakturze FakturaUsunieta;

    public override bool AktualizujDaneKlienta(string numer, string nowaNazwa, string nowyAdres)
    {
        var faktura = WyswietlFakture(numer);
        if (faktura != null)
        {
            faktura.NazwaKlienta = nowaNazwa;
            faktura.AdresKlienta = nowyAdres;
            return true;
        }
        return false;
    }

    public void DodajFakture(string nazwaKlienta, string adresKlienta, decimal kwotaNetto, decimal stawkaVAT)
    {
        string numer = $"FV{DateTime.Now.Ticks}";
        var faktura = new Faktura(numer, DateTime.Now, DateTime.Now.AddDays(14), nazwaKlienta, adresKlienta, kwotaNetto, stawkaVAT);
        DodajFakture(faktura);
        FakturaDodana?.Invoke($"Dodano fakturę {numer} dla klienta {nazwaKlienta}");
    }

    public new void DodajFakture(Faktura faktura)
    {
        base.DodajFakture(faktura);
        FakturaDodana?.Invoke($"Dodano fakturę {faktura.NumerFaktury}");
    }

    public new bool UsunFakture(string numer)
    {
        bool usunieto = base.UsunFakture(numer);
        if (usunieto)
            FakturaUsunieta?.Invoke($"Usunięto fakturę {numer}");
        return usunieto;
    }
}
