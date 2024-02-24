//
// Created by naima on 23.02.2024.
//

#include "Szyfr.h"
#define ENTER 13
#define SPACJA 32
void swap(char&a, char&b)
{
    char temporary = a;
    a=b;
    b=temporary;
}

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

std::string Shifting(std::string &message)
{
    int dlugosc=message.length();
    for(int i=0; i<dlugosc; i+=2)
    {
        swap(message[i],message[i+1]);
    }
    return message;
}
/*
std::string Ciphers::Fence(std::string &message, int h)
{
    std::string crypted;
    // Tworzenie h pustych stringów
    std::vector<std::string> fences(h, "");
    int i = 0;
    int direction = 1;
    // Iteracja bez jawnej zmiennej iteracyjnej
    // char letter - zmienna którą będziemy wyświetlać w for'ze
    // message - zmienna struktury danych, z której można pobierać kolejno
    // elementy rosnąco z indeksów
    for(char letter : message)
    {
        fences[i] += letter;
        i += direction;
        // Kierunek zmiany wierszy powinien iść z góry na dół i z dołu do góry
        // Wcześniej nie uwzględniłem tego w swoim kodzie i dlatego pojawiały się błędy
        if (i == 0 || i == h - 1)
        {
            direction = -direction;
        }
    }
    for(const std::string& fence_crypted : fences)
    {
        crypted += fence_crypted;
    }
    return crypted;
}
std::string Deciphers::deFence(std::string &crypt_message, int h)
{
    std::string decrypted_message;
    int fragment_length = (crypt_message.length() + h - 1) / h;

    std::vector<std::string> fences(h, "");
    int i = 0;
    int direction = 1;
    for(char letter : crypt_message)
    {
        fences[i] += letter;
        i += direction;
        // Znowu uwzględnienie kierunku
        if (i == 0 || i == h - 1)
        {
            direction = -direction;
        }
    }
    for(int j = 0; j < fragment_length; ++j)
    {
        for(const std::string& fence_crypted : fences)
        {
            // Dodanie j-tego znaku z każdego elementu tablicy fences do odszyfrowanej wiadomości
            if (j < fence_crypted.length())
            {
                decrypted_message += fence_crypted[j];
            }
        }
    }
    return decrypted_message;
}
*/