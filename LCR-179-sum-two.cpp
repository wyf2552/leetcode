#include <iostream>
#include <vector>

using namespace std;
/*
购物车内的商品价格按照升序记录于数组 price。请在购物车中找到两个商品的价格总和刚好是 target。若存在多种情况，返回任一结果即可。

示例 1：
输入：price = [3, 9, 12, 15], target = 18
输出：[3,15] 或者 [15,3]

示例 2：
输入：price = [8, 21, 27, 34, 52, 66], target = 61
输出：[27,34] 或者 [34,27]

提示：
1 <= price.length <= 10^5
1 <= price[i] <= 10^6
1 <= target <= 2*10^6
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        int left = 0;
        int right = price.size() - 1;

        while (left < right) {
            int sum  = price[left] + price[right];

            if (sum == target) {
                return {price[left], price[right]};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};