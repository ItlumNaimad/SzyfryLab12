#include <iostream>
#include <string>
#include "Szyfr.h"

using namespace std;

int main()
{
    cout << "Wpisz tekst do szyfru Cezara:" << std::endl;
    string tekst = "";
    getline(cin, tekst);
    string szyfr1=Ciphers::Cesar(tekst, 2);
    cout<<"Zaszyfrowana wiadomosc: "<<szyfr1<<endl;
    cout<<"Odszyfrowana wiadomosc: "<<Ciphers::Cesar(szyfr1,-2)<<endl;
    cout << "Wpisz tekst do szyfru Przestawieniowego" << std::endl;
    string tekst2 = "";
    string szyfr2="";
    getline(cin, tekst2);
    szyfr2=Ciphers::Shifting(tekst2);
    cout<<"Zaszyfrowana wiadomosc: "<<szyfr2<<endl;

    cout<<"Odszyfrowana wiadomosc: "<<Ciphers::Shifting(szyfr2);

    return 0;
}
