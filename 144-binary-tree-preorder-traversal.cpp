#include <iostream>
#include <vector>

using namespace std;
/*
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

示例 1：
输入：root = [1,null,2,3]
输出：[1,2,3]
解释：

示例 2：
输入：root = [1,2,3,4,5,null,8,null,null,6,7,9]
输出：[1,2,4,5,6,7,3,8,9]
解释：

示例 3：
输入：root = []
输出：[]

示例 4：
输入：root = [1]
输出：[1]
*/
class Solution {
public:
    vector<int> result;

    void preorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        result.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return result;
    }
};