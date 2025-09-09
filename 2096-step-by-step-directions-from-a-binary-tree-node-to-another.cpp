#include <string>
using namespace std;

/*
给你一棵 二叉树 的根节点 root ，这棵二叉树总共有 n 个节点。每个节点的值为 1 到 n 中的一个整数，且互不相同。给你一个整数 startValue ，表示起点节点 s 的值，和另一个不同的整数 destValue ，表示终点节点 t 的值。

请找到从节点 s 到节点 t 的 最短路径 ，并以字符串的形式返回每一步的方向。每一步用 大写 字母 'L' ，'R' 和 'U' 分别表示一种方向：

'L' 表示从一个节点前往它的 左孩子 节点。
'R' 表示从一个节点前往它的 右孩子 节点。
'U' 表示从一个节点前往它的 父 节点。
请你返回从 s 到 t 最短路径 每一步的方向。

示例 1：
输入：root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
输出："UURL"
解释：最短路径为：3 → 1 → 5 → 2 → 6 。

示例 2：
输入：root = [2,1], startValue = 2, destValue = 1
输出："L"
解释：最短路径为：2 → 1 。
*/

class Solution {
private:
    string path;
    string startPath, destPath;
    int startValue, destValue;

    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (root->val == startValue) {
            startPath = path;
        } else if (root->val == destValue) {
            destPath = path;
        }
        path.push_back('L');
        traverse(root->left);
        path.pop_back();
        path.push_back('R');
        traverse(root->right);
        path.pop_back();
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        this->startValue = startValue;
        this->destValue = destValue;
        traverse(root);
        int p = 0, m = startPath.size(), n = destPath.size();
        while (p < m && p < n && startPath[p] == destPath[p]) {
            p++;
        }
        startPath = startPath.substr(p);
        destPath = destPath.substr(p);
        startPath = string(startPath.size(), 'U');
        return startPath + destPath;
    }
};