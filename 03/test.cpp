#include <iostream>
#include <gtest/gtest.h>
#include "header.hpp"

Allocator *sample = NULL;

TEST(AllocatorTest1, init_allocator_test)
{
    init_allocator(&sample, 50);
    ASSERT_TRUE(sample->address); //  Проверка, что sample->address не NULL. Тогда память была успешно выделена

    std::cout << "Memory has been initialized\n";
}

TEST(AllocatorTest2, alloc_test)
{
    int n = 10;
    char *curr[n] = {NULL};

    // для примера используем alloc 10 раз, требуя каждый раз по 10 байт памяти
    // только 5 раз такой запрос должен быть успешен, т.к в init_allocator мы выделили 50 байт памяти
    for (int i = 0; i < n; i++)
        curr[i] = alloc(sample, 10);

    ASSERT_TRUE(curr[0]);
    ASSERT_TRUE(curr[1]);
    ASSERT_TRUE(curr[2]);
    ASSERT_TRUE(curr[3]);
    ASSERT_TRUE(curr[4]);
    ASSERT_FALSE(curr[5]);
    ASSERT_FALSE(curr[6]);
    ASSERT_FALSE(curr[7]);
    ASSERT_FALSE(curr[8]);
    ASSERT_FALSE(curr[9]);

    std::cout << "Alloc works well\n";
}

TEST(AllocatorTest3, reset_test)
{
    reset(sample);
    ASSERT_EQ(0, sample->offset);

    std::cout << "Offset has been reset\n";
}

TEST(AllocatorTest4, clear_test)
{
    clear(sample);

    if (sample->address == NULL)
    {
        delete sample;
        std::cout << "All the memory has been freed\n";
        SUCCEED();
    }
    else
    {
        std::cout << "Failed to free the memory";
        FAIL();
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}