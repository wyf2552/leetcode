#include <iostream>
using namespace std;

/*
读者来到图书馆排队借还书，图书管理员使用两个书车来完成整理借还书的任务。书车中的书从下往上叠加存放，图书管理员每次只能拿取书车顶部的书。排队的读者会有两种操作：

push(bookID)：把借阅的书籍还到图书馆。
pop()：从图书馆中借出书籍。
为了保持图书的顺序，图书管理员每次取出供读者借阅的书籍是 最早 归还到图书馆的书籍。你需要返回 每次读者借出书的值 。

如果没有归还的书可以取出，返回 -1 。



示例 1：

输入：
["BookQueue", "push", "push", "pop"]
[[], [1], [2], []]
输出：[null,null,null,1]
解释：
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.pop(); // return 1, queue is [2]
*/

class CQueue {
private:
    queue<int> borrowQueue; // 借出队列
    queue<int> returnQueue; // 归还队列

public:
    CQueue() {}

    void appendTail(int value) {
        borrowQueue.push(value); // 借出的书加入借出队列
    }

    int deleteHead() {
        if (borrowQueue.empty()) {
            // 如果借出队列为空，处理归还队列
            while (!returnQueue.empty()) {
                borrowQueue.push(returnQueue.front());
                returnQueue.pop();
            }
        }
        if (borrowQueue.empty()) {
            return -1; // 如果两个队列都为空，返回 -1
        }
        int value = borrowQueue.front();
        borrowQueue.pop();
        return value;
    }
};