namespace ConsoleApp22;

public class Samolot : IMaszyna
{
    public string Model { get; set; } = "Boeing 737";
    public int Predkosc { get; set; } = 900;

    public void Wyswietl()
    {
        Console.WriteLine($"Samolot: Model = {Model}, Prędkość = {Predkosc} km/h");
    }
}