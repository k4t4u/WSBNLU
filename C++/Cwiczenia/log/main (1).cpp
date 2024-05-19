#include <iostream>
#include "Logger.h"

CoutLogger2 log;

Logger & getLogger(){
    return log;
}

int main() {

  Logger & log = getLogger();
  
  log.setLogLevel(ERROR);
  
  log.log(WARN, "Message");

  log.log(ERROR, "Powazna blad!");
  
}