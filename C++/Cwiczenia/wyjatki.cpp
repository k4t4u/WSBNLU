#include <exception>
#include <iostream>
using namespace std;

int function(string a, int b) {
  std::cout << "function : \"" << a << "\", " << b << std::endl;
  if (a.size() < 2)
    throw a;
  if (b == 0)
    throw std::range_error("Dzielenie przez zero");
  if (b % 2 == 0)
    throw b;
  return a.size() % b;
}

int main() {
  string teksty[] = {"Hey!", "I", "am", "Grzegorz", "Brzeczyszczykiewicz"};
  srand(2024);
  for (const auto &tekst : teksty) {
    try {
      /// TODO: Złap wszystkie wyjątki które rzucić poniższa instrukcja.
      cout << function(tekst, rand() % 10) << endl; // (*)
    } catch (const std::range_error &e) {
      cout << "Rzucono: " << e.what() << endl;
    } catch (const string &e) {
      cout << "Rzucono: " << e << endl;
    } catch (const int &e) {
      cout << "Rzucono: " << e << endl;
    } catch (...) {
      cout << "Rzucono wyjatek." << endl;
    }
  }
}

/**
function : "Hey!", 5
4
function : "I", 3
Rzucono : tekst I
function : "am", 4
Rzucono : numer 4
function : "Grzegorz", 0
Rzucono : Dzielenie przez zero
function : "Brzeczyszczykiewicz", 9
1

*/
