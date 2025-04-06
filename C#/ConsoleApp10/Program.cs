using System;

class Program
{
    static void Main()
    {
        int suma = 0;
        int liczba;

        do
        {
            Console.Write("Podaj liczbę (0 kończy wczytywanie liczb): ");
            liczba = int.Parse(Console.ReadLine());
            suma += liczba;
        } while (liczba != 0);

        Console.WriteLine($"Suma: {suma}");
    }
}