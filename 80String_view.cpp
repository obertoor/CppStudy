#include<string>
#include<iostream>




//��������  ������ַ�������



//�ַ�����ʽ�������ַ���������Ҫ�����ڴ�
//C++17�¼���
//string_view,�ַ�����һ����ͼ
//������һ��const charָ�룬ָ��������ӵ�е������ַ������ټ���һ����С
//���Ա������


static uint32_t s_AllocCount = 0;//��¼�������
#if 0
 void* operator new(size_t size) {
	s_AllocCount++;
	std::cout << "������" << size << "�ֽ�\n";
	return malloc(size);
}
#endif
namespace my_80 {
	void PrintName(const std::string& name) {
		std::cout << name << std::endl;
	}
	void PrintName_view(std::string_view name) {
		std::cout << name << std::endl;
	}
	//ֱ�Ӵ�ֵ�ᵼ�·��������һ
	void PrintNames(std::string name) {
		std::cout << name << std::endl;
	}
}

#if 0
int main() {

	using namespace my_80;

	std::string name = "weng jiahao";//��ʱ�Ѿ�������8�ֽ�
	const char* name_char = "weng jiahao";//���ھ�̬�ַ�������ȷ����
	//std::string firstName = name.substr(0, 4);
	//std::string lastName = name.substr(5, 10);

	//ʹ��string_view,�������ӷ������
	std::string_view firstName(name.c_str(),4);
	std::string_view lastName(name.c_str()+5, 6);

	std::string_view firstName_char(name_char, 4);
	std::string_view lastName_char(name_char+5, 6);

	PrintName_view(firstName);
	PrintName_view(lastName);
	//PrintNames(firstName);

	//PrintName(name);
	PrintName_view("cherno");//���ᵼ�·���
	//PrintName("cherno");//��Ȼ���յ�������,����Ȼ��Ҫ����,�����Ҫ�����ڴ�
	std::cout << "�������:" << s_AllocCount << std::endl;

	std::cin.get();
}
#endif