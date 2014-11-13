/**
 * @file 679.cc
 * @brief dropping balls
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-11-05
 */

#include <iostream>
using namespace std;

#define For(i, n) for(int i=0; i<(n); ++i)
int D, I;
int main(void)
{
    int k = 1;
    while(cin >> D >> I) {
        k  = 1;
        For(i, D-1) {
            if(I % 2) {
                // left
                k = 2*k;
                I = (I+1) / 2;
            }
            else {
                // right
                k = 2*k + 1;
                I /= 2;
            }
        }
        cout << k << endl;
    }
    return 0;
}
