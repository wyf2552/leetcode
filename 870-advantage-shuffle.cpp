#include <iostream>
#include <vector>
using namespace std;
/*
给定两个长度相等的数组 nums1 和 nums2，nums1 相对于 nums2 的优势可以用满足 nums1[i] > nums2[i] 的索引 i 的数目来描述。
返回 nums1 的 任意 排列，使其相对于 nums2 的优势最大化。

示例 1：
输入：nums1 = [2,7,11,15], nums2 = [1,10,4,11]
输出：[2,11,7,15]

示例 2：
输入：nums1 = [12,24,8,32], nums2 = [13,25,32,11]
输出：[24,32,8,12]

提示：
1 <= nums1.length <= 105
nums2.length == nums1.length
0 <= nums1[i], nums2[i] <= 109
*/
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> result(n);

        // 排序nums1
        sort(nums1.begin(), nums1.end());

        // 创建nums2的索引对
        vector<pair<int, int>> nums2Pairs(n);
        for(int i = 0; i < n; i++) {
            nums2Pairs[i] = {nums2[i], i};
        }
        // 排序nums2Pairs
        sort(nums2Pairs.begin(), nums2Pairs.end());

        deque<int> unused; // 存储未使用的nums1元素
        int j = 0;

        // 为每个nums2的元素匹配nums1中的元素
        for(int i = 0; i < n; i++) {
            // 如果当前nums1元素小于等于nums2元素，加入未使用队列
            while(j < n && nums1[j] <= nums2Pairs[i].first) {
                unused.push_back(nums1[j]);
                j++;
            }

            if(j < n) {
                // 找到了更大的值，使用它
                result[nums2Pairs[i].second] = nums1[j];
                j++;
            } else {
                // 使用未使用队列中的值
                result[nums2Pairs[i].second] = unused.front();
                unused.pop_front();
            }
        }

        return result;
    }
};