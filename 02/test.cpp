#include <iostream>
#include <gtest/gtest.h>
#include "header.hpp"

TEST(NormalizeTest, subtest_1)
{
    // если токен несимвольный - он не должен нормализовываться
    ASSERT_EQ("d0g", normalize("d0g"));
    ASSERT_EQ("2023", normalize("2023"));

    std::cout << "Nonsymbolic tokens haven't been normalized\n" << std::endl;
}

TEST(NormalizeTest, subtest_2)
{
    // нормализуем все символьные токены
    ASSERT_EQ("INTEREST", normalize("interested"));
    ASSERT_EQ("SLOW", normalize("SlOwLy"));
    ASSERT_EQ("SYSTEM", normalize("systems"));
    ASSERT_EQ("DO", normalize("DOING"));

    ASSERT_EQ("EDLYSING", normalize("EDlySINging"));

    std::cout << "All symbolic tokens have been successfully normalized\n" << std::endl;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}