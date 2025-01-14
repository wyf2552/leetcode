#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s.begin(), s.end());
        reverseEachWord(s);
        return s;
    }

private:
    void removeExtraSpaces(string& s) {
        int slow = 0;
        int fast = 0;

        while(fast < s.size() && s[fast] == ' ') {
            fast++;
        }

        bool isFirstWord = true;
        while (fast < s.size()) {
            if (fast > 0 && s[fast] == ' ' && s[fast - 1] == ' ') {
                fast++;
                continue;
            }

            if (!isFirstWord && s[fast] != ' ') {
                s[slow++] = ' ';
            }

            while (fast < s.size() && s[fast] != ' ') {
                s[slow++] = s[fast++];
                isFirstWord = false;
            }

            fast++;
        }

        s.resize(slow);
    }

    void reverseEachWord(string& s) {
        int start = 0;
        int end = 0;

        while (start < s.size()) {
            while (end < s.size() && s[end] != ' ') {
                end++;
            }

            reverse(s.begin() + start, s.begin() + end);

            start = end + 1;
            end = start;
        }
    }

};