#include <iostream>
#include <vector>

using namespace std;
/*
给你一棵二叉树的根节点 root ，返回所有 重复的子树 。
对于同一类的重复子树，你只需要返回其中任意 一棵 的根结点即可。
如果两棵树具有 相同的结构 和 相同的结点值 ，则认为二者是 重复 的。

示例 1：
输入：root = [1,2,3,4,null,2,4,null,null,4]
输出：[[2,4],[4]]

示例 2：
输入：root = [2,1,1]
输出：[[1]]

示例 3：
输入：root = [2,2,2,3,null,3,null]
输出：[[2,3],[3]]
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // 存储结果
        vector<TreeNode*> result;
        // 存储序列化字符串出现的次数
        unordered_map<string, int> count;
        // 序列化所有子树
        serialize(root, count, result);
        return result;
    }

private:
    string serialize(TreeNode* node, unordered_map<string, int>& count, vector<TreeNode*>& result) {
        if (!node) {
            return "#";
        }

        // 构建序列化字符串
        string serial = to_string(node->val) + "," +
                        serialize(node->left, count, result) + "," +
                        serialize(node->right, count, result);

        // 更新计数并检查是否为重复子树
        count[serial]++;
        if (count[serial] == 2) {
            result.push_back(node);
        }

        return serial;
    }
};