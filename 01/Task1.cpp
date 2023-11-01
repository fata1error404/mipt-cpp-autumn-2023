#include <iostream>
#include <cstring>

std::string convertTextToSound(std::string text);
bool isEqual(std::string text1, std::string text2);

int main()
{
    setlocale(LC_ALL, "Russian");
    // std::string text1{"Ashcroft"}, text2{"Ashcraft"};
    std::string text1, text2;
    std::cout << "Input 2 words\n";
    std::cin >> text1 >> text2;

    text1 = convertTextToSound(text1);
    text2 = convertTextToSound(text2);

    bool compared = isEqual(text1, text2);

    // std::cout << text1 + "\n" << text2 << std::endl;
    compared ? std::cout << "Strings are equal" : std::cout << "Strings are NOT equal" << std::endl;
    return 0;
}



std::string convertTextToSound(std::string text)
{
    char first_letter = text[0];  // запоминаем первую букву слова

    for (int i = 0, n = text.length(); i < n; i++)
    {
        // удаляем все вхождения h и w
        if ((text[i] == 'h' || text[i] == 'w') && i != 0)
        {
            text.erase(i, 1);
            i--;  // возвращаемся на 1 индекс назад (почему ?)
        }
    
        // замена согласных на цифры
        if (text[i] == 'b' || text[i] == 'f' || text[i] == 'p' || text[i] == 'v')
            text[i] = 49; // 49 это 1 в кодировке ASCII, 50 - 2, ..
        else if (text[i] == 'c' || text[i] == 'g' || text[i] == 'j' || text[i] == 'k' || text[i] == 'q' || text[i] == 's' || text[i] == 'x' || text[i] == 'z')
            text[i] = 50;
        else if (text[i] == 'd' || text[i] == 't')
            text[i] = 51;
        else if (text[i] == 'l')
            text[i] = 52;
        else if (text[i] == 'm' || text[i] == 'n')
            text[i] = 53;
        else if (text[i] == 'r')
            text[i] = 54;

        // сокращение последовательности цифр до одной такой цифры
        if (isdigit(text[i]) != 0 && text[i] == text[i - 1])
        {
            text.erase(i, 1);
            i--;
        }

        // удаление гласных
        if ((text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' || text[i] == 'y') && i != 0)
        {            
            text.erase(i, 1);
            i--;
        }
    }

    text[0] = toupper(first_letter);
    int length = text.length();

    // обрезаем строку до первых 4-х символов
    text.resize(4);

    // недостающие символы заменяем 0
    if (length < 4)
        text.append(4 - length, '0');

    return text;
}



bool isEqual(std::string text1, std::string text2)
{
    int x = text1.compare(text2);
    return x == 0 ? true : false;  // если x = 0 (т.е строки эквивалентны), возвращаем true
}