#include<iostream>



//�������� ����ת��


//��������ȥ��������⣬�ҵ�����ת��
//�����˱������ļ��
//static_cast:��̬����ת��
//reinterpret_cast:����˫�أ�������ڴ���ͳ���������
//const_cast:�Ƴ�������ӱ�����const�޶�
//dynamic_cast����һ���������ָ�루�����ã�ת�����̳���ָ��


class Base {
public:
	Base() {}
	virtual ~Base(){}
};
class Derived:public Base {
public:
	Derived() {}
	virtual ~Derived() {}
};
class AnotherClass :public Base {
public:
	AnotherClass() {}
	virtual ~AnotherClass() {}
};


#if 0
int main() 
{
	double value = 5.25;//��ʽת��
	int a = value;//��ʽת��,a=5


	//c++����ת��
	double b = static_cast<int>(value) + 5.3; //b=10.3��ת�����ɹ�����NULL
	
	Derived* derived = new Derived();
	Base* base = derived;//���Baseָ��

	//�鿴�Ƿ���Derivedʵ������AnotherClassʵ��
	//dynamic_cast��鿴�Ƿ�ת���ɹ�
	AnotherClass* ac = dynamic_cast<AnotherClass*>(base);
	if (!ac) 
	{
		std::cout << "ת��ʧ��" << std::endl;
	}
}
#endif