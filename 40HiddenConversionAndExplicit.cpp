#include<iostream>
#include<string>


//��������  C++��ʽת����explicit�ؼ���

//explicit ������ʽת��

//��ʽת��ֻ��ִ��һ��
#if 0
namespace my_40 {
	class Entity
	{
	private:
		std::string m_Name;
		int m_Age;
	public:
		Entity(const std::string& name)
			:m_Name(name),m_Age(-1){}
		Entity(int age)
			:m_Name("unknow"), m_Age(age) {}

	};

	void PrintEnity(const Entity& entity)
	{

	}
}




int main()
{
	using namespace my_40;

	PrintEnity(22);
	//������ʽת����ֱ��ʹ��int������Entity

	//PrintEnity("Cherno");
	//char������Ͽ���ֹ��������string����ʽת���޷�char����>>string>>Entity

	PrintEnity(std::string("Cherno"));//string>>Entity
	PrintEnity(Entity("Cherno")); //char���� >> string

	Entity a("Cherno");
	Entity b("22");


}
#endif