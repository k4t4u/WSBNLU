namespace ConsoleApp25;

public abstract class DoctorBase : IDoctorManagement
{
    protected List<Doctor> Doctors = new List<Doctor>();

    public virtual void AddDoctor(Doctor doctor)
    {
        Doctors.Add(doctor);
    }

    public virtual bool RemoveDoctor(string doctorId)
    {
        for (int i = 0; i < Doctors.Count; i++)
        {
            if (Doctors[i].DoctorID == doctorId)
            {
                Doctors.RemoveAt(i);
                return true;
            }
        }
        return false;
    }


    public virtual Doctor DisplayDoctor(string doctorId)
    {
        foreach (var doctor in Doctors)
        {
            if (doctor.DoctorID == doctorId)
            {
                return doctor;
            }
        }
        return null;
    }


    public abstract bool UpdateDoctorEmail(string doctorId, string newEmail);
}