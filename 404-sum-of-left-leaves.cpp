/*
给定二叉树的根节点 root ，返回所有左叶子之和。

示例 1：
输入: root = [3,9,20,null,null,15,7]
输出: 24
解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

示例 2:
输入: root = [1]
输出: 0
*/

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        traverse(root);
        return sum;
    }

    int sum = 0;
    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            sum += root->left->val;
        }

        traverse(root->left);
        traverse(root->right);
    }
};

   