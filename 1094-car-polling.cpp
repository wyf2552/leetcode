#include <iostream>
#include <vector>

using namespace std;
/*
车上最初有 capacity 个空座位。车 只能 向一个方向行驶（也就是说，不允许掉头或改变方向）
给定整数 capacity 和一个数组 trips ,  trip[i] = [numPassengersi, fromi, toi] 表示第 i 次旅行有 numPassengersi 乘客，接他们和放他们的位置分别是 fromi 和 toi 。这些位置是从汽车的初始位置向东的公里数。
当且仅当你可以在所有给定的行程中接送所有乘客时，返回 true，否则请返回 false。

示例 1：
输入：trips = [[2,1,5],[3,3,7]], capacity = 4
输出：false

示例 2：
输入：trips = [[2,1,5],[3,3,7]], capacity = 5
输出：true
*/
class Solution {
public:
    bool carPooling(vector<vector<int>>&trips, int capicity) {
        vector<int> diff(1001, 0);

        for (const auto& trip : trips) {
            int passgers = trip[0];
            int from = trip[1];
            int to = trip[2];

            diff[from] += passgers;
            diff[to] -= passgers;
        }

        int count = 0;
        for (int i = 0; i < 1001; i++) {
            count += diff[i];
            if (count > capicity) {
                return false;
            }
        }
        return true;
    }
};