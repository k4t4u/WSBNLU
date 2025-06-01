namespace ConsoleApp24;

using System.Collections.Generic;

public class Zoo<T> where T : Animal
{
    private List<T> animals = new List<T>();

    public void DodajZwierze(T animal)
    {
        animals.Add(animal);
    }

    public void UsunZwierze(T animal)
    {
        animals.Remove(animal);
    }

    public void WyswietlZwierzeta()
    {
        Console.WriteLine("\nxaxa Zwierzęta w ZOO xaxa");
        foreach (var a in animals)
        {
            Console.WriteLine(a);
        }
    }

    public void WydajDzwieki()
    {
        Console.WriteLine("\nxaxa Odgłosy zwierząt xaxa");
        foreach (var a in animals)
        {
            a.MakeSound();
        }
    }
}
