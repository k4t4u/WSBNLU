#include <iostream>
#include "Invoice.h"
using namespace std;
int main() {
  Invoice inv("Komputery");
  Invoice inv2("Granaty");
  const Invoice inv3(inv2);
  inv.print();
  inv2.print();
  inv3.print();
  //	cout << "Liczba faktur : " << Invoice::getNumberOfInvoices() << endl;

  //Powinno się nie skompilować:
  //inv.getDescription() = "Ekran";

  return 0;
}

/**
 *  Spodziewane wyjście:
 *
Faktura nr 1 opis : Komputery
Faktura nr 2 opis : Granaty
Faktura nr 3 opis : Granaty
Liczba faktur : 3
 */
