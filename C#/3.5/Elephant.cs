namespace ConsoleApp24;

public class Elephant : Animal
{
    public Elephant(string name, int age) : base(name, age) { }

    public override void MakeSound()
    {
        Console.WriteLine($"{Name} trąbi: Prrrrrr!");
    }
}