#include "header.hpp"

// Базовый случай - прекращение рекурсии
template <typename T>
std::string format(T final)
{
    fstr.clear();
    data[idx] = final;

    size_t n = data[0].length();

    for (int32_t i = 0; i <= n; i++)
    {
        if (data[0][i] == '{')
        {
            bool show_err = true;
            int32_t j = i + 1;
            std::string temp;

            while (data[0][j] != '}' && j < n && isdigit(data[0][j]))
            {   
                temp.append(1, data[0][j]);
                j++;

                if (data[0][j] == '}')
                {
                    int32_t num = stoi(temp);
                    if (num > idx - 1)
                        throw Error(0);

                    fstr.append(data[num + 1]);
                    i += temp.length() + 1;
                    show_err = false;
                }
            }

            if (show_err == true)
                throw Error(1);

            i++;
        }

        if (data[0][i] == '}')
            throw Error(2);

        fstr.append(1, data[0][i]);
    }

    fstr.erase(fstr.find('\0'));
    idx = 0;

    return fstr;
}


// Рекурсивный случай - обрабатываем первый аргумент и вызываем саму себя для обработки следующего
template <typename T, typename... Types>
std::string format(T arg1, Types... args)
{
    data[idx] = arg1;

    idx++;
    format(args...);

    return fstr;
}


// чтобы конвертировать int в строку:
// спецификация для типа int
template <typename... Types>
std::string format(int arg1, Types... args)
{
    data[idx] = std::to_string(arg1);

    idx++;
    format(args...);

    return fstr;
}


// спецификация для типа double
template <typename... Types>
std::string format(double arg1, Types... args)
{
    std::string fstr;
    data[idx] = std::to_string(arg1);

    idx++;
    format(args...);

    return fstr;
}