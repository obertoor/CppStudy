#include<iostream>
#include<any>


//��������  any


//C++17������
//�洢�������͵�����

//����С������variant,���ڴ�������void*,��ʱ�ᶯ̬�����ڴ�

//�����ڴ����
#if 0
void* operator new(size_t size){
	return malloc(size);
}
#endif

//����32�ֽ�
struct CustomClass
{
	std::string a, b; //56�ֽ�
};
#if 0
int main() {

	//��ʼ��
	std::any data01;
	std::cout <<"data01��СΪ" << sizeof(data01) << "\n";//��СΪ40
	data01 = 2;
	data01 = "Cherno";
	std::cout << "data01��СΪ" << sizeof(data01) << "\n";
	data01 = std::string("Cherno");//�����ڴ����
	data01 = CustomClass();//�����ڴ����


	//��ȡstring,�޷�ת�����׳�����ת���쳣,
	data01 = std::string("Cherno");
	std::string str01=std::any_cast<std::string>(data01);
	std::string& str02 = std::any_cast<std::string&>(data01);//���⸴��


}
#endif