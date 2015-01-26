/**
 * @file radix-sort.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-26
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int RADIX = 10;
int front[RADIX];
int rear[RADIX];

struct Node {
    string key;
    int link;
    Node(const string &str = ""):
        key(str), link(-1) {}
};

int getDigit(const string &str, int i)
{
    if(i >= str.size()) return 0;
    return str[str.size()-i-1] - '0';
}

void PrintList(const vector<Node> &vec)
{
    int current = vec[0].link;
    while(current != 0) {
        cout << vec[current].key << " ";
        current = vec[current].link;
    }
    cout << endl;
}

/**
 * vec[0]----dummy node
 */
void RadixSort(vector<Node> &vec, int d)
{
    const int n = vec.size();
    if(n < 3) return;
    for(int i=0; i<n-1; ++i) {
        vec[i].link = i+1;
    }
    vec[n-1].link = 0;

    int digit = 0;
    for(int i=0; i<d; ++i) {
        //clear state
        for(int j=0; j<RADIX; ++j) front[j] = 0;

        int current = vec[0].link;
        while(current != 0) {
            digit = getDigit(vec[current].key, i);
            if(front[digit] == 0) {
                front[digit] = rear[digit] = current;
            }
            else {
                vec[rear[digit]].link = current;
                rear[digit] = current;
            }
            current = vec[current].link;
        }

        int last = 0;
        //link all lists togethor
        for(int j=0; j<RADIX; ++j) {
            if(front[j] != 0) {
                if(last == 0) {
                    vec[0].link = front[j];
                }
                else {
                    vec[last].link = front[j];
                }
                last = rear[j];
            }
        }
        vec[last].link = 0;
    }

    PrintList(vec);
}

void Test()
{
    vector<Node> vec{{""}, {"123"}, {"12"}, {"1"}, {"4"},
        {"270"}, {"100"}, {"99"}};
    RadixSort(vec, 3);
}

int main(void)
{
    Test();
    return 0;
}
