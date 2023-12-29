#include <gtest/gtest.h>
#include "header.hpp"
#include "vector.cpp"

int32_t arr[]{2, 3, 4, 5};
const size_t n = sizeof(arr) / sizeof(int32_t);

Vector<int32_t, n> v = arr;

// Test1 - Element access
TEST(Test1, Get_element)
{   
    ASSERT_EQ(2, v[0]);
    ASSERT_EQ(5, v[3]);
}

TEST(Test1, Front)
{
    ASSERT_EQ(2, v.front());
}

TEST(Test1, Back)
{
    ASSERT_EQ(5, v.back());
}

TEST(Test1, Data)
{
    ASSERT_EQ(&v.val[0], v.data());
    ASSERT_NE(nullptr, v.data());
}


// Test2 - Iterators
TEST(Test2, Empty)
{
    ASSERT_FALSE(v.empty());
}

TEST(Test2, Size)
{
    ASSERT_EQ(4, v.size());
}

TEST(Test2, Max_size)
{
    ASSERT_EQ(262144, v.max_size());
}

TEST(Test2, Reserve)
{
    v.reserve(100);
    ASSERT_EQ(100, v.capacity());

    v.shrink_to_fit();
    ASSERT_EQ(4, v.capacity());
}


// Test3 - Modifiers
TEST(Test3, Push_back)
{
    v.push_back(24);
    ASSERT_EQ(24, v[4]);
}

TEST(Test3, Pop_back)
{
    v.pop_back();
    ASSERT_EQ(4, v.size());
    ASSERT_NE(24, v.back());
}

TEST(Test3, Insert)
{
    int32_t *ptr1 = v.insert(v.data() + 1, 2, 0);
    ASSERT_EQ(2, v[0]);
    ASSERT_EQ(0, v[1]);
    ASSERT_EQ(0, v[2]);
    ASSERT_EQ(3, v[3]);
    ASSERT_EQ(4, v[4]);
    ASSERT_EQ(5, v[5]);
    ASSERT_EQ(6, v.size());
    ASSERT_EQ(v.data() + 1, ptr1);
}

TEST(Test3, Emplace)
{
    int32_t *ptr2 = v.emplace(v.data(), 1);
    ASSERT_EQ(1, v[0]);
}

TEST(Test3, Resize)
{
    v.resize(10, 7);
    ASSERT_EQ(7, v[7]);  
    ASSERT_EQ(7, v[8]);    
    ASSERT_EQ(7, v[9]);
}

TEST(Test3, Reverse)
{
    v.reverse();
    std::string str;
    for (int32_t i = 0; i < v.size(); i++)
        str.push_back('0' + v[i]);

    ASSERT_EQ("7775430021", str);
}


// Test4 - Copy/Move constructors and operators
TEST(Test4, Copy)
{
    Vector<int32_t, n> v1 = v, v2;
    v2 = v;

    ASSERT_TRUE(v1.size() == v2.size());
    ASSERT_TRUE(v1.capacity() == v2.capacity());

    for (int32_t i = 0; i < v1.size(); i++)
        if (v1[i] != v2[i])
            FAIL();

    ASSERT_FALSE(v1.data() == v2.data());    
}

TEST(Test4, Move)
{
    std::string str = "7775430021";
    Vector<int32_t, n> v3 = std::move(v), v4;
    ASSERT_EQ(0, v.size()); 
    ASSERT_EQ(0, v.capacity());
    ASSERT_EQ(nullptr, v.data());

    ASSERT_EQ(10, v3.size());
    for (int32_t i = 0; i < v3.size(); i++)
        if ('0' + v3[i] != str[i])
            FAIL();

    v4 = std::move(v3);
    ASSERT_EQ(0, v3.size()); 
    ASSERT_EQ(0, v3.capacity());
    ASSERT_EQ(nullptr, v3.data());    

    ASSERT_EQ(10, v4.size());
    for (int32_t j = 0; j < v4.size(); j++)
        if ('0' + v4[j] != str[j])
            FAIL();
}


// Test5 - bool specification
TEST(Test5, boolean)
{
    bool bool_arr[]{true, false, false};
    const size_t m = sizeof(bool_arr) / sizeof(bool);

    Vector<bool, m> v5 = bool_arr;
    std::string str = "100";
    for (int32_t i = 0; i < v5.num; i++)
        if ('0' + v5.val[i] != str[i])
            FAIL();
}


int main(int argc, char **argv)
{
    std::cout << "Testing..\n";

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}