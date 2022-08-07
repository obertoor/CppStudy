#include<iostream>
#include<memory>
#include<chrono>
#include<array>

//��������  ��׼������

//RAII ��������󱻴���ʱ����ʼ��ʱ����������ʱֹͣ
class Timer
{
public:
	Timer()
	{
		m_StartTimepoint=std::chrono::high_resolution_clock::now();//��õ�ǰʱ�� 
	}
	~Timer()
	{
		stop();
	}

	void stop() {
		auto endTimepoit= std::chrono::high_resolution_clock::now();//time_point
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoit).time_since_epoch().count();//����ʱ�䣬��ȷ��΢��
		//time_since_epoch(),��ʾ���time_point����Ԫ��Ҳ����1970��1��1����������duration
		//time_point_cast() ת��time_point
		auto duration = end - start;
		double ms = duration * 0.001;//���������

		//���������������

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
	 
	//ʹ��make_shared
	//debug:0.776ms//��β����²�һ����new��
	//release:0.074ms//����
	std::cout << "Make shared\n";
	{
		//1000������ָ�룬������sharedPtrs��
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++) {
			sharedPtrs[i] = std::make_shared<Vector2>(); 
		}
	}

	//ʹ��new
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
	

	//ʹ��unique
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
	



	//__debugbreak();//�жϱ��룬����������Զ����öϵ�
}
#endif