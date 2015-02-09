/**
 * @file delete-k-digits.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-04
 */

#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <cassert>
using namespace std;

string DeleteDigits(const string &num, int k)
{
    const int n = num.size();
    if(n == 0 || k >= n) return "0";
    deque<char> s;
    int i = 0;
    for(i=0; i<k; ++i) {
        while(!s.empty() && s.back() > num[i])
            s.pop_back();
        s.push_back(num[i]);
    }
    string res;
    for(; i<n; ++i) {
        while(!s.empty() && s.back() > num[i])
            s.pop_back();
        s.push_back(num[i]);
        res += s.front(); s.pop_front();
    }
    return res;
}

string DeleteDigits2(const string &num, int k)
{
    const int n = num.size();
    if(n == 0 || k >= n) return "0";
    string res;
    int j = 0;
    for(int i=0; i<n-k; ++i) {
        j = min_element(num.begin()+j, num.begin()+k+1+i) - num.begin();
        res += num[j];
        ++j;
    }
    return res;
}

string DeleteDigits3(const string &num, int k)
{    
    const int n = num.size();
    if(n == 0 || k >= n) return "0";
    string res;
    deque<char> s;
    int delete_count = 0;
    for(int i=0; i<n; ++i) {
        while(delete_count != k 
              && !s.empty() && s.back() > num[i]) {
            s.pop_back();
            ++ delete_count;
        }
        s.push_back(num[i]);
    }
    for(auto c : s) 
        res += c;
    return res.substr(0, n-k);
}

void Test()
{
    srand(time(0));
    string str(20, '0');
    int k = 0;
    for(int i=0; i<1000; ++i) {
        generate(str.begin(), str.end(), [](){return rand()%10 + '0';});
        k = rand() % 20;
        assert(DeleteDigits(str, k) == DeleteDigits2(str, k));
        assert(DeleteDigits(str, k) == DeleteDigits3(str, k));
    }
}

int main(void)
{
    Test();
    return 0;
}
