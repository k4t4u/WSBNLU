namespace ConsoleApp19_HW;

public class WypozyczeniePojazdu
{
    private int _id;
    private static int _nextId = 1;

    private string numerId;
    private int ilosc;
    private decimal cenaNetto;
    private decimal vat;

    public static int liczbaWypozyczen;

    static WypozyczeniePojazdu()
    {
        liczbaWypozyczen = 0;
    }

    public WypozyczeniePojazdu()
    {
        numerId = "BRAK";
        ilosc = 0;
        cenaNetto = 0;
        vat = 0;
        _id = _nextId++;
        liczbaWypozyczen++;
    }

    public WypozyczeniePojazdu(string numerId, int ilosc, decimal cenaNetto, decimal vat)
    {
        this.numerId = numerId;
        this.ilosc = ilosc;
        this.cenaNetto = cenaNetto;
        this.vat = vat;
        _id = _nextId++;
        liczbaWypozyczen++;
    }

    public WypozyczeniePojazdu(WypozyczeniePojazdu inny)
    {
        this.numerId = inny.numerId;
        this.ilosc = inny.ilosc;
        this.cenaNetto = inny.cenaNetto;
        this.vat = inny.vat;
        _id = _nextId++;
        liczbaWypozyczen++;
    }

    public override string ToString()
    {
        return
            $"ID: {Id}, NumerID: {NumerId}, Ilość: {Ilosc}, Cena netto: {CenaNetto:C}, VAT: {Vat}%, Brutto: {WartoscBrutto:C}";
    }

    public int Id
    {
        get => _id;
        private set => _id = value;
    }

    public string NumerId
    {
        get => numerId;
        set => numerId = value;
    }

    public int Ilosc
    {
        get => ilosc;
        set => ilosc = value;
    }

    public decimal CenaNetto
    {
        get => cenaNetto;
        set => cenaNetto = value;
    }

    public decimal Vat
    {
        get => vat;
        set => vat = value;
    }

    public decimal WartoscBrutto
    {
        get => (1 + Vat / 100) * Ilosc * CenaNetto;
    }
}