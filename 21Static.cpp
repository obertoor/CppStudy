#include<iostream>
#include <string>


//�������� static


//����߽ṹ����ʹ��static��ֻ�ܶԶ������ķ��뵥Ԫ�ɼ�
//����߽ṹ���ڲ�ʹ��static����̬���������������ʵ��������������ͳ�����ʵ��������


//ֻ����������뵥Ԫ���ӣ��򵥵�˵����ֻ������ļ�����Ч���ڱ���ʱ�����������ļ���s_Variale������Ƶ�int������Ҳ����Ӱ�졣
static int s_Variale=5;

extern int extern_int;//extern��ǻ����ⲿȥѰ�Ҷ��塣extern_int=5;��Ҫͬʱ����

static void PrinName(std::string name) {
	std::cout << name << std::endl;
}

#if 0
int main() {
	PrinName("obeytoor");
	std::cout << extern_int << std::endl;
}
#endif
