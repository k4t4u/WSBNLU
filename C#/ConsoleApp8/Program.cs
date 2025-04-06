using System;

class Program
{
    static void Main()
    {
        Console.Write("Podaj liczbę: ");
        int liczba = int.Parse(Console.ReadLine());

        if (liczba % 2 != 0)
            Console.WriteLine("Podaba liczba jest nieparzysta.");
        else
            Console.WriteLine("Podaba liczba parzysta.");
    }
}
;