#include<iostream>


//�������� ��ͽṹ���е�static

//��ͽṹ���еľ�̬�������������������ʵ���У�ֻ����һ������
//��ͽṹ���еľ�̬�������޷��������ʵ��������ͨ�����ʵ���������ڲ�����д���õ���ʵ���Ĵ���

struct Entity_22
{
	static int g;
	int x, y;
	void Print()
	{
		std::cout << x <<","<< y << "," <<g<< std::endl;
	}
	//��̬�������ܷ��ʷǾ�̬��Ա����
	static void s_Print()
	{
		std::cout << g << std::endl;
	}

	//ʵ����ÿ������߽ṹ��ķǾ�̬���������������һ�����صĲ��������ǵ�ǰ��ʵ��
	//��̬�����Ĳ�����ȱ����ǰʵ������������
#if 0
	static void s_Print(Entity_22 e1)
	{
		std::cout << g << std::endl;
	}
#endif 
};



int Entity_22::g;//ʹ�������ͨ��ʵ��ȥ����
#if 0
int main()
{
	Entity_22 e1;
	e1.x = 2;
	e1.y = 4;
	e1.g = 6;

	Entity_22 e2;
	e2.x = 4;
	e2.y = 8;
	e2.g = 10;//static�̶�Ϊ���һ�ζ���
	//����ʵ����gָ��ͬһƬ�ڴ�

	Entity_22::g = 22;

	e1.Print();
	e2.Print();
	std::cin.get();
}
#endif