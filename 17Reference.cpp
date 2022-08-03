#include<iostream>
using namespace std;
//本节主题 引用

//指针上的语法糖
//引用现有变量的方式
//不可为空

void Increment(int value) {
	value++;//如果是正常传递，函数会复制一个新的value
}

void PIncrement(int* value) {//传递指针
	(*value)++;//逆向引用，否则会针对地址进行+1
}

void RIncrement(int& value) {//传递需要在函数内部改变的量
	value++;
}

#if 0
int main() {
	int a = 5;
	int b = 8;
	//创建引用 必须赋值
	int& ref = a;//这里的&不是操作符,而是类型的一部分,
	//ref =b;这是错误的，不能改变引用
	// 如果执行，会出现 a=8,b=8;
	//ref只是一个别名,不存在于编译后的的代码中
	ref = 2;//将ref当作a使用
	cout << a << endl;


	int* pref = &a;
	*pref = 2;
	pref = &b;
	*pref = 1;
	//a=2;b=1

	Increment(a);
	PIncrement(&a);//传递指针，或者说传递a的地址
	RIncrement(a);//成功修改a
}
#endif