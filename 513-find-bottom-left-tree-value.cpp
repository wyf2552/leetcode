/*
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

假设二叉树中至少有一个节点。

示例 1:
输入: root = [2,1,3]
输出: 1

示例 2:
输入: [1,2,3,4,null,5,6,null,null,7]
输出: 7
*/

class Solution {
private:
    int maxDepth = 0;
    int depth = 0;
    TreeNode* res = nullptr;


    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        depth++;
        if (depth > maxDepth) {
            maxDepth = depth;
            res = root;
        }
        traverse(root->left);
        traverse(root->right);
        depth--;
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        traverse(root);
        return res->val;
    }
};