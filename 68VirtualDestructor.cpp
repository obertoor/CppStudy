#include<iostream>



//��������  ����������



//����д��������,���Ǽ�����������
//�����������Ϊvirtual,�����֪���ڲ�νṹȥ�����������������
//Ϊ�˰�ȫ����չ��

class Base
{
public:
	Base() {
		std::cout << "Base����ɹ�\n";
	}
	virtual ~Base() {
		std::cout << "Base�����ɹ�\n";
	}
};

class Dervied:public Base
{
public:
	Dervied() {
		my_Array = new int[5];
		std::cout << "Dervied����ɹ�\n";
	}
	~Dervied() {//����ú���û�б����ã����ڴ�й¶
		delete my_Array;
		std::cout << "Dervied�����ɹ�\n";
	}
private:
	int* my_Array;
};

#if 0
int main()
{

	Base* base = new Base();
	delete base;

	std::cout << "-----------------------\n";

	//δ���virtual:�˴����ȵ���Base�Ĺ��캯��,Ȼ�����dervied�Ĺ��캯��,����������������
	Dervied* dervied = new Dervied();
	delete dervied;

	std::cout << "-----------------------\n";

	//δ���virtual:��ʱ������������캯��,����������ֻ����base,��ᵼ���ڴ�й¶
	Base* poly = new Dervied();
	//δ���virtual:delete����Base����������
	//���virtual:�������죬����������������
	delete poly;

}
#endif