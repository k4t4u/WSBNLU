/* Ma byc klasa A glowna  
Dziedziczace z A ma byc B i C
Dziedziczace z B ma byc D
*/
class Urzadzenie
{
    private String numer;
    private String nazwa;
    public Urzadzenie(String numer, String nazwa)
    {
        this.numer = numer;
        this.nazwa = nazwa;
    }
    public void Drukuj()
    {
        System.out.println("Numer: "+numer);
        System.out.println("Nazwa: "+nazwa);
    }
}
class ParametryTechniczne
{
    public double Tdp()
    {
        return 150;
    }
    public double SredniaEnergiaNaCal()
    {
        return 2;
    }
}
class Komputer extends Urzadzenie
{
    private double ram;
    private double liczbaProcesorow;
    public Komputer(String numer, String nazwa, double ram, double liczbaProcesorow)
    {
        super(numer, nazwa); // to jest wywolanie konstruktora z klasy Urzadzenie czyli wypelnienie numeru i nazwy
        this.ram = ram;
        this.liczbaProcesorow = liczbaProcesorow;
    }
    public void Drukuj()
    {
        super.Drukuj(); // to jest wywolanie metody Drukuj z klasy Urzadzenie czyli wydrukowanie numeru i nazwy komputera
        System.out.println("Ilosc ram: "+ram);
        System.out.println("Ilosc procesorow: "+liczbaProcesorow);
        System.out.println("Maks pobor mocy: "+MaxPoborMocy());
    }
    public double MaxPoborMocy()
    {
        return liczbaProcesorow * new ParametryTechniczne().Tdp();
    }
}
class Telefon extends Urzadzenie
{
    private double pojemnoscBaterii;
    private double przekatnaWyswietlacza;
    public Telefon(String numer, String nazwa, double pojemnoscBaterii, double przekatnaWyswietlacza)
    {
        super(numer, nazwa); // to jest wywolanie konstruktora z klasy Urzadzenie czyli wypelnienie numeru i nazwy
        this.pojemnoscBaterii = pojemnoscBaterii;
        this.przekatnaWyswietlacza = przekatnaWyswietlacza;
    }
    public void Drukuj()
    {
        super.Drukuj();
        System.out.println("Pojemnosc baterii: " + pojemnoscBaterii);
        System.out.println("Przekatna wyswietlacza: " + przekatnaWyswietlacza);
        System.out.println("Czas pracy baterii: " + CzasPracyBaterii());
    }
    public double CzasPracyBaterii()
    {
        return pojemnoscBaterii / (przekatnaWyswietlacza * new ParametryTechniczne().SredniaEnergiaNaCal()); 
    }
}
class IPhone extends Telefon
{
    private String appleID;
    public IPhone(String numer, String nazwa, double pojemnoscBaterii, double przekatnaWyswietlacza, String appleID)
    {
        super(numer, nazwa, pojemnoscBaterii, przekatnaWyswietlacza);
        this.appleID = appleID;
    }
    public void Drukuj()
    {
        super.Drukuj();
        System.out.println("Apple ID: " + appleID);
    }
}
public class Main
{
	public static void main(String[] args) 
	{
		System.out.println("Przyklad dziedziczenia\n\n");
		
		Komputer k1 = new Komputer("1", "Komputer 1", 1, 1);
		k1.Drukuj();
		System.out.println("-------------------------");
		Telefon t1 = new Telefon("2", "Samsung", 2400, 15);
		t1.Drukuj();
		System.out.println("-------------------------");
		IPhone i1 = new IPhone("3", "14", 4400, 5, "12345");
		i1.Drukuj();
	}
}
