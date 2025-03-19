#include <iostream>
#include <vector>

using namesapce std;
/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

示例 1：
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

示例 2：
输入：head = [1], n = 1
输出：[]

示例 3：
输入：head = [1,2], n = 1
输出：[1]
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 创建哑节点，避免特殊处理头节点
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // 快慢指针
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // 先让快指针移动n步
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // 同时移动快慢指针，直到快指针到达末尾
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // 删除倒数第n个节点
        slow->next = slow->next->next;

        // 获取新的头节点
        head = dummy->next;

        // 释放哑节点内存
        delete dummy;

        return head;
    }
};