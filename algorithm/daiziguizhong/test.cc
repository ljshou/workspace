/**
 * @file test.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-12-30
 */
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

string minWindow(string S, string T) {
    if(S.size() < T.size()) return "";
    int appeared[256] = {0}, expected[256] = {0};
    for(auto c : T)  ++ expected[c];

    int index(0), len(INT_MAX);
    int front(0), rear(0), count(0);
    for(; rear<S.size(); ++rear) {
        while(front < S.size() && count < T.size()) {
            char c = S[front];
            if(++appeared[c] <= expected[c]) ++count;
            ++ front;
        }
        if(front - rear < len) {
            len = front - rear;
            index = rear;
        }
        if(--appeared[S[rear]] < expected[S[rear]]) --count;
    }

    if(len == INT_MAX) return "";
    else return S.substr(index, len);
}

int main(void)
{
    cout << minWindow("a", "a") << endl;
    return 0;
}
