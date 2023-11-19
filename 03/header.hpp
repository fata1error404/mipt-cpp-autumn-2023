#include <iostream>

struct Allocator
{
    char *address;
    size_t offset, total_size;
};

void init_allocator(Allocator **alloc, size_t maxSize);
char* alloc(Allocator *alloc, size_t size);
void reset(Allocator *alloc);
void clear(Allocator *alloc);