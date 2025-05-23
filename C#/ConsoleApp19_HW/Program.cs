using System;

namespace ConsoleApp19_HW
{
    class Program
    {
        static void Main(string[] args)
        {

            var pojazd1 = new WypozyczeniePojazdu("P1", 3, 120m, 23m);
            Console.WriteLine("WypożyczeniePojazdu (oryginał):");
            Console.WriteLine(pojazd1);
            Console.WriteLine();

            var pojazd2 = new WypozyczeniePojazdu(pojazd1);
            Console.WriteLine("WypożyczeniePojazdu (kopia):");
            Console.WriteLine(pojazd2);
            Console.WriteLine();

            var samochod = new Samochod("S1", 2, 200m, 23m, 800);
            Console.WriteLine("Samochód:");
            Console.WriteLine(samochod);
            Console.WriteLine();

            var maszyna = new Maszyna("M1", 1, 6000m, 23m, 25);
            Console.WriteLine("Maszyna:");
            Console.WriteLine(maszyna);
            Console.WriteLine();

            Console.WriteLine($"Liczba wypożyczeń łącznie: {WypozyczeniePojazdu.liczbaWypozyczen}");
        }
    }
}