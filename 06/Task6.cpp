// не реализовал сложение и вычитание отрицательных чисел
// не реализовал перемещающий конструктор - возникает ошибка
// проблема с деструктором (вместо него написал отдельный метод для освобождения памяти)

#include "header.hpp"


int main()
{
    unsigned long long memory = getTotalSystemMemory();
    std::cout << "Available memory:  " << memory << " Bytes" << std::endl;

    BigInt a = -1, b("123456789012345678901234567890"), c("-2384203"), d("5342342"), e, f = 1, g = 2;

    e = f + g;
    e << std::cout;
}