using System;

class Program
{
    static void Main()
    {
        /*
         Program 1.2 Napisz program, w który poprosi użytkownika o podanie nazwiska, imienia i wieku,
        a następnie wyświetli wczytany z klawiatury tekst.
        */
        Console.Write("Podaj nazwisko: ");
        string nazwisko = Console.ReadLine();
        
        Console.Write("Podaj imię: ");
        string imie = Console.ReadLine();

        Console.Write("Podaj wiek: ");
        string wiek = Console.ReadLine();

        Console.WriteLine("\nWczytane dane:");
        Console.WriteLine($"{nazwisko} - {imie} - wiek: {wiek}");
    }
}
