#include <vector>
#include <iostream>
#include "Figura.h"


class Rysunek
{
    vector<Figura *> figury;

    public:
        void dodaj(Figura & f)
        {
            figury.push_back(&f);
        }
        void dodaj(Figura *f)
        {
            figury.push_back(f);
        }

        void narysuj() const
        {
            cout << "Rysuję: " << endl;
            for(auto f: figury)
            {
                f->print();
            }
        }

        double calkowitePole() const 
        {
            double pole = 0;
            for(auto f: figury)
            {
                pole = pole + f->getArea();
            }

            return pole;
        }

};