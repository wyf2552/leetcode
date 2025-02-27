#include <iostream>
#include <vector>

using namespace std;
/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：
对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。

示例 1：
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。

示例 2：
输入：s = "a", t = "a"
输出："a"
解释：整个字符串 s 是最小覆盖子串。

示例 3:
输入: s = "a", t = "aa"
输出: ""

解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。
*/

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for (int i = 0; i < t.length(); i++) {
            char c = t[i];
            map[c]++;
        }

        int counter = t.length(); // 需要匹配的字符数
        int start = 0, end = 0;
        int minStart = 0, minLen = INT_MAX;

        while (end < s.length()) {
            // 如果当前字符在t中，减少counter
            if (map[s[end]] > 0) {
                counter--;
            }
            map[s[end]]--;
            end++;

            // 当找到可行解
            while (counter == 0) {
                if (end - start < minLen) {
                    minStart = start;
                    minLen = end - start;
                }

                // 移动左指针
                map[s[start]]++;
                if (map[s[start]] > 0) {
                    counter++;
                }
                start++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};