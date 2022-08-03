#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

//本节主题 auto

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
//自动推导变量类型
int main() {
	auto a = 5;						//int
	auto b = 5l;					//long
	auto c = 5.5f;				//float
	auto d = "Cherno";		//char*

	string str = GetName();
	auto strs = GetName();//可以在接口改变的情况下运行

	
	
	DeviceManger dm;
	//使用命名空间
	using DeviceMap = unordered_map<string, vector<Device*>>;
	typedef unordered_map<string, vector<Device*>> DeviceMap;//较老的写法	
	DeviceMap dma= dm.GetDevice();
	// 用于复杂类型
	auto dmb=dm.GetDevice();
	const auto& dmc = dm.GetDevice();//避免复制

}
#endif