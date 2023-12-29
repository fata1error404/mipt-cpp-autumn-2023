// можно ли обойтись без функций helper
// неясно с end() и rend()

#include "header.hpp"


int main()
{
    BST<int, char> mytree;

    mytree.root = new BST<int, char>::Node(24, 'a');
    mytree.root->left = new BST<int, char>::Node(14, 'b');
    mytree.root->right = new BST<int, char>::Node(74, 'c');
    mytree.root->left->left = new BST<int, char>::Node(9, 'd');
    mytree.root->left->right = new BST<int, char>::Node(19, 'e');
    mytree.root->left->left->left = new BST<int, char>::Node(3, 'f');

    mytree.insert(200, 'g');
    mytree.erase(14);

    std::cout << "Дерево содержит " << mytree.size() << " узлов" << std::endl;


    auto it1 = mytree.begin(), it2 = mytree.rbegin(), it3 = mytree.end(), it4 = mytree.rend();

    std::cout << "Begin() iterator:" << *it1 << std::endl;
    std::cout << "Rbegin() iterator:" << *it2 << std::endl;
    
    mytree.clear();
}
