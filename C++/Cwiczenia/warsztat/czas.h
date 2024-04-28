#pragma once 

#ifndef CZAS_H
#define CZAS_H

#include <iostream>
#include <iomanip>
// #include <format>

class Czas{
private:
    int godziny;
    int minuty;

public:
    Czas(int godziny=12, int minuty=0) 
      : godziny(godziny),        minuty(std::max(std::min(minuty,59),0))
     //   minuty(minuty<0?0:minuty)
    {
        if(godziny<0)
           this->godziny = 0;
        if(godziny>23)
            this->godziny = 23;
    }
    // Czas() : godziny(12),minuty(0)
    // {
    // }
    void wypisz() const
    {  
    // std::cout<< std::setfill('0') << std::setw(2)<<godziny<<":"<<std::setw(2)<<minuty<<std::endl;
      printf("%02d:%02d\n",godziny,minuty);
    //  printf("godzina = %05d,%02d",godziny, minuty);
    // std::cout << std::format("{:*>2}:{*>2}", godziny, minuty);
    }
  void wczytaj()
  {
    using namespace std;
    string tmp, h, m;
    cin >> tmp;
    h = tmp.substr(0,2);
    m = tmp.substr(3,2);
    minuty = stoi(m);
    godziny = stoi(h);

   // scanf("%d:%d",&godziny,&minuty);
    
  }
    
};

#endif