#include <iostream>
#include <string>
#include "Szyfr.h"

using namespace std;

int main()
{
    /*cout << "Wpisz tekst do szyfru Cezara:" << std::endl;
    string tekst = "";
    getline(cin, tekst);
    cout<<"Zaszyfrowana wiadomosc:"<<Ciphers::Cesar(tekst, 2)<<endl;
    */cout << "Wpisz tekst do szyfru Plotkowego:" << std::endl;
    string tekst2 = "";
    getline(cin, tekst2);
    Ciphers::Fence(tekst2,4);
    return 0;
}
