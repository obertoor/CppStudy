#include<iostream>
#include<tuple>
#include<string>
#include <chrono>

//��������  �ṹ����

//���C++17

//����ʹ��pari,��ֻ���޶���������,tuple�����ж��
std::tuple<std::string,int> CreatePerson()
{
	return { "Obeytoor",24 };
}


#if 0
int main()
{
	auto person = CreatePerson();
	//��������
	std::string name00 = std::get<0>(person);
	int age00 = std::get<1>(person);

	//ʹ��tie
	std::string name01;
	int age01;
	std::tie(name01, age01) = CreatePerson();


	std::string name02;
	int age02;
	{
		//�ṹ����,name��age�޶�����������
		auto [name, age] = CreatePerson();
		auto [name02, age02] = CreatePerson();
		std::cout << name << std::endl;
	}
	std::cout << name02 << std::endl;//�޷�����	


}
#endif