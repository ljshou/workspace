/**
 * @file ctrl-v.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-02
 */
#include <iostream>
#include <cassert>
using namespace std;
const int MAX_N = 1e5 + 10;
long long  f[MAX_N];

int max_key_A(int n) {
    if (n <= 7) return n;

    int *M = new int[n+1];
    for (int i = 0; i <= n; i++)
        M[i] = 0;

    int maxa = 0; 
    for (int i = 1; i <= n; i++) {
        M[i] = i;
        for (int j = i; j <= n; j++) {
            for (int k = i+3; k <= j; k++) {
                if (M[j] < (j-k+1)*M[k-3]) 
                    M[j] = (j-k+1)*M[k-3];
            }
        }
        if (M[n] > maxa) maxa = M[n];
    }

    delete[] M;
    return maxa;
}

long long MaxKey(int n)
{
    if(n <= 3) return n;
    for(int i=0; i<=n; ++i) f[i] = i;
    for(int i=1; i<=n; ++i) {
        for(int j=i; j-3>=0; --j) {
            f[i] = max(f[i], f[j-3] * (i - j + 1));
        }
    }
    return f[n];
}

void Test()
{
    for(int i=1; i<=100; ++i) {
        cout << MaxKey(i) << endl;
    }
}

int main(void)
{
    Test();
    return 0;
}
