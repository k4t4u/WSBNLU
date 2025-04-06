using System;

class Program
{
    static void Main()
    {
        Console.Write("Podaj długość boku a: ");
        int a = int.Parse(Console.ReadLine());

        Console.Write("Podaj długość boku b: ");
        int b = int.Parse(Console.ReadLine());

        int pole = a * b;
        int obwod = 2 * (a + b);

        Console.WriteLine($"Pole: {pole}, Obwód: {obwod}");
    }
}