#include <iostream>
#include <vector>

using namespace std;

/*
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
示例 1：
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]

示例 2：
输入：n = 1
输出：[[1]]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;

        int num = 1;

        while (num <= n * n) {
            for (int j = left; j <= right && num <= n * n; j++) {
                matrix[top][j] = num++;
            }
            top++;

            for (int i = top; i <= bottom && num <= n * n; i++) {
                matrix[i][right] = num++;
            }
            right--;

            for (int j = right; j >= left && num <= n * n; j--) {
                matrix[bottom][j] = num++;
            }
            bottom--;

            for (int i = bottom; i >= top && num <= n * n; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
        return matrix;
    }
};