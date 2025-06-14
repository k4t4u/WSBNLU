namespace ConsoleApp25
{
    public class DoctorManagement : DoctorBase
    {
        public delegate void DoctorNotification(Doctor doctor);
        public event DoctorNotification DoctorAdded;
        public event DoctorNotification DoctorRemoved;

        private static int IdCounter = 1;

        public override void AddDoctor(Doctor doctor)
        {
            base.AddDoctor(doctor);
            DoctorAdded?.Invoke(doctor);
        }

        public override bool RemoveDoctor(string doctorId)
        {
            Doctor doctor = null;
            foreach (var d in Doctors)
            {
                if (d.DoctorID == doctorId)
                {
                    doctor = d;
                    break;
                }
            }

            if (doctor != null && base.RemoveDoctor(doctorId))
            {
                DoctorRemoved?.Invoke(doctor);
                return true;
            }

            return false;
        }

        public override bool UpdateDoctorEmail(string doctorId, string newEmail)
        {
            foreach (var doctor in Doctors)
            {
                if (doctor.DoctorID == doctorId)
                {
                    doctor.Email = newEmail;
                    return true;
                }
            }
            return false;
        }

        public void AddDoctor(string name, string email, string specialization)
        {
            string doctorId = "D" + IdCounter.ToString();
            IdCounter++;

            Doctor doctor = new Doctor(doctorId, name, email, specialization);
            AddDoctor(doctor);
        }
    }
}
