#include <iostream>
#include <vector>

using namespace std;
/*
给你一个字符串 s 和一个整数 k 。你可以选择字符串中的任一字符，并将其更改为任何其他大写英文字符。该操作最多可执行 k 次。
在执行上述操作后，返回 包含相同字母的最长子字符串的长度。

示例 1：
输入：s = "ABAB", k = 2
输出：4
解释：用两个'A'替换为两个'B',反之亦然。

示例 2：
输入：s = "AABABBA", k = 1
输出：4

解释：
将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
子串 "BBBB" 有最长重复字母, 答案为 4。
可能存在其他的方法来得到同样的结果。
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxcount = 0;
        int maxlen = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            count[s[right] - 'A']++;

            maxcount = max(maxcount, count[s[right] - 'A']);

            if (right - left + 1 - maxcount > k) {
                count[s[left] - 'A']--;
                left++;
            }
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};