#include <iostream>
#include<string>

//�������� ���ƿռ�

//��ҪĿ�ģ�����������ͻ
//�౾��Ҳ��һ�����ƿռ�
//class A {
//public:
//	int values;
//	void Aprint(const std::string& text) {
//		std::cout << text << std::endl;
//	}
//};

namespace Firsnamespace {
	void print(const std::string& text) {
		std::cout << text << std::endl;
	}
}

//�����ռ��Ƕ��
namespace Seconcenamespace { namespace Fristnamespace{ namespace function{
	void printf(const std::string& text) {
		std::cout << text << std::endl;
	}
}}}
#if 0
int main() {

	using Firsnamespace::print;//��������print
	namespace a = Firsnamespace;//ȡ���� �ڸ�����������Ч


	//��ͬ
	//using namespace Seconcenamespace::Fristnamespace::function;
	using namespace Seconcenamespace::Fristnamespace;
	using namespace function;

	Seconcenamespace::Fristnamespace::function::printf("hello");
	a::print("hello");
}
#endif