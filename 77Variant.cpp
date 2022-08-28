#include<iostream>
#include<variant>
#include<string>
#include <optional>
#include<fstream>


//�������� Variant


//C++17������
//��һ������Ŷ������͵�����
//����Ϊ���ڴ�����,�����Ӧ��ʹ��Variant,������Union
//���Ͱ�ȫ��union


//ʹ�� ö��
enum class ErrorCode
{
	None = 0,//û�д���
	NotFound = 1,//û�ҵ�
	NoAccess = 2,//���ɶ�ȡ
};

//��ȡ�ļ�.ErrorCode��Ϊ�������
std::variant<std::string, ErrorCode> ReadFileAsStrin_useVariant(const std::string& filepath)
{

	std::ifstream stream(filepath);//�����ļ���

	if (stream) {
		std::string result;
		//�ɹ���
		//�ر��ļ���
		stream.close();
		return result;
	}

	return {};
}

#if 0
int main() {
	//��ʼ��,����˵string����int�ı���
	std::variant<std::string, int> data01("12");
	std::variant<std::string, int> data02(12);
	std::variant<std::string, int> data03;

	//��UNION�ıȽ�
	union 
	{
		double a;//8�ֽ�,��˸�union��СΪ8
		float b;
	};

	std::cout << "string��СΪ" << sizeof(std::string) << "\n";
	std::cout << "data01��СΪ" <<sizeof(data01) << "\n";//��СΪ32,int=4,string=28 28+4=32
	std::cout << "data03��СΪ" <<sizeof(data03) << "\n";


	


	data03 = "data";
	std::string& strdata = std::get<std::string>(data03);//��ȡstring,ʹ��&���Ա��⸴��
	std::cout << "data03Ϊ" << std::get<std::string>(data03) << "\n";
	data03 = 12;
	std::cout << "data03Ϊ" << std::get<int>(data03) << "\n";

	int index03 = data03.index();//��ȡ���͵��±�,��string�ͷ���0,int�ͷ���1

	//����dataָ��,�������string.�򷵻ؿ�ָ��,�����,�ⷵ��ָ���ַ�����ָ��
	auto value = std::get_if<std::string>(&data03);
	if (value) {
		std::string& v = *value;
		std::cout << "data03��string\n";
	}
	else {
		std::cout << "data03����string\n";
	}

}
#endif