#include <gtest/gtest.h>
#include "header.hpp"

BigInt a = -6, b("123456789012345678901234567890"), c("2384203"), d = 11, e = 25, f = 0, g, h, i;


TEST(Sum, test)
{
    g = e + d;
    h = f + f;
    i = b + c;

    for (int32_t z = 0; z < g.length; z++)
        std::cout << *g.data << " " << std::endl;

    std::cout << "\n";

    //std::cout << g.data[0] << "\n" << std::endl;

    //ASSERT_EQ("36", ArrayToStr(g));
    ASSERT_EQ("0", ArrayToStr(h));
    ASSERT_EQ("123456789012345678901236952093", ArrayToStr(i));
}

TEST(Subtract, test)
{
    g = d - e;
    h = b - c;
    i = f - f;

    ASSERT_EQ("-14", ArrayToStr(g));
    ASSERT_EQ("123456789012345678901232183687", ArrayToStr(h));
    ASSERT_EQ("0", ArrayToStr(i));
}

TEST(Multiply, test)
{
    g = a * c;
    h = f * b;
    i = d * e;

    ASSERT_EQ("-14305218", ArrayToStr(g));
    ASSERT_EQ("0", ArrayToStr(h));
    ASSERT_EQ("275", ArrayToStr(i));
}

TEST(Compare, test)
{
    ASSERT_TRUE(d < e);
    ASSERT_TRUE(b > c);
    ASSERT_TRUE(a < f);
    ASSERT_TRUE(a == a);
    ASSERT_FALSE(e == c);
    ASSERT_FALSE(d == f);
    ASSERT_FALSE(f > e);
}

TEST(Unary_minus, test)
{
    b ^ b;
    a ^ a;
    ASSERT_EQ("-123456789012345678901234567890", ArrayToStr(b));
    ASSERT_EQ("6", ArrayToStr(a));   
}

TEST(Copy, test)
{
    BigInt j = a;
    ASSERT_EQ(ArrayToStr(a), ArrayToStr(j));  
}

int main(int argc, char **argv)
{
    std::cout << "Checking.." << std::endl;
    b << std::cout; 

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}