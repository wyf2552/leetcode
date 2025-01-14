#include <iostream>
#include <vector>

using namespace std;

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




}