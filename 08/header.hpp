#include <iostream>

#ifndef FORMAT_H
#define FORMAT_H

std::string fstr;
std::string data[100];
int32_t idx = 0;

// Обработчик ошибок (исключений)
struct Error
{
    const std::string messages[3] = {"Too few arguments", "Symbol '{' is used out of context", "Symbol '}' is used out of context"};
    int to_show;

    Error(const int &i) : to_show(i) { }

    void showError() { std::cerr << "Exception caught: " << messages[to_show] << std::endl; }
};


template <typename T>
std::string format(T final);

template <typename T, typename... Types>
std::string format(T arg1, Types... args);

template <typename... Types>
std::string format(int arg1, Types... args);

template <typename... Types>
std::string format(double arg1, Types... args);

#endif