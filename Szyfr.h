//
// Created by naima on 23.02.2024.
//
#pragma once
#include <string>
#include <iostream>
void swap(char& a, char& b);
namespace Ciphers
{
    std::string Cesar(std::string &message, int n);
    //std::string Fence(std::string &message, int h);
    std::string Shifting(std::string &message);
}
namespace Deciphers
{
    //std::string deFence(std::string &crypt_message, int h);
}

