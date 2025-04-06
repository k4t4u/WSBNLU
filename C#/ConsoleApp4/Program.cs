using System;

class Program
{
    static void Main()
    {
        Console.Write("Podaj swój wiek: ");
        int wiek = int.Parse(Console.ReadLine());

        if (wiek < 12)
        {
            Console.WriteLine("Jesteś dzieckiem.");
        }
        else if (wiek < 18)
        {
            Console.WriteLine("Jesteś nastolatkiem.");
        }
        else
        {
            Console.WriteLine("Jesteś dorosły.");
        }
    }
}