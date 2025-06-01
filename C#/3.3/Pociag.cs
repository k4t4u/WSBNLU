namespace ConsoleApp22;

public class Pociag : IMaszyna
{
    public string Model { get; set; } = "Pendolino";
    public int Predkosc { get; set; } = 200;

    public void Wyswietl()
    {
        Console.WriteLine($"Pociąg: Model = {Model}, Prędkość = {Predkosc} km/h");
    }
}