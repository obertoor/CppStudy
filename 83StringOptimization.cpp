#include<iostream>
#include<string>

//�������� С�ַ����Ż�(sso)


//���Ǻܳ����ַ���,��׼�Ⲣ����ѷ���
//VS2019��С�ַ�������Ľ���:���һ���ַ���������15���ַ�,�Ͳ����ڶ��Ƿ����ڴ�,ֻ��ʹ��ջ������
//ֻ��releaseģʽ�·���


#if 0
void* operator new(size_t size) {
	std::cout << "������" << size << "�ֽ�\n";
	return malloc(size);
}


int main() 
{
	std::string name = "1234567890abcdef";//û�жѷ��俪��,�洢�ھ�̬����Ļ�����
	//�������15���ַ�����ô���ȷ���8�ֽ�,�ٷ���32�ֽ�
	std::cin.get();
}

#endif