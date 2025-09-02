#include <vector>

/*
给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。

你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。

示例 1：
输入：n = 13
输出：[1,10,11,12,13,2,3,4,5,6,7,8,9]

示例 2：
输入：n = 2
输出：[1,2]
*/

class Solution {

    std::vector<int> res;

public:
    std::vector<int> lexicalOrder(int n) {
        for (int i = 1; i < 10; i++) {
            traverse(i, n);
        }
        return res;
    }

    void traverse(int root, int n) {
        if (root > n) {
            return;
        }
        res.push_back(root);

        for (int child = root * 10; child < root * 10 + 10; child++) {
            traverse(child, n);
        }
    }
};