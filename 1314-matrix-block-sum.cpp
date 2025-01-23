#include <iostream>
#include <vector>
/*
给你一个 m x n 的矩阵 mat 和一个整数 k ，请你返回一个矩阵 answer ，其中每个 answer[i][j] 是所有满足下述条件的元素 mat[r][c] 的和：

i - k <= r <= i + k,
j - k <= c <= j + k 且
(r, c) 在矩阵内。
示例 1：
输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
输出：[[12,21,16],[27,45,33],[24,39,28]]
示例 2：
输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
输出：[[45,45,45],[45,45,45],[45,45,45]]
*/
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
       int m = mat.size();
       int n = mat[0].size();

       vector<vector<int>> preSum(m + 1, vector<int>(n + 1, 0));

       for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + mat[i - 1][j - 1];
            }
       }

       vector<vector<int>> answer(m, vector<int>(n, 0));

       for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int r1 = max(0, i - k);
            int c1 = max(0, j - k);
            int r2 = min(m - 1, i + k);
            int c2 = min(n - 1, j + k);

            answer[i][j] = preSum[r2 + 1][c2 + 1] - preSum[r1][c2 + 1] - preSum[r2 + 1][c1] + preSum[r1][c1];
        }
       }
       return answer;
    }
};