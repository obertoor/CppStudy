#include <iostream>
#include<string>


//�������� ��ʹ��using namespace std

//������Ŀ����Ӧ��ʹ��std,����˵��Ҫ��ͷ�ļ�����
//ֻ��һ��������ʹ�ã�����ʹ�ã���
namespace apple {
	void print(const std::string& text) {
		std::cout << text << std::endl;
	}
}

namespace orange {
	void print(const char* text) {
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}
}


//std������������������
void usestd() {
	using namespace std;
	cout << "usestd" << endl;
}


#if 0
using namespace apple;
using namespace orange;

int main() {
	print("hello");//hello��char[] �ȵ���orange
	apple::print("hello");//������ʽת��
	//ֱ�ӵ���print�����
}

#endif