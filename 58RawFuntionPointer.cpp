#include<iostream>
#include<vector>
using namespace std;
//本节主题 函数指针


//将一个函数赋值给一个变量的方法
//将函数作为参数传递给另一个函数


//函数会被编译成cpu指令，即可执行文件，函数指针获取这些cpu指令的内存地址

void HelloWorld() {
	cout << "HelloWorld" << endl;
}
void HelloWorlds(int a) {
	cout << "HelloWorld! value:" <<a<< endl;
}

void PrintValue(int value) {
	cout << value << endl;
}

void ForEach(const vector<int>& values,void(*func)(int))//接受函数指针
{
	for (int value : values) {
		func(value);//插入函数
	}
}
#if 0
int main() {
	auto funtion = HelloWorld;//获取函数指针，就想&helloworld，得到函数的内存地址 

	//另一种获取函数指针的方式
	void(*otherfuntion)();//()放参数列表（int）
	otherfuntion = HelloWorld;

	//还有一种获取函数指针的方式
	typedef	void(*HelloWorldFuntion)(int);
	HelloWorldFuntion anthorfuntion = HelloWorlds;

	anthorfuntion(8);
	//会输出两次helloworld
	funtion();
	funtion();

	vector<int> values = { 1,5,4,2,3 };
	ForEach(values, PrintValue);
	//lambda,本质是一个普通函数，过程中生成，用完即弃
	ForEach(values, [](int value) {cout << value << endl; });


}
#endif