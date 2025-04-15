#include <iostream>
#include <vector>

using namespace std;
/*
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

示例 1:
输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]

示例 2:
输入: preorder = [-1], inorder = [-1]
输出: [-1]
*/
class Solution {
public:
    unordered_map<int, int>index;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd) {
            return nullptr;
        }
            TreeNode* root = new TreeNode(preorder[preStart]);

            int rootIndex = index(preorder[preStart]);

            int leftSubtreeSize = rootIndex - inStart;

            root->left = buildTreeHelper(preorder, inorder, preStart + 1, preStart + leftSubtreeSize, inStart, rootIndex - 1);
            root->right = buildTreeHelper(preorder, inorder, preorder + leftSubtreeSize + 1, preEnd, rootIndex + 1, inEnd);
            return root;
    }
};