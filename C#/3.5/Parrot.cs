namespace ConsoleApp24;

public class Parrot : Animal
{
    public Parrot(string name, int age) : base(name, age) { }

    public override void MakeSound()
    {
        Console.WriteLine($"{Name} mówi: Ćwir ćwir!");
    }
}