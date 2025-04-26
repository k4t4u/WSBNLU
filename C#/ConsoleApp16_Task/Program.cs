// See https://aka.ms/new-console-template for more information

using System;

class Program
{
    static void Main(string[] args)
    {
        bool exit = false;

        while (!exit)
        {
            Console.Clear();
            Console.WriteLine("Kalkulator pól figur geometrycznych");
            Console.WriteLine("1. Kwadrat");
            Console.WriteLine("2. Prostokąt");
            Console.WriteLine("3. Trójkąt");
            Console.WriteLine("4. Koło");
            Console.WriteLine("5. Zakończ program");
            Console.Write("Wybierz opcję (1-5): ");

            string choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    CalculateSquareArea();
                    break;
                case "2":
                    CalculateRectangleArea();
                    break;
                case "3":
                    CalculateTriangleArea();
                    break;
                case "4":
                    CalculateCircleArea();
                    break;
                case "5":
                    exit = true;
                    Console.WriteLine("Zamykanie programu...");
                    break;
                default:
                    Console.WriteLine("Nieprawidłowy wybór. Naciśnij dowolny klawisz, aby spróbować ponownie.");
                    Console.ReadKey();
                    break;
            }
        }
    }

    static void CalculateSquareArea()
    {
        Console.Clear();
        Console.WriteLine("*** Pole kwadratu ***");
        double side = ReadPositiveDouble("Podaj długość boku: ");
        double area = side * side;
        Console.WriteLine($"Pole kwadratu wynosi: {area}");
        Pause();
    }

    static void CalculateRectangleArea()
    {
        Console.Clear();
        Console.WriteLine("*** Pole prostokąta ***");
        double length = ReadPositiveDouble("Podaj długość: ");
        double width = ReadPositiveDouble("Podaj szerokość: ");
        double area = length * width;
        Console.WriteLine($"Pole prostokąta wynosi: {area}");
        Pause();
    }

    static void CalculateTriangleArea()
    {
        Console.Clear();
        Console.WriteLine("*** Pole trójkąta ***");
        double baseLength = ReadPositiveDouble("Podaj długość podstawy: ");
        double height = ReadPositiveDouble("Podaj wysokość: ");
        double area = (baseLength * height) / 2;
        Console.WriteLine($"Pole trójkąta wynosi: {area}");
        Pause();
    }

    static void CalculateCircleArea()
    {
        Console.Clear();
        Console.WriteLine("*** Pole koła ***");
        double radius = ReadPositiveDouble("Podaj promień: ");
        double area = Math.PI * radius * radius;
        Console.WriteLine($"Pole koła wynosi: {area}");
        Pause();
    }

    static double ReadPositiveDouble(string prompt)
    {
        double result;
        do
        {
            Console.Write(prompt);
            string input = Console.ReadLine();
            if (!double.TryParse(input, out result) || result <= 0)
            {
                Console.WriteLine("Błąd: proszę wprowadzić poprawną dodatnią liczbę.");
            }
        } while (result <= 0);
        return result;
    }

    static void Pause()
    {
        Console.WriteLine("Naciśnij dowolny klawisz, aby kontynuować...");
        Console.ReadKey();
    }
}
