using ConsoleApp22;

class Program
{
    static void Main(string[] args)
    {
        var generatorMotorowek = new GeneratorObiektow<Motorowka>();
        var motorowka = generatorMotorowek.Create();
        motorowka.Wyswietl();

        var generatorSamolotow = new GeneratorObiektow<Samolot>();
        var samolot = generatorSamolotow.Create();
        samolot.Wyswietl();

        var generatorPociagow = new GeneratorObiektow<Pociag>();
        var pociag = generatorPociagow.Create();
        pociag.Wyswietl();
    }
}