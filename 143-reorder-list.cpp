#include <iostream>
#include <stack>

/*
给定一个单链表 L 的头节点 head ，单链表 L 表示为：
L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1：
输入：head = [1,2,3,4]
输出：[1,4,2,3]

示例 2：
输入：head = [1,2,3,4,5]
输出：[1,5,2,4,3]
*/

class Solution{
public:
    void reorderList(ListNode* head) {
        std::stack<ListNode*> stk;
        ListNode* p = head;
        while (p != nullptr) {
            stk.push(p);
            p = p->next;
        }

        p = head;
        while(!stk.empty()) {
            ListNode* lastNode = stk.top();
            stk.pop();
            ListNode* next = p->next;
            if (lastNode == next || lastNode->next == next) {
                lastNode->next = nullptr;
                break;
            }
            p->next = lastNode;
            lastNode->next = next;
            p = next;
        }
    }
};