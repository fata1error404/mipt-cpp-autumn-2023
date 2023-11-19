#include <iostream>
#include <iomanip>
#include "header.hpp"

int main()
{
    size_t n;
    Allocator *sample = NULL;

    // std::cout << "Size of Allocator structure - " << sizeof(Allocator) << " bytes\n";

    std::cout << "Enter how much memory do you want to allocate (in bytes)\n";
    std::cin >> n;

    init_allocator(&sample, n);
    sample->offset = 0;

    std::cout << "\nUsing alloc() 10 times.\n\naddress    offset\n";
    for (int i = 0; i < 10; i++)
        char *curr = alloc(sample, 10);

    reset(sample);

    clear(sample);
    delete sample;
}