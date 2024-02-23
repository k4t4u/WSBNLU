#include <iostream>

int
main ()
{
  int kat;
  std::cin >> kat;

  if (kat > 0 && kat < 90)
    {
      std::cout << "ostry" << std::endl;
    }
  else if (kat == 90)
    {
      std::cout << "prosty" << std::endl;
    }
  else if (kat > 90 && kat < 180)
    {
      std::cout << "rozwarty" << std::endl;
    }

  return 0;
}
