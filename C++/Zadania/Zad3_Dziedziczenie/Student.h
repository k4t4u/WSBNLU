#ifndef STUDENT_H
#define STUDENT_H

#include "Osoba.h"

class Student : public Osoba 
{
protected:
    std::string kierunek;

public:
    Student(const std::string& imie, int wiek, const std::string& kierunek);

    std::string getKierunek() const;
    void setKierunek(const std::string& kierunek);

    void wypisz() const override;
};

#endif // STUDENT_H
