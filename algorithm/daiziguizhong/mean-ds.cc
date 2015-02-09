/**
 * @file mean-ds.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-27
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Mean {
public:
    Mean(int N = 10): size(0), sum(0), K(N) {
        if(K <= 0) throw runtime_error("window len <= 0");
        index = 0;
        vec.resize(K, 0.0);
    }
    ~Mean() {
    }
    void Insert(double x);
    double MeanValue() const;
private:
    int size, K, index;
    double sum;
    vector<double> vec;

    //copy not allowed
    Mean(const Mean &rhs);
    Mean& operator=(const Mean &rhs);
};

void Mean::Insert(double x) 
{
    if(size < K) ++size;
    sum -= vec[index];
    vec[index] = x;
    sum += vec[index];
    ++index;
    if(index == K) index = 0;
}

double Mean::MeanValue() const
{
    return sum / size;
}

void Test()
{
    Mean m(3);
    m.Insert(1);
    cout << m.MeanValue() << endl;
    m.Insert(2);
    cout << m.MeanValue() << endl;
    m.Insert(3);
    cout << m.MeanValue() << endl;
    m.Insert(4);
    cout << m.MeanValue() << endl;
    m.Insert(5);
    cout << m.MeanValue() << endl;
}

int main(void)
{
    Test();
    return 0;
}
