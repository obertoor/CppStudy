#include<iostream>


//��������  ��������˳��



#if 0

void Function(int a, int b) {
	std::cout << a <<"+"<<b<<"="<<(a+b)<< std::endl;

};




int main()
{
	int a = 2;

	//����C++��׼δ�������Ϊ,������ж�ȡ���������
	//��Ҫʹ�����ֲ���
	Function(2, a++);//������������,����2  2+2
	std::cout << a << std::endl;//a=3
	a = 2;
	Function(a++, a++);//3+2
}

#endif