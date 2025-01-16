#include <iostream>
#include <vector>

using namespace std;
/*
给定一个二维数组 array，请返回「螺旋遍历」该数组的结果。

螺旋遍历：从左上角开始，按照 向右、向下、向左、向上 的顺序 依次 提取元素，然后再进入内部一层重复相同的步骤，直到提取完所有元素。
示例 1：
输入：array = [[1,2,3],[8,9,4],[7,6,5]]
输出：[1,2,3,4,5,6,7,8,9]
示例 2：
输入：array  = [[1,2,3,4],[12,13,14,5],[11,16,15,6],[10,9,8,7]]
输出：[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
*/

class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array) {
        if (array.empty() || array[0].empty()) return {};

        vector<int> result;
        int m = array.size();
        int n = array[0].size();

        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;

        while (result.size() < m * n) {
            for (int j = left; j < right && result.size() < m * n; j++) {
                result.push_back(array[top][j]);
            }
            top++;

            for (int i = top; i < bottom && result.size() < m * n; i++) {
                result.push_back(array[i][right]);
            }
            right--;

            for (int j = right; j >= left && result.size() < m * n; j--) {
                result.push_back(array[bottom][j]);
            }
            bottom--;

            for (int i = bottom; j >= top && result.size() < m * n; i--) {
                result.push_back(array[i][left]);
            }
            left++;
        }
        return result;
    }
};