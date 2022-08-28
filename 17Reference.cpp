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

void SetPointer(int* i) {
	(*i)++;
	cout << i << endl;
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
	//cout << a << endl;


	int* pref = &a;
	*pref = 2;
	pref = &b;
	*pref = 1;
	//a=2;b=1

	Increment(a);
	PIncrement(&a);//传递指针，或者说传递a的地址
	RIncrement(a);//成功修改a


	int i = 10;
	int* p = &i;
	cout << p << endl;
	SetPointer(p);
	cout << i << endl;

	cin.get();
}
#endif

//与指针的区别
//指针是一个变量，存储的是一个地址，引用跟原来的变量实质上是同一个东西，是原变量的别名
//指针可以有多级，引用只有一级
//指针可以为空，引用不能为NULL且在定义时必须初始化
//指针在初始化后可以改变指向，而引用在初始化之后不可再改变
//sizeof指针得到的是本指针的大小，sizeof引用得到的是引用所指向变量的大小
//当把指针作为参数进行传递时，也是将实参的一个拷贝传递给形参，两者指向的地址相同，但不是同一个变量，在函数中改变这个变量的指向不影响实参，而引用却可以。
//引用本质是一个指针，同样会占4字节内存；指针是具体变量，需要占用存储空间
