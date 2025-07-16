#include <string>
#include <stack>
#include <algorithm>

/*
给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。

示例 1 ：
输入：num = "1432219", k = 3
输出："1219"
解释：移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219 。

示例 2 ：
输入：num = "10200", k = 1
输出："200"
解释：移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。

示例 3 ：
输入：num = "10", k = 2
输出："0"
解释：从原数字移除所有的数字，剩余为空就是 0 。
*/

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::stack<char> stk;
        for (char c : num) {
            while (!stk.empty() && c < stk.top() && k > 0) {
                stk.pop();
                k--;
            }
            if (stk.empty() && c == '0') {
                continue;
            }
            stk.push(c);
        }

        while (k > 0 && !stk.empty()) {
            stk.pop();
            k--;
        }
        if (stk.empty()) {
            return "0";
        }
        std::string result = "";
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};