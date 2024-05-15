#include "Invoice.h"

  Invoice::Invoice(const std::string & description)
      : id(lastid), description(description) {
        lastid++;
      }
Invoice::Invoice(const Invoice& inv)
:Invoice(inv.description)
{}
//  Invoice::Invoice(const Invoice& inv)
// :id(lastid), description(inv.description)
// {
//   lastid++;
// }
  void Invoice::print() const {
    std::cout << "Faktura nr " << id << " opis : " << description << std::endl;
  }

  void Invoice::setDescription(const std::string &description) {
    this->description = description;
  }
   const std::string &Invoice::getDescription() const { return description; }
  int Invoice::getId() { return id; }

int Invoice::lastid=0;