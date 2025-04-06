using System;

class Program
{
    static void Main()
    {
        Console.Write("Podaj liczbę n: ");
        int n = int.Parse(Console.ReadLine());

        Console.Write("Podaj podstawę systemu (2–10): ");
        int s = int.Parse(Console.ReadLine());

        string wynik = "";

        while (n > 0)
        {
            wynik = (n % s) + wynik;
            n /= s;
        }

        Console.WriteLine($"Liczba w systemie o podstawie {s}: {wynik}");
    }
}