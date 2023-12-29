#include "header.hpp"

// доступ к указанному элементу
template <typename T, size_t N>
T Vector<T, N>::operator[](int32_t i)
{
    return val[i];
}


// доступ к первому элементу
template <typename T, size_t N>
T Vector<T, N>::front()
{
    return val[0];
}


// доступ к последнему элементу
template <typename T, size_t N>
T Vector<T, N>::back()
{
    return val[num - 1];
}


// прямой доступ к основному непрерывному хранилищу
// (указатель на начало вектора)
template <typename T, size_t N>
T *Vector<T, N>::data()
{
    return (val != NULL) ? val : NULL;
}


// проверяет, пуст ли вектор
template <typename T, size_t N>
bool Vector<T, N>::empty()
{
    return (num == 0) ? true : false;
}


// возвращает количество элементов
template <typename T, size_t N>
size_t Vector<T, N>::size()
{
    return num;
}


// возвращает максимально возможное количество элементов
template <typename T, size_t N>
unsigned long long Vector<T, N>::max_size()
{
    unsigned long long HeapSize = 1 * 1024 * 1024; // размер кучи - 1МБ
    return HeapSize / sizeof(T);
}


//  резервирует место для хранения - предварительное выделение памяти для элементов вектора, без их создания
// (чтобы не перераспределять память при добавлении новых элементов)
template <typename T, size_t N>
void Vector<T, N>::reserve(size_t new_cap)
{
    // новая вместимость вектора, в количестве элементов
    if (new_cap > cap && new_cap < max_size())
    {
        T temp[num];
        std::copy(val, val + num, temp);

        delete[] val;

        cap = new_cap;
        val = new T[cap];
        std::copy(temp, temp + num, val);
    }
}


// возвращает объем общего пространства, которое имеет вектор (в количестве элементов)
template <typename T, size_t N>
size_t Vector<T, N>::capacity()
{
    return cap;
}


// уменьшает использование памяти за счет освобождения неиспользуемой памяти - понижаем capacity до size
// (аналогично reserve - перекопирование в новый массив)
template <typename T, size_t N>
void Vector<T, N>::shrink_to_fit()
{
    T temp[num];
    std::copy(val, val + num, temp);

    delete[] val;

    cap = num;
    val = new T[cap];
    std::copy(temp, temp + num, val);
}


// добавляет элемент в конец
template <typename T, size_t N>
void Vector<T, N>::push_back(T new_element)
{
    num++;
    if (num <= cap)
        val[num - 1] = new_element;
    else
    {
        T temp[num];
        std::copy(val, val + num - 1, temp);
        temp[num - 1] = new_element;

        delete[] val;

        cap++;
        val = new T[cap];
        std::copy(temp, temp + num, val);
    }
}


// удаляет последний элемент
template <typename T, size_t N>
void Vector<T, N>::pop_back()
{
    num--;
    T temp[num];
    std::copy(val, val + num, temp);

    val[num] = 0;
    delete[] val;

    val = new T[cap];
    std::copy(temp, temp + num, val);
}


/*
  вставляет элементы
    pos - указатель на положение в массиве val, перед которым будет вставлен элемент
    count - количество элементов для вставки
    value - его значение
*/
template <typename T, size_t N>
T *Vector<T, N>::insert(T *pos, int32_t count, T value)
{
    num += count;

    T temp[num];
    int32_t index = pos - val; // индекс элемента, перед которым будет вставка

    std::copy(val, pos, temp);

    for (int32_t i = 0; i < count; i++)
        temp[i + index] = value;

    for (int32_t j = index + count; j < num; j++)
        temp[j] = val[j - count];

    if (num <= cap)
        std::copy(temp, temp + num, val);
    else
    {
        delete[] val;

        cap += count;
        val = new T[cap];
        std::copy(temp, temp + num, val);
    }

    return &val[index];
}


// конструирует элемент на месте (вставляет 1 элемент в указанную позицию)
template <typename T, size_t N>
T *Vector<T, N>::emplace(T *pos, T value)
{
    num++;

    T temp[num];
    int32_t index = pos - val;

    std::copy(val, pos, temp);

    temp[index] = value;

    for (int32_t j = index + 1; j < num; j++)
        temp[j] = val[j - 1];

    if (num <= cap)
        std::copy(temp, temp + num, val);
    else
    {
        delete[] val;

        cap++;
        val = new T[cap];
        std::copy(temp, temp + num, val);
    }

    return &val[index];
}


// изменяет количество хранимых элементов
template <typename T, size_t N>
void Vector<T, N>::resize(size_t new_size, T default_value)
{
    if (new_size < num)
    {
        for (int32_t i = new_size; i < num; i++)
            val[i] = default_value;
    }
    else if (new_size > num)
    {
        int32_t to_insert = new_size - num;
        for (int32_t j = 0; j < to_insert; j++)
            push_back(default_value);
    }
}


// реверсирует вектор
template <typename T, size_t N>
void Vector<T, N>::reverse()
{
    T temp[num];
    std::copy(val, val + num, temp);

    for (int32_t i = 0; i < num; i++)
        val[i] = temp[num - i - 1];
}