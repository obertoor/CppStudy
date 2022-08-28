#include <iostream>

using namespace std;
//本节主题 const

//const就像承诺，先程序承诺某些东西不变，但是可以绕过
//两种内涵：编译期常量（constexpr），只读变量
//const首先作用于左边的东西；如果左边没东西，就做用于右边的东西
//const可以修饰一般的变量，这样的变量我们称之为常变量，常变量的值是不能修改的。

class Entity
{
private:
	int m_X;
	int* m_Y;
	mutable int var;//mutable绕过const限制
public:
	//只在类中有效的方法
	int GetX() const//承诺不修改类成员,const限定后参数类表不同了
	{
		//m_X=2;//不行
		var = 2;//mutable,基本用不上
		return m_X;
	}
	int GetX() {
		return m_X;
	}
	//返回一个不能被修改的指针
	const int* const GetY() const {
		return m_Y;
	}
};

void PrintEntity(const Entity& e) {//这样传递参数可以避免复制Entity
	cout << e.GetX() << endl;
}


#if 0
int main() {
	int a = 5;
	const int b = 5;
#if 0
	b = 4;//无法改变b的类型以及值
#endif
	int* c = new int;
	*c = 4;
	cout << *c << endl;
	c = (int*)&b;//使用 (int*)绕开const限制
	cout << *c << endl;


	const  int* cc = new int;//意味着不能修改该指针指向的内容，只能换地址
#if 0
	*cc = 4;//无法改变内容
#endif
	cc = (int*)&b;//指针本身重新赋值



	int* const ccc = new int;//地址不能修改,只能换内容
	*ccc = 8;
#if 0
	ccc = (int*)&b;
#endif


	int const* cccc = new int;//同  const int* cccc = new int
	//关键在const 位于  * 的哪一边

	const int* const ccccc = new int;

	//指针常量
	//指向常量的指针变量
	//不能通过通过指针变量改变它指向的对象的值
	int ca = 10;
	const int* pa;
	pa = &ca;
	//*pa = ca;//报错，表达式必须是可以修改的左值。
	ca = 20;//合法
	cout << "pa:" << pa << endl;
	pa = &a;
	cout << "ca:" << ca << endl;


	//常指针(常地址)
	//针值(地址)不能改变,必须在定义时初始化
	int ac = 10;
	int bc = 20;
	int* const pc = &ac;
	*pc = ac;//合法
	//pc = &bc;//报错，表达式必须是可以修改的左值。
	cout << "ac:" << ac << endl;
	cout << "pc:" << pc << endl;

	ac = 50;
	cout <<"ac:" << ac << endl;
	cout << "pc:" << pc << endl;
	//地址不变,但值可以改变
	return 0;
}
#endif