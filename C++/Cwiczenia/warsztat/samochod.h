#pragma once 

#include <iostream>

class Samochod{
  
private:
  std::string marka="nieznana";
  std::string model="nieznany";
  int przebieg=0;
 public:
  Samochod()=default;
  Samochod(std::string marka, std::string model, int przebieg)
     :marka(marka),model(model),przebieg(przebieg)
  {
    if(przebieg<0) 
      this->przebieg = 0;
  }
  // Samochod(std::string marka, std::string model)
  //    :marka(marka),model(model),przebieg(0)
  // {
  // }
Samochod(std::string marka, std::string model)
   : Samochod(marka,model,0)
{
}
  void wypisz() const
  {
    using namespace std;
    cout<<marka<<" "<<model<< " przebieg "<<przebieg <<" km"<<endl;
  }

int jedz(int iloscKm)
{
  if(iloscKm<0)
    iloscKm=-iloscKm;
  przebieg=przebieg+iloscKm;
  return przebieg;
}

};