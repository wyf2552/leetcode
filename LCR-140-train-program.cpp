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
    int TrainingPlan(ListNode* head, int cnt) {
        int length = 0;
        ListNode* current = head;
        while (current != nullptr) {
            lenght++;
            current = current->next;
        }

        current = head;
        for (int i = 0; i < length - cnt; i++) {
            current = current->next;
        }
        return current->val;
    }
};