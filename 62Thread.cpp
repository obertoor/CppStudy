#include<iostream>
#include<thread>

//�������� �߳�


//�����������ٶ������飬�ᵼ���߳�cpuʹ����100%
static bool s_Finished = false;

//���߳���ʹ��this_thread�Ե�ǰ�߳̽��в���
void Dowork() {
	using namespace std::literals::chrono_literals;
	std::cout << "Thread id:" << std::this_thread::get_id() << std::endl;//��ӡ��ǰ�߳�id
	while (!s_Finished)
	{
		std::cout << "Working.......\n";
		std::this_thread::sleep_for(1s);//����1s
	}

}
#if 0
int main() {
	std::thread worker(Dowork);//����һ���µ��߳�ȥ���������ڵĺ��������ܵ���һ������ָ��
	std::cin.get();
	s_Finished = true;
	worker.join();//�ȴ��̼߳��룬���ȴ��߳̽��� �ڵ�ǰ�߳��ϵȴ�worker����߳�������Ĺ���
	std::cout << "Finished!" << std::endl;
	std::cout << "Thread id:" << std::this_thread::get_id() << std::endl;//��ӡ��ǰ�߳�id
}
#endif