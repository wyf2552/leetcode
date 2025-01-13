#include <iostream>
#include <vector>

using namespace std;

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