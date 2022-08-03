#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

//本节主题 lambda

//lambda本质上是我们定义一种匿名函数的方式
//快速的一次性函数
//在可以用函数指针的地方都能用lambda

void ForEach59(const vector<int>& values, void(*func)(int))//接受函数指针
{
	for (int value : values) {
		func(value);//插入函数
	}
}
void ForEachs(const vector<int>& values, const function<void(int)>& func)//接受函数指针
{
	for (int value : values) {
		func(value);//插入函数
	}
}



//回调函数

#if 0
int main() {
	int a = 5;
	vector<int> values = { 1,2,3,4,5 };

	auto it =find_if(values.begin(), values.end(), [](int value) {return value > 3; });//生成迭代器
	cout << *it << endl; //返回4



	ForEach59(values, [](int value) {cout << value << endl; });//定义lambda表达式
	//可以使用auto
	auto lambda = [](int value) {cout << value << endl; };//非捕获的lambda可以隐式的转换为函数指针,而捕获的lambda不可以
	auto lambda01= [a](int value) {cout << a << endl; };
	auto lambda02 = [=](int value) mutable  {a = 555; cout << a << endl; };//使用mutab让其可以修改值传递的变量
	ForEach59(values, lambda);
	ForEachs(values, lambda01);
	ForEachs(values, lambda02);

	// []是捕获,可以捕获变量等([=]和[&]是捕获所有,=是通过复制,&是通过传递),如何传递变量
}
#endif