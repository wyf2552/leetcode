#include <iostream>
#include <vector>

using namespace std;
/*
给你二叉树的根结点 root ，请你将它展开为一个单链表：
展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。

示例 1：
输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [0]
输出：[0]
*/
class Solution {
public:
    void flatten(treeNode* root) {
        if (!root) {
            return;
        }

        for (int i = 1; i < list.size(); i++) {
            root->right = list[i];
            root->left = nullptr;
            root = root->right;
        }
    }

private:
    void preorderTraversal(TreeNode* root, vector<TreeNode*>& list) {
        if (!root) {
            return;
        }
        list.push_back(root);
        preorderTraversal(root->left, list);
        preorderTraversal(root->right, list);
    }
};