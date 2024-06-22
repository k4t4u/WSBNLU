#include <iostream>
#include <vector>

using namespace std;

class Postac 
{
protected:
    string imie;

public:
    Postac(string imie) : imie(imie) 
    {
    }

    string getImie() const 
    { 
      return imie; 
    }

    virtual void obrona() = 0;
    virtual void atak() = 0;
};

class Rycerz : public Postac 
{
public:
  Rycerz(string imie) : Postac(imie) 
  {
  }

  void obrona() override 
  {
    cout << imie << ": Stoi" << endl;
  }

  void atak() override 
  {
    cout << imie << ": Uderza" << endl;
  }
};

class Smok : public Postac 
{
public:
  Smok(string imie) : Postac(imie) 
  {
  }
  void obrona() override 
  {
    cout << imie << ": Robi unik" << endl;
  }

  void atak() override 
  {
    cout << imie << ": Rzuca ogniem" << endl;
  }
};

class Ksiezniczka : public Postac 
{
public:
  Ksiezniczka(string imie) : Postac(imie) 
  {
  }

  void obrona() override 
  {
    cout << imie << ": Unika z gracją" << endl;
  }

  void atak() override 
  {
    cout << imie << ": Krzyczy" << endl;
  }
};

void spotkanie(Postac* p1, Postac* p2) 
{
  p1->atak();
  p2->obrona();
  cout << endl << "Ruch przeciwnika: " << endl;
  p2->atak();
  p1->obrona();
}

int main() 
{
  Rycerz r("Pjoter");
  Smok s("Teodor");
  Ksiezniczka k("Kopciuszek");

  vector<Postac*> postacie = { &r, &s, &k };
  
  spotkanie(postacie[0], postacie[1]);
  cout << "________" << endl;

  spotkanie(postacie[0], postacie[2]);
  cout << "________" << endl;

  spotkanie(postacie[1], postacie[0]);
  cout << "________" << endl;

  spotkanie(postacie[1], postacie[2]);
  cout << "________" << endl;

  spotkanie(postacie[2], postacie[0]);
  cout << "________" << endl;

  spotkanie(postacie[2], postacie[1]);
  cout << "________" << endl;

    return 0;
}