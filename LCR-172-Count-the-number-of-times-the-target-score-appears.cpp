#include <iostream>
#include <vector>

using namespace std;
/*
某班级考试成绩按非严格递增顺序记录于整数数组 scores，请返回目标成绩 target 的出现次数。

示例 1：
输入: scores = [2, 2, 3, 4, 4, 4, 5, 6, 6, 8], target = 4
输出: 3

示例 2：
输入: scores = [1, 2, 3, 5, 7, 9], target = 6
输出: 0

提示：
0 <= scores.length <= 105
-109 <= scores[i] <= 109
scores 是一个非递减数组
-109 <= target <= 109
*/
class Solution {
public:
    int countTarget(vector<int>& scores, int target) {
        if (scores.empty()) {
            return 0;
        }

        int leftBound = findBound(scores, target, true);
        if (leftBound == -1) {
            return 0;
        }

        int rightBound = findBound(scores, target, false);
        return rightBound - leftBound + 1;
    }

private:
    int findBound(vector<int>& scores, int target, bool isleft) {
        int left = 0;
        int right = scores.size() - 1;
        int bound = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (scores[mid] == target) {
                bound = mid;
                if (isleft) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (scores[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return bound;
    }
};