#include <iostream>
#include <string>
#include "Szyfr.h"

using namespace std;

int main() {
   cout << "Szyfr Cezara" << std::endl;
   string tekst = "Lubie Placki";
   Ciphers::Caeser(tekst, 2);
    return 0;
}
