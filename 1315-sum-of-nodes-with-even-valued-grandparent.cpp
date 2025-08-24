/*
给你一棵二叉树，请你返回满足以下条件的所有节点的值之和：

该节点的祖父节点的值为偶数。（一个节点的祖父节点是指该节点的父节点的父节点。）
如果不存在祖父节点值为偶数的节点，那么返回 0 。

示例：
输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
输出：18
解释：图中红色节点的祖父节点的值为偶数，蓝色节点为这些红色节点的祖父节点。

*/

class Solution {
private:
    int ans = 0;

public:
    void dfs(TreeNode* grandparent, TreeNode* parent, TreeNode* node) {
        if (!node) {
            return;
        }
        if (grandparent->val % 2 == 0) {
            ans += node->val;
        }
        dfs(parent, node, node->left);
        dfs(parent, node, node->right);
    }

    int sumEvenGrandparent(TreeNode* root) {
        if (root->left) {
            dfs(root, root->left, root->left->left);
            dfs(root, root->left, root->left->right);
        }
        if (root->right) {
            dfs(root, root->right, root->right->left);
            dfs(root, root->right, root->right->right);
        }
        return ans;
    }
};
