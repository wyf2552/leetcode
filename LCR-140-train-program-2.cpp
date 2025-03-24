#include <iostream>
#include <vector>

using namespace std;
/*
给定一个头节点head的链表用于记录仪系列核心肌群训练项目编号，请查找并返回倒数第cnt个训练项目编号

示例1:
输入：head = [2, 4, 7, 8], cnt = 1
输出：8
*/
class Solution {
public:
    int trainingPlan(ListNode* head, int cnt) {
        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; i < cnt; i++) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};