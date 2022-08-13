#include<iostream>


//本节主题  单例模式


//只打算拥有类或结构体的一个实例
//用于包装对一个数据集的操作
//例如渲染器,向其提交渲染命令
//一种组织一堆全局变量和静态函数的方法
//也可以写在命名空间内,其private可以通过头文件等声明,但是失去将其赋值给变量的能力


//不能有公共构造函数,因为有公共的构造函数,就会被允许实例化
class Singleton
{
public:
	Singleton(const Singleton&) = delete;//拷贝构造函数,避免实例化

	//提供静态访问该类的方法,返回特定类型的引用或者指针
	static Singleton& Get() 
	{
		return s_Instance;
	}
	void Function()
	{
		
	}

private:
	Singleton() //构造函数标记为private,不能在外部被实例化
	{}

	static Singleton s_Instance;//传统方法,需要定义
};

Singleton Singleton::s_Instance;//定义



class Random 
{
public:
	Random(const Random&) = delete;
	static Random& Get()
	{
		static Random m_Random;//处于静态内存中,只被实例化一次
		return m_Random;
	}
	//float Float() {
	//	return m_RandomGenerator;
	//}

	static float Float() {
		return Get().FloatInternal();
	}

private:
	Random(){}

	float FloatInternal() {
		return m_RandomGenerator;
	}

	float m_RandomGenerator = 0.5f;
	static Random m_Random;
};
//可以移动到类内部
//Random Random::m_Random;
#if 0
int main() 
{
	Singleton::Get().Function();//访问单例

	auto& Instance = Singleton::Get();

	//当非static float函数在public时
	//float number1=Random::Get().Float();
	//auto& random = Random::Get();
	//float number2 = random.Float();

	float number3 = Random::Float();


	std::cin.get();
}
#endif