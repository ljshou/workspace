/**
 * @file 1220.cc
 * @brief  Number Base Conversion
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-11-02
 */

#include <iostream>
using namespace std;
#define For(i, n) for(int i=0; i<(n); ++i)
const int Max = 500 + 5;

char in[Max], out[Max];
int s[Max], t[Max];
int base1, base2;

void solve() 
{
    int len = strlen(in);
    For(i, len) {
        if(in[i] >= '0' && in[i] <= '9') {
            s[len-1-i] = in[i] - '0';
        }
        else if(in[i] >= 'A' && in[i] <= 'Z') {
            s[len-1-i] = in[i] - 'A' + 10;
        }
        else {
            s[len-1-i] = in[i] - 'a' + 36;
        }
    }
    int k = len - 1, cur = 0;
    while(k >= 0) {
        for(int j=k; j>0; --j) {
            s[j-1] += s[j] % base2 * base1;
            s[j] /= base2;
        }
        t[cur++] = s[0] % base2;
        s[0] /= base2;
        //remove heading zeros
        for(; k>=0 && s[k] == 0; --k);
    }
    For(i, cur) {
        if(t[i] >= 0 && t[i] <= 9) {
            out[cur-i-1] = t[i] + '0';
        }
        else if(t[i] >= 10 && t[i] <= 35) {
            out[cur-i-1] = t[i] + 'A' - 10;
        }
        else {
            out[cur-i-1] = t[i] + 'a' - 36;
        }
    }
    out[cur] = 0;
    cout << base1 << " " << in << endl;
    cout << base2 << " " << out << endl;
    cout << endl;
}

int main(void)
{
    int n;
    cin >> n;
    while(n --) {
        cin >> base1 >> base2;
        cin >> in;
        solve();
    }
    return 0;
}
