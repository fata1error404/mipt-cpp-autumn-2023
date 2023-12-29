#include <gtest/gtest.h>
#include "header.hpp"

TEST(Test, mytree)
{
    BST<int, char> mytree;

    mytree.root = new BST<int, char>::Node(24, 'a');
    mytree.root->left = new BST<int, char>::Node(14, 'b');
    mytree.root->right = new BST<int, char>::Node(74, 'c');
    mytree.root->left->left = new BST<int, char>::Node(9, 'd');
    mytree.root->left->right = new BST<int, char>::Node(19, 'e');
    mytree.root->left->left->left = new BST<int, char>::Node(3, 'f');


    auto it1 = mytree.begin(), it2 = mytree.rbegin(), it3 = mytree.end(), it4 = mytree.rend();
    ASSERT_EQ(3, *it1);
    ASSERT_EQ(74, *it2);
    ASSERT_EQ(nullptr, it3.current);
    ASSERT_EQ(nullptr, it4.current);


    ASSERT_FALSE(mytree.empty());
    ASSERT_EQ(6, mytree.size());


    ASSERT_EQ('c', mytree[74]);
    ASSERT_EQ('f', mytree[3]);
    ASSERT_EQ(0, mytree[179]);

    ASSERT_EQ('a', mytree.at(24));
    ASSERT_EQ('b', mytree.at(14));
    try { mytree.at(2023); }
    catch (const std::out_of_range &err) { std::string err_msg = err.what(); EXPECT_EQ(err_msg, "Key not found in the BST"); }

    try { mytree.insert(2023, 'G'); }
    catch (const std::out_of_range &err) { std::string err_msg = err.what(); EXPECT_EQ(err_msg, "Unable to insert. Key already exists"); }
    mytree.insert(2024, 'F');
    ASSERT_EQ('F', mytree.find(2024));

    mytree.erase(2024);
    ASSERT_EQ( 0 , mytree.find(2024));
    ASSERT_EQ('e', mytree.find(19));

    ASSERT_TRUE(mytree.contains(9));
    ASSERT_FALSE(mytree.contains(10));

    mytree.clear();
    ASSERT_EQ(0, mytree.size());
}

int main(int argc, char **argv)
{
    std::cout << "Testing..\n";

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}