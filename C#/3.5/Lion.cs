namespace ConsoleApp24;

public class Lion : Animal
{
    public Lion(string name, int age) : base(name, age) { }

    public override void MakeSound()
    {
        Console.WriteLine($"{Name} ryczy: Roooar!");
    }
}