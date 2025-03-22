#include <iostream>
#include <vector>

using namespace std;
/*
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
你应当 保留 两个分区中每个节点的初始相对位置。

示例 1：
输入：head = [1,4,3,2,5,2], x = 3
输出：[1,2,2,4,3,5]

示例 2：
输入：head = [2,1], x = 2
输出：[1,2]
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);

        ListNode* smallCurrent = small;
        ListNode* largeCurrent = large;

        while (head != nullptr) {
            if (head->val < x) {
                smallCurrent->next = head;
                smallCurrent = smallCurrent->next;
            } else {
                largeCurrent->next = head;
                largeCurrent = largeCurrent->next;
            }
            head = head->next;
        }
        smallCurrent->next = large->next;
        largeCurrent->next = nullptr;

        ListNode* result = small->next;
        delete small;
        delete large;

        return result;
    }
};