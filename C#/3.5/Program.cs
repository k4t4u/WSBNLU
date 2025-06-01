using ConsoleApp24;

class Program
{
    static void Main(string[] args)
    {
        var zooLwow = new Zoo<Lion>();
        zooLwow.DodajZwierze(new Lion("Simba", 5));
        zooLwow.DodajZwierze(new Lion("Mufasa", 9));

        var zooSloni = new Zoo<Elephant>();
        zooSloni.DodajZwierze(new Elephant("Dumbo", 12));
        zooSloni.DodajZwierze(new Elephant("Ella", 10));

        var zooPapug = new Zoo<Parrot>();
        zooPapug.DodajZwierze(new Parrot("Koko", 2));
        zooPapug.DodajZwierze(new Parrot("Polly", 4));

        zooLwow.WyswietlZwierzeta();
        zooLwow.WydajDzwieki();

        zooSloni.WyswietlZwierzeta();
        zooSloni.WydajDzwieki();

        zooPapug.WyswietlZwierzeta();
        zooPapug.WydajDzwieki();
    }
}