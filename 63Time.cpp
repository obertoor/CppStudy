#include<iostream>
#include<thread>
#include<chrono>


//�������� ��ʱ

//chrono��
//��ʱ�����п�����������ʱ�䲻һ��
namespace ob_time {


	struct Timer {
		std::chrono::time_point<std::chrono::steady_clock> start, end;
		std::chrono::duration<float> duration;
		Timer() {
			start = std::chrono::high_resolution_clock::now();//��¼��ʼ��ʱ��
		}
		~Timer() {
			end = std::chrono::high_resolution_clock::now();//��¼����ʱ��
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
		std::cout << "hello\n";//�ɽ���ʱ�俪��
	}
}
#if 0
int main() {
	using namespace std::literals::chrono_literals;
	auto start = std::chrono::high_resolution_clock::now();//���ʵ�ǰʱ��
	std::this_thread::sleep_for(1s);//�߳�����1s
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = end - start;//�߾��ȼ�ʱ��	 
	std::cout << duration.count() <<"s"<< std::endl;//ʵ�ʳ���1s
	function();
	std::cin.get();
}
#endif