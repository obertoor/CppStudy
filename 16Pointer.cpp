#include <iostream>
//�������� ָ��

//������һ�ִ洢�ڴ��ַ������	



#if 0
int main() {
	int var = 8;
	void* pvar = &var;//&��һ��������ȡ��ַ������,&��һ��������
	//���Կ��ڴ�, ����-����-�ڴ�-�ڴ�һ

	int* pivar = &var;//�����Ͳ��ܲ���
	*pivar =50 ;//�������ã�������

	char* buffer = new char[8];//����˸��ֽڵ��ڴ棬����һ��ָ����ڴ��ָ��
	memset(buffer, 0, 8);//����ڴ溯��

	char** pbuffer = &buffer;//˫ָ��,�Ӻ���ǰ������buffer�ĵ�ַ����С�ˣ���С��

	delete[] buffer;

	void* ptr = NULL;//������ָ��,��nullptr����
	//���������ڲ����ڴ�
}

#endif