#include <iostream>
#include <vector>

using namespace std;
/*
给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
如果不存在这样的子字符串，则返回 0。

示例 1：
输入：s = "aaabb", k = 3
输出：3
解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。

示例 2：
输入：s = "ababbc", k = 2
输出：5
解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
*/
class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxlen = 0;
        int n = s.length();

        for (int uniqueTarget = 1; uniqueTarget <= 26; uniqueTarget++) {
            vector<int> charCount(26, 0);
            int left = 0;
            int uniquecount = 0;
            int validcount = 0;

            for (int right = 0; right < n; right++) {
                if (charCount[s[right] - 'a']++ == 0) {
                    uniquecount++;
                }

                if (charCount[s[right] - 'a'] == k) {
                    validcount++;
                }

                while(uniquecount > uniqueTarget) {
                    if (charCount[s[left] - 'a'] == k) {
                        validcount--;
                    }
                    if (--charCount[s[left] - 'a'] == 0) {
                        uniquecount--;
                    }
                    left++;
                }

                if (uniquecount == uniqueTarget && uniquecount == validcount) {
                    maxlen = max(maxlen, right - left + 1);
                }
            }
        }
        return maxlen;
    }
};

