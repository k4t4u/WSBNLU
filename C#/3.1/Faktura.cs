namespace ConsoleApp20;

public class Faktura
{
    public string NumerFaktury { get; set; }
    public DateTime DataWystawienia { get; set; }
    public DateTime TerminPlatnosci { get; set; }
    public string NazwaKlienta { get; set; }
    public string AdresKlienta { get; set; }
    public decimal KwotaNetto { get; set; }
    public decimal StawkaVAT { get; set; }

    private decimal kwotaBrutto;
    public decimal KwotaBrutto
    {
        get { return kwotaBrutto; }
        private set { kwotaBrutto = value; }
    }

    // Konstruktor bezparametrowy
    public Faktura()
    {
        NumerFaktury = "";
        DataWystawienia = DateTime.Now;
        TerminPlatnosci = DateTime.Now.AddDays(14);
        NazwaKlienta = "";
        AdresKlienta = "";
        KwotaNetto = 0;
        StawkaVAT = 0;
        KwotaBrutto = 0;
    }

    // Konstruktor z parametrami (bez kwoty brutto)
    public Faktura(string numer, DateTime data, DateTime termin, string klient, string adres, decimal netto, decimal vat)
    {
        NumerFaktury = numer;
        DataWystawienia = data;
        TerminPlatnosci = termin;
        NazwaKlienta = klient;
        AdresKlienta = adres;
        KwotaNetto = netto;
        StawkaVAT = vat;
        KwotaBrutto = netto + (netto * vat / 100);
    }

    public override string ToString()
    {
        return $"Faktura: {NumerFaktury}, Klient: {NazwaKlienta}, Kwota brutto: {KwotaBrutto:C}";
    }
}
