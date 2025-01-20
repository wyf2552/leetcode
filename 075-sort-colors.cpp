#include <iostream>
#include <vector>

/*
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地 对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
必须在不使用库内置的 sort 函数的情况下解决这个问题。
示例 1：
输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]
示例 2：
输入：nums = [2,0,1]
输出：[0,1,2]
*/
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int curr = 0;

        while (curr <= right) {
            if (nums[curr] == 0) {
                swap(nums[left], nums[curr]);
                left++;
                curr++;
            } else if (nums[curr] == 2) {
                swap(nums[right], nums[curr]);
                right--;
            } else {
                curr++;
            }
        }
    }
};