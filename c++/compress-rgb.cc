/**
 * @file compress-rgb.cc
 * @brief compress rgb
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2015-01-18
 */
#include <iostream>
using namespace std;

unsigned char compress[1<<8];

void Init()
{
    int upper(0), lower(0);
    for(size_t i=0; i<(1<<8); ++i) {
        upper = i >> 4;
        lower = i & 0x0F;
        if(lower - upper >= 9)
            compress[i] = (upper+1<(1<<4) ? upper+1 : upper);
        else if(upper - lower >= 9) 
            compress[i] = (upper-1>=0  ? upper-1 : upper);
        else
            compress[i] = upper;
    }
}

unsigned char Convert(unsigned char r)
{
    return compress[r];
}

void Test()
{
    unsigned char rgb[3] = {171, 205, 238};
    for(int i=0; i<3; ++i) {
        cout << (int)Convert(rgb[i]) << " ";
    }
    cout << endl;
}

int main(void)
{
    Init();
    Test();
    return 0;
}


