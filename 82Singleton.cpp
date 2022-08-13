#include<iostream>


//��������  ����ģʽ


//ֻ����ӵ�����ṹ���һ��ʵ��
//���ڰ�װ��һ�����ݼ��Ĳ���
//������Ⱦ��,�����ύ��Ⱦ����
//һ����֯һ��ȫ�ֱ����;�̬�����ķ���
//Ҳ����д�������ռ���,��private����ͨ��ͷ�ļ�������,����ʧȥ���丳ֵ������������


//�����й������캯��,��Ϊ�й����Ĺ��캯��,�ͻᱻ����ʵ����
class Singleton
{
public:
	Singleton(const Singleton&) = delete;//�������캯��,����ʵ����

	//�ṩ��̬���ʸ���ķ���,�����ض����͵����û���ָ��
	static Singleton& Get() 
	{
		return s_Instance;
	}
	void Function()
	{
		
	}

private:
	Singleton() //���캯�����Ϊprivate,�������ⲿ��ʵ����
	{}

	static Singleton s_Instance;//��ͳ����,��Ҫ����
};

Singleton Singleton::s_Instance;//����



class Random 
{
public:
	Random(const Random&) = delete;
	static Random& Get()
	{
		static Random m_Random;//���ھ�̬�ڴ���,ֻ��ʵ����һ��
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
//�����ƶ������ڲ�
//Random Random::m_Random;
#if 0
int main() 
{
	Singleton::Get().Function();//���ʵ���

	auto& Instance = Singleton::Get();

	//����static float������publicʱ
	//float number1=Random::Get().Float();
	//auto& random = Random::Get();
	//float number2 = random.Float();

	float number3 = Random::Float();


	std::cin.get();
}
#endif