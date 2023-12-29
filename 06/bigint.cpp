#include "header.hpp"
#include <unistd.h>

unsigned long long getTotalSystemMemory()
{
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    return pages * page_size;
}

std::string ArrayToStr(const BigInt &to_convert)
{
    std::string str;

    for (int32_t i = 0; i < to_convert.length; i++)
        str.push_back('0' + to_convert.data[i]);
    
    if (to_convert.IsPositive == false)
        str.insert(0, 1, '-');

    return str;
}