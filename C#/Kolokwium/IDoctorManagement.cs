namespace ConsoleApp25;

public interface IDoctorManagement
{
    void AddDoctor(Doctor doctor);
    bool RemoveDoctor(string doctorId);
    Doctor DisplayDoctor(string doctorId);
    bool UpdateDoctorEmail(string doctorId, string newEmail);
}