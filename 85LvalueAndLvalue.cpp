#include<iostream>


//��������  ��ֵ����ֵ

//��ֵ: ĳ�ִ洢֧�ֵı���
//��ֵ����ʱֵ

//��ֵ��������ֵ���õı��ʶ�����ֵ

#if 0
//����һ����ֵ������ʱ��
int GetValue01() {
	return 10;
}



//��ֵ����	
int& GetValue02() {
	static int value = 10;	
	return value;
}


//ʹ��const ���Խ�����ֵ������ֵ������
//��ֵ������ͨ������һ����ʱ��temp��ʵ������Ȼ����ֵ����
void SetValue(const int& value) {

}

static void PrintName(std::string& name) {
	std::cout <<"Lvalue" << name << std::endl;
}

//ʹ��&& ����ʹ�øú���ֻ������ֵ����ʱ����
//��ʱ�����õ��ĸ��ƣ��������ڵ�
static void PrintName(std::string&& name) {
	std::cout <<"Rvalue:" << name << std::endl;
}




int main()
{
	//�󲿷�����£���ֵ������ֵ����
	int i = 10;
	//����
	int a = i;


	GetValue02() = 20;

	//���Խ�����ֵ����
	SetValue(10);

	
	std::string firstname = "weng";
	std::string lasttname = "jiahao";
	//�ұߵı��ʽ����ֵ���������ַ������һ����ʱ�ַ�����Ȼ��ֵ����ֵ
	std::string fullname = firstname + lasttname;
	PrintName(fullname);
	//�޷����ã�����PrintName�ǽ���const string&  ���� string&&
	PrintName(firstname + lasttname);




	std::cin.get();
}
#endif