#include <iostream>
// это заголовочный файл, его подключение необходимо чтобы компилятор знал как  выглядят функции в libstemmer.a
// (в нем только объявлены функции из libstemmer.a)

//! Проверка, что строка состоит только из символов латинского алфавита.
bool isalpha(const std::string& str);

//! Приводит строку в верхний регистр.
std::string toupper(const std::string& str);

//! Удаляем окончания и суффиксы.
std::string stem(const std::string& str);

//! Применяет функции toupper, isalpha и stem для получения нормализованной функции.
std::string normalize(const std::string& str);

