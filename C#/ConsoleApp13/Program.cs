using System;

class Program
{
    static void Main()
    {
        int[] tab = new int[100];
        Random rand = new Random();

        int min = int.MaxValue;
        int max = int.MinValue;

        for (int i = 0; i < tab.Length; i++)
        {
            tab[i] = rand.Next(1, 1001);
            if (tab[i] < min) min = tab[i];
            if (tab[i] > max) max = tab[i];
            Console.Write($"{tab[i]} ");
        }

        Console.WriteLine($"\nNajmniejsza: {min}, Największa: {max}");
    }
}