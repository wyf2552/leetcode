#include <iostream>
#include <vector>

using namespace std;
/*
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

示例 1:
输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
输出：[3,9,20,null,null,15,7]

示例 2:
输入：inorder = [-1], postorder = [-1]
输出：[-1]
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
        unordered_map<int, int> index; // 存储中序遍历中值到索引的映射

    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            int n = inorder.size();
            // 建立中序遍历的值到索引的映射
            for (int i = 0; i < n; i++) {
                index[inorder[i]] = i;
            }
            return buildTreeHelper(inorder, postorder, 0, n-1, 0, n-1);
        }

        TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder,
                                int inStart, int inEnd, int postStart, int postEnd) {
            if (inStart > inEnd) {
                return nullptr;
            }

            // 后序遍历的最后一个节点是根节点
            int rootVal = postorder[postEnd];
            TreeNode* root = new TreeNode(rootVal);

            // 在中序遍历中找到根节点的位置
            int rootIndex = index[rootVal];

            // 计算左子树的节点数量
            int leftSubtreeSize = rootIndex - inStart;

            // 递归构建左子树
            root->left = buildTreeHelper(inorder, postorder,
                                       inStart, rootIndex - 1,
                                       postStart, postStart + leftSubtreeSize - 1);

            // 递归构建右子树
            root->right = buildTreeHelper(inorder, postorder,
                                        rootIndex + 1, inEnd,
                                        postStart + leftSubtreeSize, postEnd - 1);

            return root;
        }
    };