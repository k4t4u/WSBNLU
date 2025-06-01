namespace ConsoleApp22;

public class GeneratorObiektow<T> where T : IMaszyna, new()
{
    public T Create()
    {
        return new T();
    }
}