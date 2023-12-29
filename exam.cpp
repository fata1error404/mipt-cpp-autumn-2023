#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


int deepestLeavesSum(TreeNode *root, int curr, int &last, int &sum)
{
    if (root == nullptr)
        return 0;

    if (curr > last)
    {
        last = curr;
        sum = root->val;
    }
    else if (curr == last)
        sum += root->val;

    int left = deepestLeavesSum(root->left, curr + 1, last, sum);
    int right = deepestLeavesSum(root->right, curr + 1, last, sum);

    return left + right;
}


int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(100);
    root->right = new TreeNode(309);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-5);
    root->right->right = new TreeNode(8);
    root->left->left->left = new TreeNode(734);
    root->right->right->right = new TreeNode(20);

    int sum = 0, last = 0;
    deepestLeavesSum(root, 0, last, sum);

    std::cout << "Сумма узлов = " << sum << std::endl;
}