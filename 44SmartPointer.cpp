#include<iostream>
#include<memory>
#include<string>


//�������� ����ָ��


//������ԭʼָ��İ�װ
//�Զ���delete��ָ��

//unique_ptr:������ָ��,���ܸ���,����и�����,��ô����unique_ptr��ָ��ͬһ���ڴ�,��ô��ָ������ʱ���ͷ�����

//shared_ptr:ʵ�ַ�ʽȡ���ڱ������ͱ�����ʹ�õı�׼��,ʹ�����ü���(����ָ���ж��ٸ�����)
//������ָ��ӵ��һ���ڴ�,�п��ƿ�,���ڴ洢���ü���


//weak_ptr:��ָ��,�����������ü�����shared_ptr,��Ӱ����ָ������������

//operator=()	���� = ��ֵ�������weak_ptrָ�����ֱ�ӱ�weak_ptr����shared_ptr����ָ�븳ֵ��
//swap(x)		����x��ʾһ��ͬ���͵�weak_ptr����ָ�룬�ú������Ի���2����ͬ����weak_ptrָ������ݡ�
//reset()		����ǰweak_ptrָ����Ϊ��ָ�롣
//use_count()	�鿴ָ��͵�ǰweak_ptrָ����ͬ��shared_ptrָ���������
//expired()		�жϵ�ǰweak_ptrָ���Ƿ���ڣ�ָ��Ϊ�գ�����ָ��Ķ��ڴ��Ѿ����ͷţ���
//lock()		�����ǰweak_ptr�Ѿ����ڣ���ú����᷵��һ���յ�shared_ptrָ�룻��֮���ú�������һ���͵�ǰweak_ptrָ��ָ����ͬ��shared_ptrָ��


class Entity
{
public:
	Entity() {
		std::cout << "����Entity" << std::endl;
	}
	~Entity() {
		std::cout << "����Entity" << std::endl;
	}
	void Print() {
		std::cout << "����Entity��" << std::endl;
	}
};
#if 0
int main()
{
	std::shared_ptr<Entity> e0;
	std::weak_ptr<Entity> weakentity;
	{
		//std::unique_ptr<Entity> entity(new Entity());//��Ҫ��ʽ�ĵ��ù��캯��(explicit),���ܵõ�����ָ��
		std::unique_ptr<Entity> entity = std::make_unique<Entity>();//���ַ�ʽ�Ƚϰ�ȫ,�������캯���׳��쳣�ᰲȫ


		std::shared_ptr<Entity> shareentity = std::make_shared<Entity>();
		//���ü�����һ,��new����:�����ڴ��Լ����ƿ��ڴ��ֿ�����,��ʹ��make_shared����һ�����
		weakentity = std::make_shared<Entity>();
		e0 = shareentity;


		entity->Print();
	}
	 

}
#endif 