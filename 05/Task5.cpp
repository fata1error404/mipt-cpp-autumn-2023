#include <iostream>
#include <cassert>
#include <random>

class Matrix
{
public:
    size_t rows;
    size_t columns;
    int32_t **data;

    // конструктор матрицы - инициализируем значения
    Matrix(size_t c, size_t r, bool random)
    {
        // выделяем память под r строк и пробегаемся по ним, внутри каждой строки повторяем тоже самое для каждого столбца столбца
        // i - строка, j - столбец
        data = new int32_t *[r];
        for (size_t i = 0; i < r; i++)
        {
            data[i] = new int32_t[c];
            for (size_t j = 0; j < c; j++)
            {
                if (random == true)
                {
                    std::random_device rd;                        // Используем random_device для генерации начального seed
                    std::mt19937 gen(rd());                       // Создаем генератор случайных чисел
                    std::uniform_int_distribution<int> dis(0, 9); // Задаем равномерное распределение от 0 до 9

                    data[i][j] = dis(gen); // Генерация случайного числа в диапазоне от 0 до 9
                }
                else
                    data[i][j] = 0;
            }
        }

        rows = r;
        columns = c;
    }

    size_t getRows() { return rows; }
    size_t getColumns() { return columns; }
    size_t getElement(size_t n, size_t m) { return data[n][m]; }

    void operator*=(int32_t C)
    {
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < columns; j++)
            {
                data[i][j] *= C;
            }
        }

        std::cout << "Multiplying matrix by " << C << std::endl;
    }

    Matrix operator+(const Matrix &to_sum)
    {
        size_t r_A = rows, r_B = to_sum.rows, c_A = columns, c_B = to_sum.columns;
        if (r_A != r_B || c_A != c_B)
        {
            std::cout << "Matrices have different dimensions!" << std::endl;
            throw std::out_of_range(""); // бросаем исключение
        }

        Matrix C(c_A, r_A, false);
        for (size_t i = 0; i < r_A; i++)
        {
            for (size_t j = 0; j < c_A; j++)
            {
                C.data[i][j] = data[i][j] + to_sum.data[i][j];
            }
        }

        return C;
    }

    bool operator==(const Matrix &to_compare)
    {
        size_t r_A = rows, r_B = to_compare.rows, c_A = columns, c_B = to_compare.columns;
        if (r_A != r_B || c_A != c_B)
            return false;

        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < columns; j++)
            {
                if (data[i][j] != to_compare.data[i][j])
                    return false;
            }
        }

        return true;
    }

    // вывод матрицы в поток std::ostream
    // перегружаем оператор <<, это позволяет объекту класса Matrix быть выводимым через std::cout
    std::ostream &operator<<(std::ostream &out)
    {
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < columns; j++)
            {
                out << data[i][j] << "  ";
                if (data[i][j] < 10)
                    out << " ";
            }
            out << "\n";
        }

        return out;
    }

    // освобождаем память
    // (почему то если это засунуть в деструктор, valgrind выдает много ошибок и варнингов, хотя все компилиуется)
    void freeMatrix()
    {
        for (size_t i = 0; i < rows; i++)
            delete[] data[i];

        delete[] data;
    }
};

int main()
{
    const size_t rows = 5;
    const size_t cols = 3;

    std::cout << "Generating 2 random matrices and 1 zero matrix" << std::endl;
    Matrix m1(cols, rows, true), m2(cols, rows, true), m3(cols, rows, false);

    std::cout << "Matrices dimensions: n = " << m1.getRows() << " rows and m = " << m1.getColumns() << " columns" << std::endl;
    std::cout << "Matrix m1:" << std::endl;
    m1 << std::cout << "\n"
       << std::endl;
    std::cout << "Matrix m2:" << std::endl;
    m2 << std::cout << "\n"
       << std::endl;
    assert(m1.getRows() == rows);
    assert(m1.getColumns() == cols);

    std::cout << "Checking element values\n element | value" << std::endl;
    std::cout << "  (1, 1)     " << m1.getElement(0, 0) << std::endl;
    std::cout << "  (5, 3)     " << m1.getElement(4, 2) << std::endl;
    std::cout << "  (3, 2)     " << m1.getElement(2, 1) << std::endl;

    std::cout << "\nAdding matrices m1 * 2 and m2" << std::endl;
    m1 *= 2;

    m3 = m1 + m2;
    m3 << std::cout;

    std::cout << "\nComparing matrices m1 and m2" << std::endl;
    if (m1 == m2)
        std::cout << "Matrices are equal!" << std::endl;
    else
        std::cout << "Matrices are not equal." << std::endl;

    bool isequal = m1.operator==(m2);
    assert(isequal == false);

    m1.freeMatrix();
    m2.freeMatrix();
    m3.freeMatrix();
}