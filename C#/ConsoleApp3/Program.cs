using System;

class Program
{
    static void Main()
    {
        Console.Write("Podaj pierwszą liczbę: ");
        int a = int.Parse(Console.ReadLine());

        Console.Write("Podaj drugą liczbę: ");
        int b = int.Parse(Console.ReadLine());

        Console.WriteLine($"Suma: {a + b}");
        Console.WriteLine($"Różnica: {a - b}");
        Console.WriteLine($"Iloczyn: {a * b}");

        if (b != 0)
        {
            Console.WriteLine($"Iloraz: {a / b}");
            Console.WriteLine($"Reszta z dzielenia: {a % b}");
        }
        else
        {
            Console.WriteLine("Nie można dzielić przez zero.");
        }
    }
}
