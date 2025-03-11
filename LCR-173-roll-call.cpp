#include <iostream>
#include <vector>

using namespace std;
/*
某班级 n 位同学的学号为 0 ~ n-1。点名结果记录于升序数组 records。假定仅有一位同学缺席，请返回他的学号。

示例 1：
输入：records = [0,1,2,3,5]
输出：4

示例 2：
输入：records = [0, 1, 2, 3, 4, 5, 6, 8]
输出：7
*/
class Solution {
public:
    int takeAttendance(vector<int>& records) {
        int left = 0;
        int right = records.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (records[mid] == mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};