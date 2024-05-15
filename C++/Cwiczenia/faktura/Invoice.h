#ifndef WSB_INVOICE
#define WSB_INVOICE
#include <iostream>

class Invoice {
  const int id;
  static int lastid;
  std::string description;

public:
  Invoice(const std::string & description);
  Invoice(const Invoice& inv);

  void print() const;
  void setDescription(const std::string &description);
   const std::string &getDescription() const;
  int getId();
};
#endif //WSB_INVOICE