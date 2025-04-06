using System;

class Program
{
    static void Main()
    {
        Console.Write("Podaj temperaturę ciała: ");
        double temp = double.Parse(Console.ReadLine());

        if (temp >= 36.6 && temp <= 37.0)
            Console.WriteLine("OK");
        else if (temp >= 37.1 && temp <= 38.0)
            Console.WriteLine("Stan podgorączkowy");
        else if (temp >= 38.1 && temp <= 41.0)
            Console.WriteLine("Gorączka");
        else
            Console.WriteLine("Skonsultuj się z lekarzem");
    }
}