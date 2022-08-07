#include<iostream>
#include<thread>
#include<chrono>


//本节主题 计时

//chrono库
//计时本身有开销，故休眠时间不一定
namespace ob_time {


	struct Timer {
		std::chrono::time_point<std::chrono::steady_clock> start, end;
		std::chrono::duration<float> duration;
		Timer() {
			start = std::chrono::high_resolution_clock::now();//记录初始化时间
		}
		~Timer() {
			end = std::chrono::high_resolution_clock::now();//记录析构时间
			duration = end - start;
			float ms = duration.count() * 1000.0f;
			std::cout << "Timer took=" << ms << "ms" << std::endl;
		}
	};
}

void function() {
	using namespace ob_time;
	Timer timer;
	for (int i = 0; i < 100; i++) {
		//std::cout << "hello" << std::endl;
		std::cout << "hello\n";//可降低时间开销
	}
}
#if 0
int main() {
	using namespace std::literals::chrono_literals;
	auto start = std::chrono::high_resolution_clock::now();//访问当前时间
	std::this_thread::sleep_for(1s);//线程休眠1s
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = end - start;//高精度计时器	 
	std::cout << duration.count() <<"s"<< std::endl;//实际超过1s
	function();
	std::cin.get();
}
#endif