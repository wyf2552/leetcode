#include <iostream>
#include <vector>

using namespace std;
/*
传送带上的包裹必须在 days 天内从一个港口运送到另一个港口。
传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量（weights）的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。
返回能在 days 天内将传送带上的所有包裹送达的船的最低运载能力。

示例 1：
输入：weights = [1,2,3,4,5,6,7,8,9,10], days = 5
输出：15
解释：
船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
第 1 天：1, 2, 3, 4, 5
第 2 天：6, 7
第 3 天：8
第 4 天：9
第 5 天：10
请注意，货物必须按照给定的顺序装运，因此使用载重能力为 14 的船舶并将包装分成 (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) 是不允许的。

示例 2：
输入：weights = [3,2,2,4,1,4], days = 3
输出：6
解释：
船舶最低载重 6 就能够在 3 天内送达所有包裹，如下所示：
第 1 天：3, 2
第 2 天：2, 4
第 3 天：1, 4

示例 3：
输入：weights = [1,2,3,1,1], days = 4
输出：3
解释：
第 1 天：1
第 2 天：2
第 3 天：3
第 4 天：1, 1
*/
class Solution {
public:
    // 检查给定运载能力是否能在指定天数内运完货物
    bool canShip(vector<int>& weights, int days, int capacity) {
        int currentDays = 1;  // 当前需要的天数
        int currentLoad = 0;  // 当前这天的累计重量

        for (int weight : weights) {
            if (weight > capacity) return false;  // 单个货物超过运载能力

            if (currentLoad + weight > capacity) {
                currentDays++;  // 需要新的一天
                currentLoad = weight;
            } else {
                currentLoad += weight;
            }
        }

        return currentDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // 确定二分查找的范围
        int left = *max_element(weights.begin(), weights.end());  // 最小运载能力
        int right = accumulate(weights.begin(), weights.end(), 0);  // 最大运载能力

        // 二分查找
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canShip(weights, days, mid)) {
                right = mid;  // 尝试更小的运载能力
            } else {
                left = mid + 1;  // 需要更大的运载能力
            }
        }

        return left;
    }
};