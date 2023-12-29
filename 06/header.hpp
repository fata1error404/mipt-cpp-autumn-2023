#include <iostream>

class BigInt
{
public:
    bool IsPositive = true;
    int32_t length;
    int32_t *data;

    BigInt()
    {

    }

    BigInt(int32_t val)
    {
        int32_t k = 0;
        if (val < 0)
        {
            IsPositive = false;
            k++;
        }

        std::string str = std::to_string(val);
        length = str.length() - k;
        data = new int32_t[length];

        for (size_t i = 0; i < length; i++)
            data[i] = str[i + k] - 48;
    }

    BigInt(std::string val)
    {
        int32_t k = 0;
        if (val[0] == '-')
        {
            IsPositive = false;
            k++;
        }

        length = val.length() - k;
        data = new int32_t[length];

        for (int32_t i = 0; i < length; i++)
            data[i] = val[i + k] - 48;
    }


    // копирущий конструктор (инициализация копированием BigInt a = b;)
    BigInt(const BigInt &to_copy) : IsPositive(to_copy.IsPositive), length(to_copy.length)
    {
        data = new int32_t[to_copy.length];

        // IsPositive = to_copy.IsPositive;
        // length = to_copy.length;

        // for (int32_t i = 0; i < length; i++)
        //     data[i] = copy.data[i];

        // копирование всего массива to_copy.data в массив data по длине length
        std::copy(to_copy.data, to_copy.data + length, data);
    }


    // перемещающий констуктор
    /*BigInt(BigInt &&to_move) noexcept : IsPositive(to_move.IsPositive), length(to_move.length)
    {
        data = to_move.data;  // перемещаем текст сообщения
        to_move.data = nullptr;
    }*/


    // оператор сложения
    BigInt operator+(const BigInt &to_sum)
    {
        int32_t l1 = length, l2 = to_sum.length, n = std::max(l1, l2), add = 0, temp = 0;

        BigInt res;
        res.data = new int32_t[n];
        res.length = n;
        res.IsPositive = true;

        // сложение в столбик
        for (int32_t i = 1; i < n + 1; i++)
        {
            // учитываем разную длину чисел
            if (l1 >= i && l2 >= i)
                temp = data[l1 - i] + to_sum.data[l2 - i] + add;
            else if (l1 > l2)
                temp = data[l1 - i] + add;
            else
                temp = to_sum.data[l2 - i] + add;

            // учитываем перенос 1 в следующий столбик
            if (temp < 10)
            {
                res.data[n - i] = temp;
                add = 0;
            }
            else
            {
                res.data[n - i] = temp - 10;
                add = 1;

                // учитываем переполнение последнего порядка -> нужно увеличить размер массива на 1
                if (i == n)
                {
                    BigInt new_res;
                    new_res.data = new int32_t[n + 1];
                    new_res.length = n + 1;

                    new_res.data[0] = 1;

                    for (int32_t j = 1; j < n + 1; j++)
                        new_res.data[j] = res.data[j - 1];

                    delete[] res.data;
                    return new_res;
                }
            }
        }

        return res;
    }


    // оператор вычитания
    BigInt operator-(const BigInt &to_subtract)
    {
        int32_t l1 = length, l2 = to_subtract.length, n = std::max(l1, l2), sub = 0, temp = 0;

        BigInt res;
        res.data = new int32_t[n];
        res.length = n;

        BigInt a = *this, b = to_subtract;

        // если a < b, меняем местами
        if (*this < to_subtract)
        {
            a = to_subtract;
            b = *this;
            res.IsPositive = false;
        }

        // вычитание в столбик
        for (int32_t i = 1; i < n + 1; i++)
        {
            // учитываем разную длину чисел
            if (l1 >= i && l2 >= i)
                temp = a.data[l1 - i] - b.data[l2 - i] - sub;
            else if (l1 > l2)
                temp = a.data[l1 - i] - sub;
            else
                temp = b.data[l2 - i] - sub;

            // учитываем перенос 1 в следующий столбик
            if (temp >= 0)
            {
                res.data[n - i] = temp;
                sub = 0;
            }
            else
            {
                res.data[n - i] = temp + 10;
                sub = 1;
            }
        }

        return res;
    }


