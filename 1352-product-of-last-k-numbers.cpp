#include <iostream>
#include <vector>
/*
请你实现一个「数字乘积类」ProductOfNumbers，要求支持下述两种方法：

1. add(int num)
将数字 num 添加到当前数字列表的最后面。

2. getProduct(int k)
返回当前数字列表中，最后 k 个数字的乘积。
你可以假设当前列表中始终 至少 包含 k 个数字。
题目数据保证：任何时候，任一连续数字序列的乘积都在 32-bit 整数范围内，不会溢出。

示例：
输入：
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]
输出：
[null,null,null,null,null,null,20,40,0,null,32]
*/
using namespace std;

class ProductOfNumbers {
private:
    vector<int> prefix;
public:
    ProductOfNumbers() {
        prefix = {1};
    }

    void add(int num) {
        if (num == 0) {
            prefix = {1};
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= prefix.size()) {
            return 0;
        }
        return prefix.back() / prefix[prefix.size() - 1 - k];
    }
};

