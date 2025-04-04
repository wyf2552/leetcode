#include <iostream>
#include <vector>

using namespace std;
/*
给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。
我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是「劳累的一天」。
所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。
请你返回「表现良好时间段」的最大长度。

示例 1：
输入：hours = [9,9,6,0,6,6,9]
输出：3
解释：最长的表现良好时间段是 [9,9,6]。

示例 2：
输入：hours = [6,6,6]
输出：0
*/
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();

        vector<int> presum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + (hours[i] > 8 ? 1 : -1);
        }

        stack<int> st;

        for (int i = 0; i <= n; i++) {
            if (st.empty() || presum[st.top()] > presum[i]) {
                st.push(i);
            }
        }

        int maxlen = 0;

        for (int i = n; i >= 0; i--) {
            while (!st.empty() && presum[st.top()] < presum[i]) {
                maxlen = max(maxlen, i - st.top());
                st.pop();
            }
        }
        return maxlen;
    }
};