//
// Created by naima on 23.02.2024.
//

#include "Szyfr.h"
#define ENTER 13
#define SPACJA 32
std::string Ciphers::Caeser(std::string &message, int n)
{
    std::string zaszyfrowane;
    int dlugosc=message.length();
    for(int i=0; i<dlugosc; i++)
    {
        if(message[i]==ENTER || message[i]==SPACJA)
        {
            message[i]=message[i];
        }
        else
        {
            message[i]=message[i]+n;
            zaszyfrowane[i]=message[i];
        }

    }
}