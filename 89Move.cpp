#include<iostream>




//��������  �ƶ�����

#if 0
class String {
public:
	String() = default;
	String(const char* string)
	{
		printf("����!\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}
	//�������캯��,���
	String(const String& other)
	{
		printf("����!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	//noexcept
	//���һ�������е��õ�����������Ϊnoexcept�������������δ����Ϊnoexcept��Ҳ����noexcept��Ч����
	//���һ��noexcept�����У��׳����쳣�������ֱ���ں����쳣����ֹ�������ⲿ����Դ������ʽ���ͷţ�


	//move���캯��,���ܵ�����ֵ,�����ƶ����캯��
	//ʵ�����ǽӹ�ԭ�����ַ���
	String(String&& other) noexcept//��Ӧ���׳��쳣
	{
		printf("�ƶ�!\n");
		m_Size = other.m_Size;
		//m_Data = new char[m_Size];//���Ƿ����µ��ڴ�
		m_Data = other.m_Data;//�µ�ָ�룬ָ��ԭ�����ڴ�
		//memcpy(m_Data, other.m_Data, m_Size);

		//��ֹԭ����ʵ��delete,��ԭ����ָ���ÿ�(Ұָ��)
		//�����ն���
		other.m_Size = 0;
		other.m_Data = nullptr;
	}


	~String() {
		printf("����!\n");
		delete m_Data;
	}

	void Print()
	{
		for (uint32_t i = 0; i < m_Size; i++) {
			printf("%c", m_Data[i]);
		}
		printf("\n");

	}
private:
	char* m_Data;
	uint32_t m_Size;
};

class Entity {
public:
	Entity(const String& name)
		:m_Name(name)
	{

	}
	Entity(String&& name)
		:m_Name((String&&)name)//������ʽ������Ϊ��ʱ���� 
		//:m_Name(std::move(name));//Ч��ͬ��
	{

	}

	void PrintName() {
		m_Name.Print();
	}
private:
	String m_Name;
	//�ƶ�������Ϊ�˽���main�д�����Stringֱ�ӷŵ�������ڴ棬�����Ǹ��ƴ��ݽ�����������m_Names
};


int main() {
	//Entity entity(String("Cherno"));
	//entity.PrintName();
	//���������ƣ����ᷢ������String���ݸ�entity��ʱ��Ḵ��Stirng

	Entity entity("Cherno");
	entity.PrintName();

	std::cin.get();
}
#endif