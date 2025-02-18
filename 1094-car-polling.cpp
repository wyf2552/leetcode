#include <iostream>
#include <vector>

using namespace std;

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