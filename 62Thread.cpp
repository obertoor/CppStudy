#include<iostream>
#include<thread>

//本节主题 线程


//不断以最快的速度做事情，会导致线程cpu使用率100%
static bool s_Finished = false;

//在线程中使用this_thread对当前线程进行操作
void Dowork() {
	using namespace std::literals::chrono_literals;
	std::cout << "Thread id:" << std::this_thread::get_id() << std::endl;//打印当前线程id
	while (!s_Finished)
	{
		std::cout << "Working.......\n";
		std::this_thread::sleep_for(1s);//休眠1s
	}

}
#if 0
int main() {
	std::thread worker(Dowork);//创建一个新的线程去自行括号内的函数，接受的是一个函数指针
	std::cin.get();
	s_Finished = true;
	worker.join();//等待线程加入，即等待线程结束 在当前线程上等待worker这个线程完成它的工作
	std::cout << "Finished!" << std::endl;
	std::cout << "Thread id:" << std::this_thread::get_id() << std::endl;//打印当前线程id
}
#endif