#include <iostream>
#include <vector>

using namespace std;
/*
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]

示例 2：
输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next;

        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* nex = nullptr;

        int length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }

        for (int i = 0; i < length / 2; i++) {
            for (int j = 1; j < k; j++) {
                nex = cur->next;
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
            }
            pre = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};