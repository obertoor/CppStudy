#include<iostream>
#include<memory>
#include<chrono>
#include<array>

//本节主题  基准化测试

//RAII 当这个对象被创建时，开始计时器，被销毁时停止
class Timer
{
public:
	Timer()
	{
		m_StartTimepoint=std::chrono::high_resolution_clock::now();//获得当前时间 
	}
	~Timer()
	{
		stop();
	}

	void stop() {
		auto endTimepoit= std::chrono::high_resolution_clock::now();//time_point
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoit).time_since_epoch().count();//花费时间，精确到微秒
		//time_since_epoch(),表示这个time_point距离元年也就是1970年1月1日所经过的duration
		//time_point_cast() 转换time_point
		auto duration = end - start;
		double ms = duration * 0.001;//计算毫秒数

		//可以输出到跟踪器

		std::cout << duration << "us("<<ms<<"ms)\n";
	}
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;

};


namespace ob_74
{
	struct Vector2
	{
		float x, y, z;
	};
}
#if 0
int main() {
	using namespace ob_74;
	//int value = 0;
	//{	
	//	Timer timer;
	//	for (int i = 0; i < 1000000; i++) {
	//		value += 2;
	//	}
	//}
	//std::cout << value << std::endl;
	 
	//使用make_shared
	//debug:0.776ms//多次测试下不一定比new快
	//release:0.074ms//更快
	std::cout << "Make shared\n";
	{
		//1000个共享指针，储存在sharedPtrs中
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++) {
			sharedPtrs[i] = std::make_shared<Vector2>(); 
		}
	}

	//使用new
	//debug:0.933ms
	//release:0.107ms
	std::cout << "new shared\n";
	{
			
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++) {
			sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2);
		}
	}
	

	//使用unique
	//debug:0.509ms
	//release:0.057ms
	std::cout << "Make unique\n";
	{
		//
		std::array<std::unique_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++) {
			sharedPtrs[i] = std::make_unique<Vector2>();
		}
	}
	



	//__debugbreak();//中断编译，会这该行于自动设置断点
}
#endif