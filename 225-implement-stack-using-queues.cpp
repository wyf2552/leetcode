#include <iostream>
/*
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

实现 MyStack 类：

void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。


注意：

你只能使用队列的标准操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。


示例：

输入：
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 2, 2, false]

解释：
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // 返回 2
myStack.pop(); // 返回 2
myStack.empty(); // 返回 False

*/

class MyStack {
    queue<int> q;
    int top_elem = 0;

public:
    // 将元素 x 压入栈顶
    void push(int x) {
        // x 是队列的队尾，是栈的栈顶
        q.push(x);
        top_elem = x;
    }

    // 返回栈顶元素
    int top() {
        return top_elem;
    }

    // 删除栈顶的元素并返回
    int pop() {
        int size = q.size();
        // 留下队尾 2 个元素
        while (size > 2) {
            q.push(q.front());
            q.pop();
            size--;
        }
        // 记录新的队尾元素
        top_elem = q.front();
        q.push(q.front());
        q.pop();
        // 删除之前的队尾元素
        int result = q.front();
        q.pop();
        return result;
    }

    // 判断栈是否为空
    bool empty() {
        return q.empty();
    }
};