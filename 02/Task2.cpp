#include <iostream>
#include "libstemmer.h"

int main()
{
    std::string token;
    std::cout << "Input a token\n";
    std::cin >> token;

    token = normalize(token);
    isalpha(token) ? std::cout << "Normalized word: " << token : std::cout << "Token is not a word" << std::endl;
}