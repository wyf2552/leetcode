#include <iostream>
#include <vector>
/*
给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。

示例 1:
输入: nums = [0,1]
输出: 2
说明: [0, 1] 是具有相同数量 0 和 1 的最长连续子数组。

示例 2:
输入: nums = [0,1,0]
输出: 2
说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。

提示：
1 <= nums.length <= 105
nums[i] 不是 0 就是 1
*/
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixSum;

        prefixSum[0] = -1;

        int sum = 0;
        int maxlen = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 1 ? 1 : -1;

            if (prefixSum.count(sum)) {
                maxlen = max(maxlen, i - prefixSum[sum]);
            } else {
                prefixSum[sum] = i;
            }
        }
        return maxlen;
    }
};