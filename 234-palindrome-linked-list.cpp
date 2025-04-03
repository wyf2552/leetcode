#include <iostream>
#include <vector>

using namespace std;
/*
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

示例 1：
输入：head = [1,2,2,1]
输出：true

示例 2：
输入：head = [1,2]
输出：false
*/
class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            vector<int> vals;
            // 将链表值存入数组
            while (head != nullptr) {
                vals.push_back(head->val);
                head = head->next;
            }

            // 使用双指针判断是否回文
            for(int i = 0, j = vals.size()-1; i < j; i++, j--) {
                if(vals[i] != vals[j]) return false;
            }
            return true;
        }
    };