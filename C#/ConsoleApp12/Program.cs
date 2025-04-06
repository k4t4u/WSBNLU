using System;

class Program
{
    static void Main()
    {
        Console.Write("Podaj liczbę całkowitą: ");
        int liczba = Math.Abs(int.Parse(Console.ReadLine()));
        int suma = 0;

        while (liczba > 0)
        {
            suma += liczba % 10;
            liczba /= 10;
        }

        Console.WriteLine($"Suma cyfr: {suma}");
    }
}