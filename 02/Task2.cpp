#include <iostream>
#include "header.hpp"

// 1. g++ -c stemmer.cpp  - компилируем библиотеку без компоновки (создается файл stemmer.o)
// 2. ar rc libstemmer.a stemmer.o  - создаем статическую библиотеку из объектного файла
// 3. g++ -o Task2 Task2.cpp -lstemmer -L./  - компилируем цель и подключаем библиотеку libstemmer.a

int main()
{
    std::string token;
    std::cout << "Input a token\n";
    std::cin >> token;

    token = normalize(token);
    isalpha(token) ? std::cout << "Normalized word: " << token : std::cout << "Token is not a word" << std::endl;
}