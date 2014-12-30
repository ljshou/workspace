/**
 * @file maximum-gap.cc
 * @brief maximum gap in Leetcode
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-12-30
 */

#include <iostream>
#include <vector>
using namespace std;

int MaximumGap(const vector<int> &vec)
{
    const int n = vec.size();
    if(n < 2) return 0;
    int max_val = *max_element(vec.begin(), vec.end());
    int min_val = *min_element(vec.begin(), vec.end());
    int len = (max_val - min_val) / n + 1;
    
    vector<vector<int> > buckets((max_val - min_val)/len + 1);
    for(auto x : vec) {
        int i = (x - min_val) / len;
        if(buckets[i].empty()) {
            buckets[i].resize(2);
            buckets[i][0] = x;
            buckets[i][1] = x;
        }
        else {
            buckets[i][0] = min(buckets[i][0], x);
            buckets[i][1] = max(buckets[i][1], x);
        }
    }

    int gap(0), prev(0);
    for(int i=1; i<buckets.size(); ++i) {
        if(buckets[i].empty()) continue;
        gap = max(gap, buckets[i][0] - buckets[prev][1]);
        prev = i;
    }
    return gap;
}
int main(void)
{
    vector<int> vec{0,100000};
    cout << MaximumGap(vec) << endl;
    return 0;
}
