#include <iostream>
#include <vector>

using namespace std;
/*
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]

提示：
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};

        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;

        while (result.size() < m * n) {
            for (int j = left; j <= right && result.size() < m * n; j++) {
                result.push_back(matrix[top][j]);
            }
            top++;

            for (int i = top; i <= bottom && result.size() < m * n; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;

            for (int j = right; j >= left && result.size() < m * n; j--) {
                result.push_back(matrix[bottom][j]);
            }
            bottom--;

            for (int i = bottom; i >= top && result.size() < m * n; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        return result;
    }
};