#include <iostream>
#include <string>
#include <stack>

class Solution {
private:
    char leftOf(char c) {
        if (c == '}') {
            return '{';
        } else if (c == ')') {
            return '(';
        } else {
            return '[';
        }
    }

public:
    bool isValid(string str) {
        stack<char> left;
        for (char c : str) {
            if (c == '(' || c == '{' || c == '[') {
                left.push(c);
            } else {
                if (!left.empty() && leftOf(c) == left.top()) {
                    left.pop();
                } else {
                    return false;
                }
            }
        }
        return left.empty();
    }
};

