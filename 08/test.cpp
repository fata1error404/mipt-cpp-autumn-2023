#include <gtest/gtest.h>
#include "header.hpp"
#include "format.cpp"

// Test1 - корректность работы
TEST(Test1, functionality)
{
    auto s1 = format("{1}+{1} = {0}", 2, "one");
    auto s2 = format("{8} any text {4} {5}", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, "num");

    std::cout << "String1 = " << s1 << std::endl;
    std::cout << "String2 = " << s2 << std::endl;

    ASSERT_EQ("one+one = 2", s1);
    ASSERT_EQ("8 any text 4 5", s2);
}

// Test2 - исключения
TEST(Test2, exceptions)
{
    try { auto s3 = format("{1}+{1} = {{0}", 2, "one"); FAIL(); }
    catch (Error err) { EXPECT_EQ(err.messages[1], "Symbol '{' is used out of context"); }

    try { auto s4 = format("{1}+{1} = 6}}}}}", 2, "one"); FAIL(); }
    catch (Error err) { EXPECT_EQ(err.messages[2], "Symbol '}' is used out of context"); }

    try { auto s5 = format("{1}+{10} = {24}", 2, "one"); FAIL(); }
    catch (Error err) { EXPECT_EQ(err.messages[0], "Too few arguments"); }
}


int main(int argc, char **argv)
{
    std::cout << "Testing..\n";

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}