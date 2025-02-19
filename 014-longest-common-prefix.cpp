#include <iostream>
#include <vector>
/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 "。

示例 1：
输入：strs = ["flower","flow","flight"]
输出："fl"

示例 2：
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
*/
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        string prefix = strs[0];

        for (int i = 0; i < strs.size(); i++) {
            while (strs[i].substr(0, prefix.length()) != prefix) {
                prefix = prefix.substr(0, prefix.length() - 1);

                if (prefix.empty()) {
                    return "";
                }
            }
        }
        return prefix;
    }
};