#include <iostream>
#include <vector>

using namespace std;
/*
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。

示例 1：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6

示例 2：
输入：lists = []
输出：[]

示例 3：
输入：lists = [[]]
输出：[]
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
    // 自定义比较函数，用于优先队列
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // 最小堆
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 创建优先队列（最小堆）
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // 将所有链表的头节点加入优先队列
        for (ListNode* list : lists) {
            if (list) pq.push(list);
        }

        // 创建哑节点
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        // 当优先队列不为空时
        while (!pq.empty()) {
            // 取出最小值节点
            ListNode* node = pq.top();
            pq.pop();

            curr->next = node;
            curr = curr->next;

            // 如果取出的节点还有后续节点，将后续节点加入优先队列
            if (node->next) {
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};