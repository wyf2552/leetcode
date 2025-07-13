#include <vector>
#include <stack>
#include <iostream>

/*
给定一个长度为 n 的链表 head

对于列表中的每个节点，查找下一个 更大节点 的值。也就是说，对于每个节点，找到它旁边的第一个节点的值，这个节点的值 严格大于 它的值。

返回一个整数数组 answer ，其中 answer[i] 是第 i 个节点( 从1开始 )的下一个更大的节点的值。如果第 i 个节点没有下一个更大的节点，设置 answer[i] = 0 。

示例 1：
输入：head = [2,1,5]
输出：[5,5,0]

示例 2：
输入：head = [2,7,4,3,5]
输出：[7,0,5,5,0]
*/

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        for (ListNode* p = head; p != nullptr; p = p->next) {
            nums.push_back(p->val);
        }
        vector<int> res(nums.size());
        stack<int> stk;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= nums[i]) {
                stk.pop();
            }
            res[i] = stk.empty() ? 0 : stk.top();
            stk.push(nums[i]);
        }
        return res;
    }
};