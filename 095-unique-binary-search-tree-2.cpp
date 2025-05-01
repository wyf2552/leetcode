#include <iostream>
#include <vector>

using namespace std;
/*
给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。

示例 1：

输入：n = 3
输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

示例 2：
输入：n = 1
输出：[[1]]

提示：
1 <= n <= 8
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
    public:
        vector<TreeNode*> generateTrees(int n) {
            if (n == 0) return vector<TreeNode*>();
            return generateTrees(1, n);
        }

    private:
        vector<TreeNode*> generateTrees(int start, int end) {
            vector<TreeNode*> allTrees;

            // 如果start大于end，返回包含nullptr的数组
            if (start > end) {
                allTrees.push_back(nullptr);
                return allTrees;
            }

            // 遍历每个可能的根节点
            for (int i = start; i <= end; i++) {
                // 递归生成所有可能的左子树
                vector<TreeNode*> leftSubtrees = generateTrees(start, i - 1);

                // 递归生成所有可能的右子树
                vector<TreeNode*> rightSubtrees = generateTrees(i + 1, end);

                // 组合所有可能的左右子树
                for (auto left : leftSubtrees) {
                    for (auto right : rightSubtrees) {
                        TreeNode* root = new TreeNode(i);
                        root->left = left;
                        root->right = right;
                        allTrees.push_back(root);
                    }
                }
            }

            return allTrees;
        }
    };