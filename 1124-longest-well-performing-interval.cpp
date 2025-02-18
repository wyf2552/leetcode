#include <iostream>
#include <vector>

using namespace std;

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