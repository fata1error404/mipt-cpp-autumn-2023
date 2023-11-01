#include <iostream>

//! Проверка, что строка состоит только из символов латинского алфавита.
bool isalpha(const std::string& str)
{
    for (int i = 0, n = str.length(); i < n; i++)
        if (isalpha(str[i]) == 0)
            return false;
    
    return true;
}

//! Приводит строку в верхний регистр.
std::string toupper(const std::string& str)
{
    std::string word;

    for (int i = 0, n = str.length(); i < n; i++)
        word.push_back(toupper(str[i]));  // почему word[i] = toupper(str[i]) не работает?

    return word;
}

//! Удаляем окончания и суффиксы.
std::string stem(const std::string& str)
{
    // как сделать проще?
    int n = str.length();
    std::string s1 = "ED", s2 = "ING", s3 = "S", s4 = "LY", word = str;

    // rbegin и rend - обратные итераторы - указывают на начало и конец обратной последовательности
    // (позволяют перебирать элементы контейнера в обратном направлении)
    if (std::equal(s1.rbegin(), s1.rend(), str.rbegin()))
        word.resize(n - 2);
    else if (std::equal(s2.rbegin(), s2.rend(), str.rbegin()))
        word.resize(n - 3);
    else if (std::equal(s3.rbegin(), s3.rend(), str.rbegin()))
        word.resize(n - 1);
    else if (std::equal(s4.rbegin(), s4.rend(), str.rbegin()))
        word.resize(n - 2);

    return word;
}

//! Применяет функции toupper, isalpha и stem для получения нормализованной функции.
std::string normalize(const std::string& str)
{
    return isalpha(str) ? stem(toupper(str)) : str;
}