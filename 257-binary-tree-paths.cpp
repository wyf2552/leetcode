#include <vector>
#include <string>
#include <sstream>

/*
给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

叶子节点 是指没有子节点的节点。

示例 1：
输入：root = [1,2,3,null,5]
输出：["1->2->5","1->3"]

示例 2：
输入：root = [1]
输出：["1"]
*/

class Solution {
private:
    vector<string> path;
    vector<string> res;

    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            path.push_back(to_string(root->val));
            res.push_back(joinPath(path));
            path.pop_back();
            return;
        }
        path.push_back(to_string(root->val));
        traverse(root->left);
        traverse(root->right);
        path.pop_back();
    }

    string joinPath(const vector<string>& path) {
        stringstream ss;
        for (size_t i = 0; i < path.size(); ++i) {
            ss << path[i];
            if (i < path.size() - 1) {
                ss << "->";
            }
        }
        return ss.str();
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        traverse(root);
        return res;
    }
};
