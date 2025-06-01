namespace ConsoleApp20;

using System.Collections.Generic;
using System.Linq;

public abstract class BazaFaktur : IZarzadzanieFakturami
{
    protected List<Faktura> faktury = new List<Faktura>();

    public virtual void DodajFakture(Faktura faktura)
    {
        faktury.Add(faktura);
    }

    public virtual bool UsunFakture(string numerFaktury)
    {
        var faktura = faktury.FirstOrDefault(f => f.NumerFaktury == numerFaktury);
        if (faktura != null)
        {
            faktury.Remove(faktura);
            return true;
        }
        return false;
    }

    public virtual Faktura WyswietlFakture(string numerFaktury)
    {
        return faktury.FirstOrDefault(f => f.NumerFaktury == numerFaktury);
    }

    public abstract bool AktualizujDaneKlienta(string numerFaktury, string nowaNazwa, string nowyAdres);
}
