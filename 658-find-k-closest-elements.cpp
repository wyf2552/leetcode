#include <iostream>
#include <vector>

using namespace std;
/*
给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。
整数 a 比整数 b 更接近 x 需要满足：
|a - x| < |b - x| 或者
|a - x| == |b - x| 且 a < b

示例 1：
输入：arr = [1,2,3,4,5], k = 4, x = 3
输出：[1,2,3,4]

示例 2：
输入：arr = [1,1,2,3,4,5], k = 4, x = -1
输出：[1,1,2,3]
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (arr.size() == k) {
            return arr;
        }

        int left = 0;
        int right = arr.size() - k;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};