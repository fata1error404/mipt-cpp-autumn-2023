#include "header.hpp"

// инициализирует блок памяти
void init_allocator(Allocator **alloc, size_t maxSize)
{  
    // Если ранее выделялась память, освобождаем ее
    if (*alloc != NULL) 
        delete *alloc;


    *alloc = new Allocator; 

    (*alloc)->address = new char[maxSize];
    (*alloc)->total_size = maxSize;

    std::cout << "\nAddress of allocated memory: " << reinterpret_cast<void*>((*alloc)->address) << std::endl;
    std::cout << "Size of allocated memory in bytes: " << maxSize << "\n\n";
}

// возвращает пользователю адрес на блок памяти
char* alloc(Allocator *alloc, size_t size)
{
    if (alloc->total_size >= alloc->offset + size)
    {
        //std::string str = std::to_string((unsigned long long)(Allocator*)alloc);
        //int str_dec = std::stoll(str, nullptr, 16);

        //std::stringstream stream;
        //stream << "0x" << std::hex << str_dec;
        //std::string str_hex = stream.str();


        //std::cout << str << std::endl;
        //std::cout << "Converted value: " << str_hex << std::endl;

        //char *address = (char*)alloc;
        // char *address = reinterpret_cast<char*>(alloc);
        char *ptr = alloc->address + alloc->offset;
        std::cout << reinterpret_cast<void*>(ptr) << "  " << alloc->offset << std::endl;

        alloc->offset += size;

        return ptr;
    }
    else
    {
        std::cout << "Allocation failure.\n";
        return NULL;
    }
}

// сбрасывает сдвиг до начального значения
void reset(Allocator *alloc)
{
    alloc->offset = 0;
}

// освобождает всю память выделенную init_allocator
void clear(Allocator *alloc)
{
    delete[] alloc->address;
    alloc->address = NULL;
}