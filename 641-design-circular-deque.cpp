#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

/*
设计实现双端队列。

实现 MyCircularDeque 类:

MyCircularDeque(int k) ：构造函数,双端队列最大为 k 。
boolean insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true ，否则返回 false 。
boolean insertLast() ：将一个元素添加到双端队列尾部。如果操作成功返回 true ，否则返回 false 。
boolean deleteFront() ：从双端队列头部删除一个元素。 如果操作成功返回 true ，否则返回 false 。
boolean deleteLast() ：从双端队列尾部删除一个元素。如果操作成功返回 true ，否则返回 false 。
int getFront() )：从双端队列头部获得一个元素。如果双端队列为空，返回 -1 。
int getRear() ：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1 。
boolean isEmpty() ：若双端队列为空，则返回 true ，否则返回 false  。
boolean isFull() ：若双端队列满了，则返回 true ，否则返回 false 。


示例 1：
输入
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
输出
[null, true, true, true, false, 2, true, true, true, 4]

解释
MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
circularDeque.insertLast(1);			        // 返回 true
circularDeque.insertLast(2);			        // 返回 true
circularDeque.insertFront(3);			        // 返回 true
circularDeque.insertFront(4);			        // 已经满了，返回 false
circularDeque.getRear();  				// 返回 2
circularDeque.isFull();				        // 返回 true
circularDeque.deleteLast();			        // 返回 true
circularDeque.insertFront(4);			        // 返回 true
circularDeque.getFront();				// 返回 4
*/


template <typename E>
class MyArrayDeque {
private:
    int currentSize;
    vector<E> data;
    static const int INIT_CAP = 2;
    int first, last;

    void resize(int newCap) {
        vector<E> temp(newCap);

        for (int i = 0; i < currentSize; i++) {
            temp[i] = data[(first + i) % data.size()];
        }

        first = 0;
        last = currentSize;
        data = move(temp);
    }

public:
    MyArrayDeque(int initCap) : currentSize(0), data(initCap), first(0), last(0) {}

    MyArrayDeque() : MyArrayDeque(INIT_CAP) {}

    E getFirst() {
        if (isEmpty()) {
            throw out_of_range("No such element");
        }
        return data[first];
    }

    E getLast() {
        if (isEmpty()) {
            throw out_of_range("No such element");
        }

        if (last == 0) return data[data.size() - 1];
        return data[last - 1];
    }

    void addFirst(E e) {
        if (currentSize == data.size()) {
            resize(currentSize * 2);
        }

        if (first == 0) {
            first = data.size() - 1;
        } else {
            first--;
        }
        data[first] = e;

        currentSize++;
    }

    void addLast(E e) {
        if (currentSize == data.size()) {
            resize(currentSize * 2);
        }
        data[last] = e;
        last++;
        if (last == data.size()) {
            last = 0;
        }

        currentSize++;
    }

    E removeFirst() {
        if (isEmpty()) {
            throw out_of_range("No such element");
        }

        if (currentSize == data.size() / 4) {
            resize(data.size() / 2);
        }

        E oldVal = data[first];
        data[first] = E();

        first++;
        if (first == data.size()) {
            first = 0;
        }

        currentSize--;
        return oldVal;
    }

    E removeLast() {
        if (isEmpty()) {
            throw out_of_range("No such element");
        }

        if (currentSize == data.size() / 4) {
            resize(data.size() / 2);
        }

        if (last == 0) {
            last = data.size() - 1;
        } else {
            last--;
        }
        E oldVal = data[last];
        data[last] = E();

        currentSize--;
        return oldVal;
    }

    int size() {
        return currentSize;
    }

    bool isEmpty() {
        return currentSize == 0;
    }
};

class MyCircularDeque {
private:
    int cap;
    MyArrayDeque<int> list;

public:
    MyCircularDeque(int k) : cap(k) {}

    bool insertFront(int value) {
        if (list.size() == cap) {
            return false;
        }

        list.addFirst(value);
        return true;
    }

    bool insertLast(int value) {
        if (list.size() == cap) {
            return false;
        }

        list.addLast(value);
        return true;
    }

    bool deleteFront() {
        if (list.isEmpty()) {
            return false;
        }

        list.removeFirst();
        return true;
    }

    bool deleteLast() {
        if (list.isEmpty()) {
            return false;
        }

        list.removeLast();
        return true;
    }

    int getFront() {
        if (list.isEmpty()) {
            return -1;
        }

        return list.getFirst();
    }

    int getRear() {
        if (list.isEmpty()) {
            return -1;
        }

        return list.getLast();
    }

    bool isEmpty() {
        return list.isEmpty();
    }

    bool isFull() {
        return list.size() == cap;
    }
};