#include<iostream>
#include<string>


//��������  ��Ա��ʼ���б�


//���캯���г�ʼ�����Ա(����)��һ�ַ�ʽ

class Example
{
public:
	Example()
	{
		std::cout << "����Example\n";
	}
	Example(int a) 
	{
		std::cout << "����Eample(" << a << ")\n";
	}
};


class Entity 
{
private:
	std::string m_Name;
	Example m_Example;
public:
	//��ʼ���б���Ҫ����������˳��ȥ��ʼ��
	Entity()
		:m_Name("Unknown"),m_Example(8)//ֻ����һ��
	{
		//���������,��������ι��캯��,һ��Ĭ��,ȥ��ʼ��m_Name,Ȼ�����this����
		//m_Name = "Unknown";
		
		//m_Example = Example(8);
		//�ṹ������
	}
	Entity(const std::string& name) 
	{

	}
	const std::string& GetName() const {//����const�ú�����ʽ�����thisָ�뽫constָ��
		return m_Name;
	}

};
#if 0
int main()
{
	Entity e;

	//std::cout << e.GetName() << std::endl;
}
#endif