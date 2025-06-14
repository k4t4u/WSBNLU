namespace ConsoleApp25;

public class Doctor
{
    public string DoctorID { get; set; }
    public string Name { get; set; }
    public string Email { get; set; }
    public string Specialization { get; set; }
    
    public Doctor()
    {
        DoctorID = string.Empty;
        Name = string.Empty;
        Email = string.Empty;
        Specialization = string.Empty;
    }
    
    public Doctor(string doctorID, string name, string email, string specialization)
    {
        DoctorID = doctorID;
        Name = name;
        Email = email;
        Specialization = specialization;
    }

    public override string ToString()
    {
        return $"ID: {DoctorID}, Name: {Name}, Email: {Email}, Specialization: {Specialization}";
    }
}