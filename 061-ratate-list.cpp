#include <iostream>
#include <vector>

using namespace std;

/*
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
示例 2：
输入：head = [0,1,2], k = 4
输出：[2,0,1]
提示：
链表中节点的数目在范围 [0, 500] 内
-100 <= Node.val <= 100
0 <= k <= 2 * 109
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k <= 0) {
            return head;
        }

        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            length++;
            tail = tail->next;
        }

        k = k % length;
        if (k == 0) {
            return head;
        }

        tail->next = head;
        tail = head;
        for (int i = 0; i < length - k - 1; i++) {
            tail = tail->next;
        }

        head = tail->next;
        tail->next = nullptr;

        return head;
    }
};