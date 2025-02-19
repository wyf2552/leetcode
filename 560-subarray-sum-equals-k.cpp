#include <iostream>
#include <vector>

using namespace std;

/*
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
子数组是数组中元素的连续非空序列。

示例 1：
输入：nums = [1,1,1], k = 2
输出：2

示例 2：
输入：nums = [1,2,3], k = 3
输出：2

提示：
1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

class Solution {
public:
    int subarraysum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0;
        int presum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            presum += nums[i];

            if (mp.find(presum) != mp.end()) {
                count += mp[presum - k];
            }

            mp[presum]++;
        }
        return count;
    }
};

