namespace ConsoleApp22;

public class Motorowka : IMaszyna
{
    public string Model { get; set; } = "Yamaha 2000";
    public int Predkosc { get; set; } = 80;

    public void Wyswietl()
    {
        Console.WriteLine($"Motorówka: Model = {Model}, Prędkość = {Predkosc} km/h");
    }
}