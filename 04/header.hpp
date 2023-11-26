#include <iostream>

// Нужно ли при декларации функции указывать имена прототипов переменных?
void Parse(const std::string &text, void (*)(std::string), void (*)(uint64_t));
void StringHandler(const std::string text);
void NumberHandler(const uint64_t num);