#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

//�������� auto

class Device {

};
class DeviceManger {
private:
	unordered_map<string, vector<Device*>> m_Devices;
public:
	const unordered_map<string, vector<Device*>>& GetDevice() const
	{
		return m_Devices;
	}
};



string GetName() {
	return "obeytoor";
}
#if 0
//�Զ��Ƶ���������
int main() {
	auto a = 5;						//int
	auto b = 5l;					//long
	auto c = 5.5f;				//float
	auto d = "Cherno";		//char*

	string str = GetName();
	auto strs = GetName();//�����ڽӿڸı�����������

	
	
	DeviceManger dm;
	//ʹ�������ռ�
	using DeviceMap = unordered_map<string, vector<Device*>>;
	typedef unordered_map<string, vector<Device*>> DeviceMap;//���ϵ�д��	
	DeviceMap dma= dm.GetDevice();
	// ���ڸ�������
	auto dmb=dm.GetDevice();
	const auto& dmc = dm.GetDevice();//���⸴��

}
#endif