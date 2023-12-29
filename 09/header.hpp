#include <iostream>

template <typename Key, typename T>
class BST
{
public:
    struct Node
    {
        Key key;
        T val;
        Node *left;
        Node *right;

        Node(const Key &k, const T &v) : key(k), val(v), left(nullptr), right(nullptr) {}
    };

    Node *root, *ptr, *parent;
    size_t N = 6;

    BST() : root(nullptr), ptr(nullptr) {}


    // доступ к указанному элементу (или вставка нулевого элемента если не найден)
    T operator[](const Key &to_access)
    {
        T res = find(to_access);
        if (res == 0)
            insert(to_access, 0);

        return res;
    }


    // доступ к указанному элементу
    T at(const Key &to_access)
    {
        T res = find(to_access);
        if (res == 0)
            throw std::out_of_range("Key not found in the BST");

        return res;
    }


    // вставка элемента (key, value)
    void insert(const Key &to_insert, const T &new_element)
    {
        Node *newNode = new Node(to_insert, new_element);
        if (root == nullptr)
            root = newNode;
        else
        {
            Node *current = root;
            while (true)
            {
                if (to_insert < current->key)
                {
                    if (current->left == nullptr)
                    {
                        current->left = newNode;
                        break;
                    }
                    else
                        current = current->left;
                }
                else if (to_insert > current->key)
                {
                    if (current->right == nullptr)
                    {
                        current->right = newNode;
                        break;
                    }
                    else
                        current = current->right;
                }
                else
                {
                    delete newNode;
                    throw std::invalid_argument("Unable to insert. Key already exists");
                }
            }
        }

        N++;
    }


    // стирает 1 элемент дерева
    int erase(const Key &to_remove)
    {
        Node *current = root;
        Node *parent = nullptr;

        while (current != nullptr && current->key != to_remove)
        {
            parent = current;
            if (to_remove < current->key)
                current = current->left;
            else
                current = current->right;
        }

        if (current == nullptr)
            return 0;

        if (current->left == nullptr && current->right == nullptr)
        {
            if (parent == nullptr)
                root = nullptr;
            else if (to_remove < parent->key)
                parent->left = nullptr;
            else
                parent->right = nullptr;

            delete current;
        }
        else if (current->left == nullptr)
        {
            if (parent == nullptr)
                root = current->right;
            else if (to_remove < parent->key)
                parent->left = current->right;
            else
                parent->right = current->right;

            delete current;
        }
        else if (current->right == nullptr)
        {
            if (parent == nullptr)
                root = current->left;
            else if (to_remove < parent->key)
                parent->left = current->left;
            else
                parent->right = current->left;

            delete current;
        }
        else
        {
            Node *successor = current->right;
            while (successor->left != nullptr)
                successor = successor->left;

            Key newKey = successor->key;
            T newVal = successor->val;
            erase(successor->key);
            current->key = newKey;
            current->val = newVal;
        }

        N--;
        return 1;
    }


    // находит элемент с определенным ключом
    T find(const Key &to_find)
    {
        T found = findHelper(root, to_find);
        return found;
    }

    T findHelper(Node *curr, const Key &to_find)
    {
        if (curr == nullptr)
            return 0;

        if (curr->key == to_find)
        {
            ptr = curr;
            return curr->val;
        }

        parent = curr;

        if (to_find < curr->key)
            return findHelper(curr->left, to_find);
        else
            return findHelper(curr->right, to_find);
    }


    // проверяет, содержит ли дерево элемент с определенным ключом
    bool contains(const Key &to_check)
    {
        return find(to_check) != 0;
    }


    // проверяет, пусто ли дерево
    bool empty()
    {
        return N == 0;
    }


    // возвращает количество элементов в дереве
    size_t size()
    {
        return N;
    }


    // очищает содержимое дерева
    void clear()
    {
        clearHelper(root);
        root = nullptr;
        N = 0;
    }

    void clearHelper(Node *node)
    {
        if (node != nullptr)
        {
            clearHelper(node->left);
            clearHelper(node->right);
            delete node;
        }
    }


    // _________
    // Итераторы
    class Iterator : public std::iterator<std::input_iterator_tag, Node>
    {
    public:
        Node *current;
        explicit Iterator(Node *node) : current(node) {}

        const Key &operator*() const { return current->key; }
    };


    // первый элемент (крайний левый)
    Iterator begin()
    {
        Node *current = root;
        while (current != nullptr && current->left != nullptr)
            current = current->left;

        return Iterator(current);
    }


    // последний элемент (крайний правый)
    Iterator rbegin()
    {
        Node *current = root;
        while (current != nullptr && current->right != nullptr)
            current = current->right;

        return Iterator(current);
    }


    // итератор элемента после последнего - nullptr
    Iterator end()
    {
        Node *current = root;
        while (current != nullptr && current->right != nullptr)
            current = current->right;

        current = current->right;

        return Iterator(nullptr);
    }


    // итератор элемента до первого - nullptr
    Iterator rend()
    {
        Node *current = root;
        while (current != nullptr && current->left != nullptr)
            current = current->left;

        current = current->left;

        return Iterator(nullptr);
    }
};