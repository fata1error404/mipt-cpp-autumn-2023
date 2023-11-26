#include "header.hpp"

// Parse - функция высшего порядка; анализирует строку, разбивая ее на символьные токены и числа
void Parse(const std::string &text, void (*str_handler)(std::string), void (*num_handler)(uint64_t))
{
    if (str_handler == NULL || num_handler == NULL)
        std::cout << "User entered a NULL pointer! Won't parse the string" << std::endl;
    else
    {
        uint64_t num;
        std::string temp;
        bool is_num = true;

        for (int i = 0, n = text.length(); i <= n; i++)
        {
            temp.push_back(text[i]);
            if ((text[i] == ' ' || i == n)) // "если текущий символ - пробел или последний в строке"
            {
                temp.pop_back();                                               // удаляем пробел (т.к он тоже записывается в я temp)
                if (temp.find_first_not_of("1234567890") == std::string::npos) // "если не найден символ отличный от 0, 1, 2,.."
                {
                    // обрабатываем исключение
                    // (temp не помещается в uint64_t)
                    try
                    {
                        num = std::stoull(temp);
                    }

                    catch (const std::out_of_range &err)
                    {
                        if (err.what())
                        {
                            is_num = false;
                            str_handler(temp);
                        }
                    }

                    if (is_num == true)
                        num_handler(num);

                    is_num = true; // зануляем для проверки следующего слова
                }
                else
                    str_handler(temp);

                temp.clear();
            }
        }
    }
}

void StringHandler(const std::string text)
{
    std::cout << "str " << text << std::endl;
}

void NumberHandler(const uint64_t num)
{
    std::cout << "num " << num << std::endl;
}