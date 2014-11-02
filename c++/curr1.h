#ifndef Currency_  //Currency_为标志符, 防止该头文件被重复#include
#define Currency_

#include<iostream>
using namespace std;


enum sign { plus1, minus1};  //std中定义了plus,minus这两个类

class Currency {
public:
// 构造函数
	Currency(sign s = plus1, unsigned long d = 0, unsigned int c = 0);
// 析构函数
	~Currency() {}

	bool Set(sign s, unsigned long d, unsigned int c);
	bool Set(float a);
	sign Sign() const {return sgn;} //const表示该成员函数不能够改变 成员变量的值
	unsigned long Dollars() const {return dollars;}
	unsigned int Cents() const {return cents;}
	Currency Add(const Currency& x) const;
	Currency& Increment(const Currency& x);
	void Output() const;

private:
	sign sgn;
	unsigned long dollars;
	unsigned int cents;
};


Currency::Currency(sign s, unsigned long d, unsigned int c)//构造函数类外的实现
{// 创建一个Currency对象
	if(c > 99)
	{//美分数目过多
	cerr << "Cents should be < 100" << endl;
	exit(1);}
	sgn = s; dollars = d; cents = c;
}

bool Currency::Set(sign s, unsigned long d, unsigned int c)
{// 取值
	if (c > 99) return false;
	sgn = s; dollars = d; cents = c;
	return true;
}


bool Currency::Set(float a)//成员函数Set的重载
{// 取值
	if (a < 0) {sgn = minus1; a = -a;}
	else sgn = plus1;
	dollars = a; // 抽取整数部分
// 获取两个小数位
	cents = (a + 0.005 - dollars) * 100;
	return true;
}


Currency Currency::Add(const Currency& x) const
{// 把 x累加到 *this.
	long a1, a2, a3;
	Currency ans;
// 把当前对象转换成带符号的整数
	a1 = dollars * 100 + cents;
	if (sgn == minus1) a1 = -a1;
// 把x转换成带符号的整数
	a2 = x.dollars * 100 + x.cents;
	if (x.sgn == minus1) a2 = -a2;
	a3 = a1 + a2;
// 转换成 currency 形式
	if (a3 < 0) {ans.sgn = minus1; a3 = -a3;}
	else ans.sgn = plus1;
	ans.dollars = a3 / 100;
	ans.cents = a3 - ans.dollars * 100;
	return ans;
}


Currency& Currency::Increment(const Currency& x)
{// 增加量 x.
	*this = Add(x);
	return *this;
}


void Currency::Output () const
{// 输出currency 的值
	if (sgn == minus1) cout << '-';
	cout << '$' << dollars << '.';
	if (cents < 10) cout << "0";
	cout << cents;
}


#endif
