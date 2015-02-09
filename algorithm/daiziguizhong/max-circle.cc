/**
 * @file max-circle.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-25
 */

int maxCycle(vector<int> &a) {
    int n = a.size(), answer = 0, now = 0;
    vector<int> ts(n, - 1);
    for (int i = 0; i < n; ++i) {
        if (ts[i] < 0) {
            int x;
            for (x = i;(x >= 0) && (x < n) && (ts[x] < 0); ts[x] = now++, x = a[x]);
            if ((x >= 0) && (x < n) && (ts[x] >= ts[i])) {
                answer = max(answer, now - ts[x]);
            }
        }
    }
    return answer;
}
