#include <iostream>
#include <vector>
/*
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1：
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]

示例 2：
输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]

提示：
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums 已按 非递减顺序 排序
*/
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int left = 0;
        int right = n - 1;
        int pos = n - 1;

        while (left <= right) {
            int leftsquares = nums[left] * nums[left];
            int rightsquares = nums[right] * nums[right];

            if (leftsquares > rightsquares) {
                result[pos] = leftsquares;
                left++;
            } else {
                result[pos] = rightsquares;
                right--;
            }
            pos--;
        }
        return result;
    }
};