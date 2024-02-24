//
// Created by naima on 23.02.2024.
//

#include "Szyfr.h"
#define ENTER 13
#define SPACJA 32
std::string Ciphers::Cesar(std::string &message, int n)
{
    std::string zaszyfrowane;
    int dlugosc=message.length();
    // Zalecenie od chatuGPT by napewno string zmiescil
    // treść wiadomości ze string message
    zaszyfrowane.resize(dlugosc);
    char encrypted_char;
    for(int i=0; i<dlugosc; i++)
    {
        // Jeśli to jest znak spacji lub nowej linii
        // to nie zmieniaj znaku
        // Dopiero później zauważyłem że do znaku nowej lini
        // iteracja nie dotrze heh.
        if(message[i]==ENTER || message[i]==SPACJA)
        {
            zaszyfrowane[i]=message[i];
        }
        else
        {
            // Zabezpieczenie by ilosc znakow do przesuniecia
            //Znajdował się w zakresie liter alfabetu
            n=n%26;
            encrypted_char=message[i]+n;
            // Jeśli znak zaszyfrowany znajduje się po za zakresem małych liter
            // albo między zakresem dużych i małych liter ('Z' - 'a')
            // To wróć na początek zakresu liter
            // a-z 97-122  A-Z 65-90
            if (encrypted_char > 'z' || (encrypted_char > 'Z' && encrypted_char < 'a'))
            {
                encrypted_char=encrypted_char-26;
            }
            zaszyfrowane[i]=encrypted_char;
        }

    }
    return zaszyfrowane;
}

void Ciphers::Fence(std::string &message, int h)
{
    std::string fences[h];
    int i=0;
    // for bez zmiennej iteracyjnej jawnej do zbiorów danych
    // char letter - zmienna w której chcemy przechować wartość
    // message - zbiór danych z których chcemy iterować
    for(char letter : message)
    {
        fences[i] += letter;
        i = (i + 1) % h;
    }
    for(std::string fence_crypted : fences)
    {
        std::cout << fence_crypted;
    }
}