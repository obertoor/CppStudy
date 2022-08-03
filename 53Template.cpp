#include<iostream>
#include<string>

using namespace std;
//本节主题 模板

//模板是让编译器帮助写代码
//如果没用调用Print函数，那么这个函数就不会存在，此时Print函数内有错误也不会报错(msvc编译器）
template<typename T>
//template<class T> 与上一行代码相同
void Print(T value) 
{
	cout << value << endl;
}

//模板用于类上的情况
template<typename T, int N>
class Array
{
private:
	//获得一个类型为T的数组
	T m_Array[N];
public:
	int GetSize() const
	{
		return N;
	}
};

//int main()
//{
//	//指定类型
//	Print<int>(4);
//	//隐式的获得参数类型
//	Print(5);
//	Print("string");
//	Print(5.04f);
//
//	Array<char,5> array;
//	cout << array.GetSize() << endl;
//
//
//
//	cin.get();
//}


