#include <iostream>
#include <vector>

using namespace std;
/*
给定两个以 非递减顺序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。
定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。

示例 1:
输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
输出: [1,2],[1,4],[1,6]
解释: 返回序列中的前 3 对数：
     [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

示例 2:
输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
输出: [1,1],[1,1]
解释: 返回序列中的前 2 对数：
     [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
*/
class Solution {
    public:
        vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
            vector<vector<int>> result;
            if (nums1.empty() || nums2.empty()) return result;

            // 定义优先队列，保存{和，nums1下标，nums2下标}
            // greater<>使其成为最小堆
            priority_queue<pair<int, pair<int, int>>,
                          vector<pair<int, pair<int, int>>>,
                          greater<pair<int, pair<int, int>>>> pq;

            // 使用set记录访问过的索引对
            set<pair<int, int>> visited;

            // 将第一对数放入队列
            pq.push({nums1[0] + nums2[0], {0, 0}});
            visited.insert({0, 0});

            // 循环k次或直到队列为空
            while (k > 0 && !pq.empty()) {
                // 取出当前最小和的数对
                auto curr = pq.top();
                pq.pop();

                int i = curr.second.first;
                int j = curr.second.second;

                // 添加到结果中
                result.push_back({nums1[i], nums2[j]});

                // 尝试添加下一个nums1元素的组合
                if (i + 1 < nums1.size() && visited.find({i + 1, j}) == visited.end()) {
                    pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                    visited.insert({i + 1, j});
                }

                // 尝试添加下一个nums2元素的组合
                if (j + 1 < nums2.size() && visited.find({i, j + 1}) == visited.end()) {
                    pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                    visited.insert({i, j + 1});
                }

                k--;
            }

            return result;
        }
    };