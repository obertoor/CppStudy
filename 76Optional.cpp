#include<iostream>
#include<string>
#include<fstream>
#include<optional>

//��������  OPTIONAL


//�����ز�ȷ���ķ�������


//��ȡ�ļ�,ʹ��OutSuccess����Ƿ��ѯ�ɹ�
std::string ReadFileAsStrin(const std::string& filepath,bool& OutSuccess) 
{
	std::ifstream stream(filepath);//�����ļ���

	if (stream) {
		std::string result;
		//�ɹ���
		//�ر��ļ���
		stream.close();
		OutSuccess = true;
		return result;
	}

	return std::string();//���ؿ��ַ�
}

//ʹ��OPTIONAL
//C++17������
std::optional<std::string> ReadFileAsStrin_useOptional(const std::string& filepath)
{

	std::ifstream stream(filepath);//�����ļ���

	if (stream) {
		std::string result;
		//�ɹ���
		//�ر��ļ���
		stream.close();
		return result;
	}

	return {};//����optinal
}
#if 0
int main() {
	std::optional<std::string> data = ReadFileAsStrin_useOptional("data.txt");

	std::string value = data.value_or("Not present!");//������ݴ��ڣ��������ݣ����򷵻����Ǵ���value_or��ֵ
	std::cout << value << std::endl;
	//���ķ���ֵ
	std::optional<int> count;
	int c = count.value_or(100);

	if (data.has_value()) {//���Ϊtrue,�ɹ���,Ҳ����ʹ��if(data),data��������һ��bool�����
		std::cout << "�ɹ��򿪣�" << std::endl;
		std::string& string = *data;//�����ã�Ȼ���������ͨ�ַ�������ʽ����
		std::string strings = data.value();//Ҳ��һ�ַ��ʷ���
	}
	else {
		std::cout << "��ʧ�ܣ�\n";
	}


	std::cin.get();
}
#endif