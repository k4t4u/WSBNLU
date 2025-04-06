using System;

class Program
{
    static void Main()
    {
        string[] imiona = new string[10];

        for (int i = 0; i < 10; i++)
        {
            Console.Write($"Podaj imię {i + 1}: ");
            imiona[i] = Console.ReadLine();
        }

        Console.WriteLine("Odwrotna kolejność: ");
        for (int i = 9; i >= 0; i--)
        {
            Console.WriteLine(imiona[i]);
        }
    }
}