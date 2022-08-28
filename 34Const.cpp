#include <iostream>

using namespace std;
//�������� const

//const�����ŵ���ȳ����ŵĳЩ�������䣬���ǿ����ƹ�
//�����ں��������ڳ�����constexpr����ֻ������
//const������������ߵĶ�����������û���������������ұߵĶ���
//const��������һ��ı����������ı������ǳ�֮Ϊ����������������ֵ�ǲ����޸ĵġ�

class Entity
{
private:
	int m_X;
	int* m_Y;
	mutable int var;//mutable�ƹ�const����
public:
	//ֻ��������Ч�ķ���
	int GetX() const//��ŵ���޸����Ա,const�޶���������ͬ��
	{
		//m_X=2;//����
		var = 2;//mutable,�����ò���
		return m_X;
	}
	int GetX() {
		return m_X;
	}
	//����һ�����ܱ��޸ĵ�ָ��
	const int* const GetY() const {
		return m_Y;
	}
};

void PrintEntity(const Entity& e) {//�������ݲ������Ա��⸴��Entity
	cout << e.GetX() << endl;
}


#if 0
int main() {
	int a = 5;
	const int b = 5;
#if 0
	b = 4;//�޷��ı�b�������Լ�ֵ
#endif
	int* c = new int;
	*c = 4;
	cout << *c << endl;
	c = (int*)&b;//ʹ�� (int*)�ƿ�const����
	cout << *c << endl;


	const  int* cc = new int;//��ζ�Ų����޸ĸ�ָ��ָ������ݣ�ֻ�ܻ���ַ
#if 0
	*cc = 4;//�޷��ı�����
#endif
	cc = (int*)&b;//ָ�뱾�����¸�ֵ



	int* const ccc = new int;//��ַ�����޸�,ֻ�ܻ�����
	*ccc = 8;
#if 0
	ccc = (int*)&b;
#endif


	int const* cccc = new int;//ͬ  const int* cccc = new int
	//�ؼ���const λ��  * ����һ��

	const int* const ccccc = new int;

	//ָ�볣��
	//ָ������ָ�����
	//����ͨ��ͨ��ָ������ı���ָ��Ķ����ֵ
	int ca = 10;
	const int* pa;
	pa = &ca;
	//*pa = ca;//�������ʽ�����ǿ����޸ĵ���ֵ��
	ca = 20;//�Ϸ�
	cout << "pa:" << pa << endl;
	pa = &a;
	cout << "ca:" << ca << endl;


	//��ָ��(����ַ)
	//��ֵ(��ַ)���ܸı�,�����ڶ���ʱ��ʼ��
	int ac = 10;
	int bc = 20;
	int* const pc = &ac;
	*pc = ac;//�Ϸ�
	//pc = &bc;//�������ʽ�����ǿ����޸ĵ���ֵ��
	cout << "ac:" << ac << endl;
	cout << "pc:" << pc << endl;

	ac = 50;
	cout <<"ac:" << ac << endl;
	cout << "pc:" << pc << endl;
	//��ַ����,��ֵ���Ըı�
	return 0;
}
#endif