// правильный ли формат возвращаемого значения функции?
// можно ли было обойтись без спецификаций для каждого типа (через if (std::is_same<T, int>::value)) ?

#include "header.hpp"
#include "format.cpp"  // исправить


int main()
{
    try
    {
        auto text = format("{1}+{1} = {{0}", 2, "one");
        std::cout << text << std::endl;
    }
    catch (Error err)
    {
        err.showError();
    }
}