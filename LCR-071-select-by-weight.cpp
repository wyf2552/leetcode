#include <iostream>
#include <vector>

using namespace std;
/*
给定一个正整数数组 w ，其中 w[i] 代表下标 i 的权重（下标从 0 开始），请写一个函数 pickIndex ，它可以随机地获取下标 i，选取下标 i 的概率与 w[i] 成正比。
例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），而选取下标 1 的概率为 3 / (1 + 3) = 0.75（即，75%）。
也就是说，选取下标 i 的概率为 w[i] / sum(w) 。

示例 1：
输入：
inputs = ["Solution","pickIndex"]
inputs = [[[1]],[]]
输出：
[null,0]
解释：
Solution solution = new Solution([1]);
solution.pickIndex(); // 返回 0，因为数组中只有一个元素，所以唯一的选择是返回下标 0。

示例 2：
输入：
inputs = ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
inputs = [[[1,3]],[],[],[],[],[]]
输出：
[null,1,1,1,1,0]
解释：
Solution solution = new Solution([1, 3]);
solution.pickIndex(); // 返回 1，返回下标 1，返回该下标概率为 3/4 。
solution.pickIndex(); // 返回 1
solution.pickIndex(); // 返回 1
solution.pickIndex(); // 返回 1
solution.pickIndex(); // 返回 0，返回下标 0，返回该下标概率为 1/4 。

由于这是一个随机问题，允许多个答案，因此下列输出都可以被认为是正确的:
[null,1,1,1,1,0]
[null,1,1,1,1,1]
[null,1,1,1,0,0]
[null,1,1,1,0,1]
[null,1,0,1,0,0]
......
诸若此类。
*/
class Solution {
private:
    vector<int> preSum;  // 前缀和数组
    int total;          // 总权重

public:
    Solution(vector<int>& w) {
        // 计算前缀和
        preSum = w;
        for(int i = 1; i < w.size(); i++) {
            preSum[i] += preSum[i-1];
        }
        total = preSum.back();
    }

    int pickIndex() {
        // 生成1到total的随机数
        int randNum = rand() % total + 1;

        // 二分查找第一个大于等于randNum的前缀和位置
        int left = 0, right = preSum.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(preSum[mid] >= randNum) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};