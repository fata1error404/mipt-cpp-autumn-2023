#include <iostream>

#ifndef VECTOR_H
#define VECTOR_H

template <typename T, size_t N>
class Vector
{
public:
    T *val = NULL;
    size_t num = 0, cap = 0;

    Vector()
    {

    }

    Vector(T *arr)
    {
        num = N;
        cap = N;
        val = new T[num];
        std::copy(arr, arr + num, val);
    }


    // копирущий конструктор
    Vector(const Vector &to_copy) : num(to_copy.num), cap(to_copy.cap)
    {
        val = new T[to_copy.num];

        std::copy(to_copy.val, to_copy.val + num, val);
    }


    // оператор копирующего присваивания
    Vector &operator=(const Vector &to_copy)
    {
        // избегаем самоприсваивания
        if (to_copy.val != val)
        {
            num = to_copy.num;
            cap = to_copy.cap;
            val = new T[cap];
            std::copy(to_copy.val, to_copy.val + num, val);
        }

        return *this;
    }


    // перемещающий конструктор
    Vector(Vector &&to_move) noexcept : num(to_move.num), cap(to_move.cap)
    {
        val = to_move.val;

        to_move.val = NULL;
        to_move.num = 0;
        to_move.cap = 0;
    }


    // оператор назначения перемещения
    Vector &operator=(Vector &&to_move)
    {
        if (to_move.val != val)
        {
            num = to_move.num;
            cap = to_move.cap;
            val = to_move.val;

            to_move.val = NULL;
            to_move.num = 0;
            to_move.cap = 0;
        }

        return *this;
    }

    T operator[](int32_t i);

    T front();

    T back();

    T *data();

    bool empty();

    size_t size();

    unsigned long long max_size();

    void reserve(size_t new_cap);

    size_t capacity();

    void shrink_to_fit();

    void push_back(T new_element);

    void pop_back();

    T *insert(T *pos, int32_t count, T value);

    T *emplace(T *pos, T value);

    void resize(size_t new_size, T default_value);

    void reverse();

    ~Vector()
    {
        delete[] val;
    }
};


template <size_t N>
class Vector<bool, N>
{
public:
    int32_t *val = NULL;
    size_t num = 0, cap = 0;

    Vector(bool *arr)
    {
        num = N;
        cap = N;
        val = new int32_t[num];
        for (int32_t i = 0; i < num; i++)
            (arr[i] == true) ? val[i] = 1 : val[i] = 0;
    }

    void PrintType() {
        std::cout << "Type: Bool with size " << num << std::endl;
        for (int32_t i = 0; i < num; i++)
            std::cout << val[i] << " ";

        std::cout << "\n";
    }
};

#endif