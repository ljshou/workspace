/**
 * @file count-binary-trees.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2015-01-19
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

typedef vector<int>::iterator Iterator;
int CountBinarytrees(Iterator pre_first, Iterator pre_last,
                     Iterator post_first, Iterator post_last)
{
    const int n = pre_last - pre_first;
    if(n != post_last - post_first)
        return 0;
    if(n == 0) 
        return 1;
    if(*pre_first != *(post_last-1))
        return 0; //not same root

    int count = 0, right_len = 0;
    for(int left_len=0; left_len<n; ++left_len) {
        right_len = n-1 - left_len;
        count += CountBinarytrees(pre_first+1, pre_first+1+left_len, post_first, post_first+left_len) 
            * CountBinarytrees(pre_last-right_len, pre_last, post_last-1-right_len, post_last-1);
    }
    return count;
}

void Test()
{
    vector<int> pre{1,2,3,4}, post{3,2,4,1};
    cout << CountBinarytrees(pre.begin(), pre.end(), 
                             post.begin(), post.end()) << endl;
}

int main(void)
{
    Test();
    return 0;
}
