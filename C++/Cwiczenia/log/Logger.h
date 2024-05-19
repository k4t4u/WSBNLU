#include <string>
#include <iostream>

enum Level{INFO, WARN, ERROR};

class Logger{
  protected:
    Level level = ERROR;
  public:
    void setLogLevel(Level level){
      this->level = level;
    }
    Level getLogLevel()const {
      return level;
    }
    virtual void log(Level logLevel, std::string msg) = 0;
};

class CoutLogger : public Logger{

  void log(Level logLevel, std::string msg){
    if(logLevel >= level)
      std::cout << msg << std::endl;
  }

};

class CoutLogger2 : public Logger{

  void log(Level logLevel, std::string msg){
    if(logLevel >= level)
      std::cout << "****" << msg << "***"<< std::endl;
  }

};