/**
 * @file test.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.com
 * @version 0.1.00
 * @date 2014-11-21
 */

#include<iostream>
#include<boost/bind.hpp>
using namespace std;
using namespace boost;
int fun(int x,int y){return x+y;}
int main(){
    int m=1;int n=2;
    cout<<boost::bind(fun,_1,_2)(m,n)<<endl;
    return 0;
}
