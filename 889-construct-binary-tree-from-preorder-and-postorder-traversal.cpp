#include <iostream>
#include <vector>

using namespace std;
/*
给定两个整数数组，preorder 和 postorder ，其中 preorder 是一个具有 无重复 值的二叉树的前序遍历，postorder 是同一棵树的后序遍历，重构并返回二叉树。

如果存在多个答案，您可以返回其中 任何 一个。

示例 1：
输入：preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
输出：[1,2,3,4,5,6,7]

示例 2:
输入: preorder = [1], postorder = [1]
输出: [1]
*/
class Solution {
private:
    unordered_map<int, int>postIndex;

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>&  postorder) {
        int n = preorder.size();

        for (int i = 0; i < n; i++) {
            postIndex[postorder[i]] = i;
        }

        return buildTree(preorder, postorder, 0, n - 1, 0, n - 1);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, int preStart, int preEnd, int postStart, int postEnd) {
        if (preStart > preEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        if (preStart == preEnd) {
            return root;
        }

        int leftRootVal = preorder[preStart + 1];
        int leftRootPost = postIndex[leftRootVal];

        int leftSubtreeSize = leftRootPost - postStart + 1;
        root->left = buildTree(preorder, postorder, preStart + 1, preStart + leftSubtreeSize, postStart, leftRootPost);

        root->right = buildTree(preorder, postorder, preStart + leftSubtreeSize + 1, preEnd, leftRootPost + 1, postEnd - 1);

    }
}