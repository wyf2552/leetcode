#include <iostream>
#include <vector>
#include <stdexcept>
#include <optional>

/*
设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：

MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。


示例：
MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
circularQueue.enQueue(1);  // 返回 true
circularQueue.enQueue(2);  // 返回 true
circularQueue.enQueue(3);  // 返回 true
circularQueue.enQueue(4);  // 返回 false，队列已满
circularQueue.Rear();  // 返回 3
circularQueue.isFull();  // 返回 true
circularQueue.deQueue();  // 返回 true
circularQueue.enQueue(4);  // 返回 true
circularQueue.Rear();  // 返回 4
*/


template<typename E>
class ArrayQueue {
private:
    int size;
    std::vector<std::optional<E>> data;
    static const int INIT_CAP = 2;
    int first, last;

    void resize(int newCap) {
        std::vector<std::optional<E>> temp(newCap);

        for (int i = 0; i < size; i++) {
            temp[i] = data[(first + i) % data.size()];
        }

        first = 0;
        last = size;
        data = std::move(temp);
    }

public:
    ArrayQueue(int initCap) : size(0), data(initCap), first(0), last(0) {}

    ArrayQueue() : ArrayQueue(INIT_CAP) {}

    void enqueue(E e) {
        if (size == data.size()) {
            resize(size * 2);
        }

        data[last] = e;
        last++;
        if (last == data.size()) {
            last = 0;
        }

        size++;
    }

    E dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }

        if (size == data.size() / 4) {
            resize(data.size() / 2);
        }

        E oldVal = *data[first];
        data[first].reset();
        first++;
        if (first == data.size()) {
            first = 0;
        }

        size--;
        return oldVal;
    }

    E peekFirst() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return *data[first];
    }

    E peekLast() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        if (last == 0) return *data[data.size() - 1];
        return *data[last - 1];
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }
};

class MyCircularQueue {
private:
    ArrayQueue<int> q;
    int maxCap;

public:
    MyCircularQueue(int k) : q(k), maxCap(k) {}

    bool enQueue(int value) {
        if (q.getSize() == maxCap) {
            return false;
        }
        q.enqueue(value);
        return true;
    }

    bool deQueue() {
        if (q.isEmpty()) {
            return false;
        }
        q.dequeue();
        return true;
    }

    int Front() {
        if (q.isEmpty()) {
            return -1;
        }
        return q.peekFirst();
    }

    int Rear() {
        if (q.isEmpty()) {
            return -1;
        }
        return q.peekLast();
    }

    bool isEmpty() {
        return q.isEmpty();
    }

    bool isFull() {
        return q.getSize() == maxCap;
    }
};