    // оператор сложения
    BigInt operator*(const BigInt &to_multiply)
    {
        BigInt res = 0;

        // умножение на ноль
        if (data[0] == 0 || to_multiply.data[0] == 0)
            return res;

        BigInt strings[to_multiply.length];
        int32_t i, j;
        for (i = 0; i < to_multiply.length; i++)
        {
            int32_t add = 0, temp = 0;
            std::string str;
            for (j = 0; j < length; j++)
            {

                temp = data[length - j - 1] * to_multiply.data[to_multiply.length - i - 1] + add;
                add = 0;
                if (temp > 9)
                {
                    add = temp / 10;
                    temp = temp % 10;
                }

                str.insert(0, 1, '0' + temp);

                if (j == length - 1 && add != 0)
                    str.insert(0, 1, '0' + add);
            }

            str.append(i, '0');

            //std::cout << str << std::endl;
            strings[i] = str;
        }

        for (int32_t l = 0; l < to_multiply.length; l++)
            res = res + strings[l];

        // определяем знак результата (- если числа разных знаков)
        if (IsPositive != to_multiply.IsPositive)
            res.IsPositive = false;

        for (int32_t m = 0; m < to_multiply.length; m++)
            delete[] strings[m].data;

        return res;
    }


    // унарный минус
    void operator^(const BigInt &to_invert)
    {
        IsPositive = IsPositive ? false : true;
    }


    // оператор сравнения 1
    bool operator==(const BigInt &to_compare)
    {
        if (length != to_compare.length)
            return false;

        for (int32_t i = 0; i < length; i++)
            if (data[i] != to_compare.data[i])
                return false;

        return true;
    }


    // оператор сравнения 2
    bool operator>(const BigInt &to_compare)
    {
        bool BothNegative = false;

        // если разные знаки
        if (IsPositive == true && to_compare.IsPositive == false)
            return true;
        else if (IsPositive == false && to_compare.IsPositive == true)
            return false;
        else if (IsPositive == false && to_compare.IsPositive == false)
            BothNegative = true;

        // если числа разной длины
        if (length > to_compare.length)
            return BothNegative ? false : true;
        else if (length < to_compare.length)
            return BothNegative ? true : false;

        for (int32_t i = 0; i < length; i++)
            if ((data[i] > to_compare.data[i] && !BothNegative) || (data[i] < to_compare.data[i] && BothNegative))
                return true;

        return false;
    }


    // оператор сравнения 3
    bool operator<(const BigInt &to_compare)
    {
        bool BothNegative = false;

        // если разные знаки
        if (IsPositive == true && to_compare.IsPositive == false)
            return false;
        else if (IsPositive == false && to_compare.IsPositive == true)
            return true;
        else if (IsPositive == false && to_compare.IsPositive == false)
            BothNegative = true;

        // если числа разной длины
        if (length > to_compare.length)
            return BothNegative ? true : false;
        else if (length < to_compare.length)
            return BothNegative ? false : true;

        for (int32_t i = 0; i < length; i++)
            if ((data[i] < to_compare.data[i] && !BothNegative) || (data[i] > to_compare.data[i] && BothNegative))
                return true;

        return false;
    }


    // вывод числа в поток std::ostream
    // перегружаем оператор <<, это позволяет объекту класса BigInt быть выводимым через std::cout
    std::ostream &operator<<(std::ostream &out)
    {
        if (IsPositive == false)
            out << "-";

        for (size_t i = 0; i < length; i++)
        {
            out << data[i];
        }

        out << "\n";
        return out;
    }


    //~BigInt()
    //{
    //    delete[] data;
    //}
};

unsigned long long getTotalSystemMemory();
std::string ArrayToStr(const BigInt &to_convert);