#include <iostream>
#include <vector>

using namespace std;
/*
给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的 排列。如果是，返回 true ；否则，返回 false 。
换句话说，s1 的排列之一是 s2 的 子串 。

示例 1：
输入：s1 = "ab" s2 = "eidbaooo"
输出：true
解释：s2 包含 s1 的排列之一 ("ba").

示例 2：
输入：s1= "ab" s2 = "eidboaoo"
输出：false
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> s1Count(26, 0);
        vector<int> windowCount(26, 0);

        for (char i = 0 ; i < s1.length(); i++) {
            char c = s1[i];
            s1Count[c - 'a']++;
        }

        for (int i = 0; i < s1.length(); i++) {
            windowCount[s2[i] - 'a']++;
        }

        if (s1Count == windowCount) {
            return true;
        }

        for (int i = s1.length(); i < s2.length(); i++) {
            windowCount[s2[i - s1.length()] - 'a']--;
            windowCount[s2[i] - 'a']++;

            if (s1Count == windowCount) {
                return true;
            }
        }
        return false;
    }
};