#include <iostream>
#include <vector>

using namespace std;
/*
给定字符串 s 和字符串数组 words, 返回  words[i] 中是s的子序列的单词个数 。
字符串的 子序列 是从原始字符串中生成的新字符串，可以从中删去一些字符(可以是none)，而不改变其余字符的相对顺序。
例如， “ace” 是 “abcde” 的子序列。

示例 1:
输入: s = "abcde", words = ["a","bb","acd","ace"]
输出: 3
解释: 有三个是 s 的子序列的单词: "a", "acd", "ace"。

Example 2:
输入: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
输出: 2
*/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // 创建一个vector数组，用于存储每个字符的待处理单词
        vector<pair<int, int>> waiting[26];

        // 将所有单词的初始状态放入对应字符的等待数组中
        for (int i = 0; i < words.size(); i++) {
            char firstChar = words[i][0];
            waiting[firstChar - 'a'].push_back({i, 0});
        }

        int count = 0;

        // 遍历主字符串s
        for (char c : s) {
            // 获取当前字符对应的等待队列
            vector<pair<int, int>> curr = waiting[c - 'a'];
            waiting[c - 'a'].clear();

            // 处理当前字符的所有等待中的单词
            for (auto [wordIdx, charIdx] : curr) {
                charIdx++; // 移动到下一个字符

                if (charIdx == words[wordIdx].length()) {
                    // 如果到达单词末尾，说明匹配成功
                    count++;
                } else {
                    // 否则将单词放入下一个待匹配字符的等待队列
                    char nextChar = words[wordIdx][charIdx];
                    waiting[nextChar - 'a'].push_back({wordIdx, charIdx});
                }
            }
        }

        return count;
    }
};