#include <iostream>

/*
给你一棵以 root 为根的 二叉树 ，请你返回 任意 二叉搜索子树的最大键值和。

二叉搜索树的定义如下：

任意节点的左子树中的键值都 小于 此节点的键值。
任意节点的右子树中的键值都 大于 此节点的键值。
任意节点的左子树和右子树都是二叉搜索树。

示例 1：
输入：root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
输出：20
解释：键值为 3 的子树是和最大的二叉搜索树。

示例 2：
输入：root = [4,3,null,1,2]
输出：2
解释：键值为 2 的单节点子树是和最大的二叉搜索树。

示例 3：
输入：root = [-4,-2,-5]
输出：0
解释：所有节点键值都为负数，和最大的二叉搜索树为空。

示例 4：
输入：root = [2,1,3]
输出：6

示例 5：
输入：root = [5,4,8,3,null,6,3]
输出：7
*/

class Solution {
private:
    int maxSum = 0;
    vector<int> dfs(TreeNode* node) {
        if (!node) {
            return {1, INT_MAX, INT_MIN, 0};
        }

        vector<int> left = dfs(node->left);
        vector<int> right = dfs(node->right);

        bool isBST = left[0] && right[0] && left[2] < node->val &&
                     right[1] > node->val;

        if (!isBST) {
            return {0, 0, 0, 0};
        }

        int currSum = left[3] + right[3] + node->val;

        maxSum = max(maxSum, currSum);

        int minVal = min(node->val, left[1]);
        int maxVal = max(node->val, right[2]);

        return {1, minVal, maxVal, currSum};
    }

public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};



