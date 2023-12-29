// определение методов класса - в vector.cpp, конструкторов - в header.hpp
// как правильно компилировать без #include "vector.cpp"
// не стал делать полную спецификацию для типа bool (слишком долго)

#include "header.hpp"
#include "vector.cpp"  // исправить


int main()
{
    int32_t arr[]{2, 3, 4, 5};     
    const size_t n = sizeof(arr) / sizeof(int32_t);

    bool bool_arr[]{true, false, false};
    const size_t m = sizeof(bool_arr) / sizeof(bool);


    Vector<int32_t, n> a = arr, b;
    Vector<bool, m> c = bool_arr;

    b = std::move(a);
    b.reserve(100);
    //b.shrink_to_fit();

    b.push_back(6);

    b.reverse();
    b.pop_back();

    for (int32_t i = 0; i < b.size(); i++)
        std::cout << b[i] << " ";

    std::cout << "\n";

    std::cout << "Number of elements = " << b.size() << ", capacity = " << b.capacity() << std::endl;
    std::cout << "Pointer to data -> " << b.data() << "\n" << std::endl;

    c.PrintType();
}