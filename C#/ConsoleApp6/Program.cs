using System;

class Program
{
    static void Main()
    {
        Console.Write("Podaj cenę netto: ");
        double netto = double.Parse(Console.ReadLine());

        Console.Write("Podaj stawkę VAT: ");
        double vatStawka = double.Parse(Console.ReadLine());

        double vatKwota = netto * vatStawka / 100;
        double brutto = netto + vatKwota;

        Console.WriteLine($"VAT: {vatKwota:F2} zł ({vatStawka}%)");
        Console.WriteLine($"Cena brutto: {brutto:F2} zł");
    }
}