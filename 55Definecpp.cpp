#include<iostream>
#include<string>

using namespace std;
//�������� ��

//Ԥ������ִ��.���ı��滻
// �ı��ı����ɵķ�ʽ
//�����ڱ����Ԥ����׶�


//�������debugģʽ�£������´���
//������-c++-Ԥ������-Ԥ������һ����Ӷ�Ӧ����

#ifdef CS_DEBUG
//Ҳ���Զ���CS_DEBUG=1(�����пո�
//#if CS_DEBUG ==1

#define LOG(x) cout<<x<<endl;

#else
//����
//#elif defined(CS_RELEASE)

#define LOG(x) 
//	�л���releaseģʽ����ʲô�������

#endif // CS_DEBUG

//���ٽ��ô���
#if 0

#endif
//���к�
#define MAIN int main()\
{\
	cin.get();\
}

#if 0
int main()
{

	LOG("hello");
	

}
#endif