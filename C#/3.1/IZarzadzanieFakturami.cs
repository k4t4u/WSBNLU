namespace ConsoleApp20;

public interface IZarzadzanieFakturami
{
    void DodajFakture(Faktura faktura);
    bool UsunFakture(string numerFaktury);
    Faktura WyswietlFakture(string numerFaktury);
    bool AktualizujDaneKlienta(string numerFaktury, string nowaNazwa, string nowyAdres);
}
