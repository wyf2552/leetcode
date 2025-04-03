#include <iostream>
#include <vector>

using namespace std;
/*
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。

示例 1：
输入：head = [1,2,3,4,5], left = 2, right = 4
输出：[1,4,3,2,5]

示例 2：
输入：head = [5], left = 1, right = 1
输出：[5]
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* pre = dummy;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }

        ListNode* rightNode = pre;
        for (int i = 0; i < right - left + 1; i++) {
            rightNode = rightNode->next;
        }

        ListNode* leftNode = pre->next;
        ListNode* curr = rightNode->next;

        pre->next = nullptr;
        rightNode->next = nullptr;

        reverseLinkedList(leftNode);

        pre->next = rightNode;
        leftNode->next = curr;

        return dummy->next;
    }

private:
    void reverseLinkedList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
    }
};