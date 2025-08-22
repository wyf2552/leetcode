/*
在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。

如果二叉树的两个节点深度相同，但 父节点不同 ，则它们是一对堂兄弟节点。

我们给出了具有唯一值的二叉树的根节点 root ，以及树中两个不同节点的值 x 和 y 。

只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true 。否则，返回 false。

示例 1：
输入：root = [1,2,3,4], x = 4, y = 3
输出：false

示例 2：
输入：root = [1,2,3,null,4,null,5], x = 5, y = 4
输出：true

示例 3：
输入：root = [1,2,3,null,4], x = 2, y = 3
输出：false
*/

class Solution {
private:
    int x;
    TreeNode* x_parent;
    int x_depth;
    bool x_found = false;

    int y;
    TreeNode* y_parent;
    int y_depth;
    bool y_found = false;

public:
    void dfs(TreeNode* node, int depth, TreeNode* parent) {
        if (!node) {
            return;
        }

        if (node->val == x) {
            tie(x_parent, x_depth, x_found) = tuple{parent, depth, true};
        }
        else if (node->val == y) {
            tie(y_parent, y_depth, y_found) = tuple{parent, depth, true};
        }

        if (x_found && y_found) {
            return;
        }

        dfs(node->left, depth + 1, node);

        if (x_found && y_found) {
            return;
        }

        dfs(node->right, depth + 1, node);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        this->x = x;
        this->y = y;
        dfs(root, 0, nullptr);
        return x_depth == y_depth && x_parent != y_parent;
    }
};