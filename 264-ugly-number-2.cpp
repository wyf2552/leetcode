#include <iostream>
#include <vector>

using namespace std;
/*
给你一个整数 n ，请你找出并返回第 n 个 丑数 。
丑数 就是质因子只包含 2、3 和 5 的正整数。

示例 1：
输入：n = 10
输出：12
解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。

示例 2：
输入：n = 1
输出：1
解释：1 通常被视为丑数。
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;  // 第一个丑数是1

        // 三个指针，分别指向要乘以2、3、5的数字
        int p2 = 0, p3 = 0, p5 = 0;

        for(int i = 1; i < n; i++) {
            // 计算下一个丑数的三个候选值
            int num2 = dp[p2] * 2;
            int num3 = dp[p3] * 3;
            int num5 = dp[p5] * 5;

            // 取最小值作为下一个丑数
            dp[i] = min(num2, min(num3, num5));

            // 更新指针
            if(dp[i] == num2) p2++;
            if(dp[i] == num3) p3++;
            if(dp[i] == num5) p5++;
        }

        return dp[n-1];
    }
};