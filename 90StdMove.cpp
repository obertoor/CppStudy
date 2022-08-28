#include<iostream>


//��������  std::move���ƶ���ֵ������

//������Դ�����·���(new)





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
	//�������캯��
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


	//move���캯��,���ܵ�����ֵ
	//ʵ�����ǽӹ�ԭ�����ַ���
	String(String&& other) noexcept//��Ӧ���׳��쳣
	{
		printf("�ƶ�!\n");
		m_Size = other.m_Size;
		//m_Data = new char[m_Size];//���Ƿ����µ��ڴ�
		m_Data = other.m_Data;//�µ�ָ�룬ָ��ԭ�����ڴ�
		//memcpy(m_Data, other.m_Data, m_Size);

		//��ֹԭ����ʵ��delete,��ԭ����ָ���ÿ�
		//�����ն���
		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	//�ƶ���ֵ�����
	String& operator=(String&& other) noexcept {
		//printf("�ƶ���ֵ�����!\n");
		if (this != &other) {
			delete[] m_Data;

			m_Size = other.m_Size;
			m_Data = other.m_Data;


			other.m_Size = 0;
			other.m_Data = nullptr;
		}
		else {
			return *this;
		}
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




void func(int &n) {
	std::cout << "Lvalue:" << n << std::endl;
}
void func(int &&n) {
	std::cout << "Rvalue:" << n << std::endl;
}



//����ת�����ܴ���������ֵ������ֵ�Լ�׼ȷ��������ֵ��ֵ
//��������
//�����۵�����:(ģ������Ч)
//int& &&t => int& t
//int&& &&t => int&& t
template<typename T>
void revoke(T &&t)
{
	//forward<T>(t):���TΪ��ֵ����,��tת��ΪT���͵���ֵ
	//���TΪ��ֵ����,��tת��ΪT���͵���ֵ
	func(std::forward<T>(t));
	//func(std::move(t));//��t�����ֵ

	//func(t);
}




#if 0
int main() {

	int i = 10;
	int &m = i;
	int &&n = 100;


	//revoke(i);
	//revoke(10);

	revoke(static_cast<int&>(m));
	revoke(static_cast<int&&>(n));


	//Entity entity(String("Cherno"));
	//entity.PrintName();
	//���������ƣ����ᷢ������String���ݸ�entity��ʱ��Ḵ��Stirng

	//Entity entity("Cherno");
	//entity.PrintName();

	//String string = "Hello";
	//String dest = (String&&)string;
	//String dest((String&&)string);//Ч��ͬ��	
	//String dest = std::move(string);


	String apple = "Apple";
	String dest;

	apple.Print();
	dest.Print();

	dest = std::move(apple);//apple�����ݱ��ƶ���dest,apple���  apple���ڴ�����dest���ڴ�
	//dest.operator=(std::move(apple));
	apple.Print();
	dest.Print();

	std::cin.get();
}
#endif