/**
 * @file longest-substring-with-2.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-07
 */
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

string LongestSubstringWithAtMost2(const string &str, int k = 2)
{
    int hash[256] = {0};
    int index = 0, len = 0;
    int back = 0, front = 0, count = 0;
    for(; back < str.size(); ++back) {
        while(front < str.size() && (hash[str[front]] || count < k)) {
            if(hash[str[front]]++ == 0) ++count;
            ++front;
        }
        if(count <= k) {
            if(front - back > len) 
                len = front - back, index = back;
        }
        if(--hash[str[back]] == 0) --count;
    }

    return str.substr(index, len); 
}

void Test() 
{
    assert(LongestSubstringWithAtMost2(""               ) == "");
    assert(LongestSubstringWithAtMost2("a"              ) == "a");
    assert(LongestSubstringWithAtMost2("aa"             ) == "aa");
    assert(LongestSubstringWithAtMost2("aba"            ) == "aba");
    assert(LongestSubstringWithAtMost2("abcd"           ) == "ab");
    assert(LongestSubstringWithAtMost2("abcdedcba"      ) == "ded");
    assert(LongestSubstringWithAtMost2("abbcdededcba"   ) == "deded");
    assert(LongestSubstringWithAtMost2("eceba"          ) == "ece");
    assert(LongestSubstringWithAtMost2("abaece"         ) == "aba");
    assert(LongestSubstringWithAtMost2( "ababcd"        ) == "abab");
    assert(LongestSubstringWithAtMost2( "cababcd"       ) == "abab");
    assert(LongestSubstringWithAtMost2( "abcdefgabcdefg") == "ab");
    assert(LongestSubstringWithAtMost2( "ababababababab") == "ababababababab");
}

int main(void)
{
    Test();
    return 0;
}
