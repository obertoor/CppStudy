#include<iostream>
#include<string>
#include<cmath>
#include<chrono>
#include <algorithm>
#include <fstream>
#include <thread>


//本节主题  可视化基准测试



//使用谷歌chrome进行可视化分析(Chrome Tracing),网站:chrome://tracing/
//加载一个包含所有数据的json包

//Instrumentor 插桩:注入代码并进行分析

#define PROFILE 1//不需要分析时将其改为0即可,剥离计时器
#if PROFILE
#define PROFILE_SCOPE(name) InstrumentorTimer timer##__LINE__(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCSIG__)
//用于替代InstrumentorTimer timer(name);
//##__LINE__是为了拼接代码行号
//__FUNCTION__获得当前函数名称
//__FUNCSIG__获得当前函数签名
#else
#define PROFILE_SCOPE(name)
#endif

namespace my_81 {


    struct ProfileResult
    {
        std::string Name;
        long long Start, End;
        uint32_t ThreadID;
    };

    struct InstrumentationSession
    {
        std::string Name;
    };

    class Instrumentor
    {
    private:
        InstrumentationSession* m_CurrentSession;
        std::ofstream m_OutputStream;
        int m_ProfileCount;
    public:
        Instrumentor()
            : m_CurrentSession(nullptr), m_ProfileCount(0)
        {
        }

        //创建一个有给定文件名的新文件,默认为results.json
        void BeginSession(const std::string& name, const std::string& filepath = "results.json")
        {
            m_OutputStream.open(filepath);
            WriteHeader();
            m_CurrentSession = new InstrumentationSession{ name };
        }

        void EndSession()
        {
            WriteFooter();
            m_OutputStream.close();
            delete m_CurrentSession;
            m_CurrentSession = nullptr;
            m_ProfileCount = 0;
        }

        void WriteProfile(const ProfileResult& result)
        {
            if (m_ProfileCount++ > 0)
                m_OutputStream << ",";

            std::string name = result.Name;
            std::replace(name.begin(), name.end(), '"', '\'');

            m_OutputStream << "{";
            m_OutputStream << "\"cat\":\"function\",";
            m_OutputStream << "\"dur\":" << (result.End - result.Start) << ',';
            m_OutputStream << "\"name\":\"" << name << "\",";
            m_OutputStream << "\"ph\":\"X\",";
            m_OutputStream << "\"pid\":0,";
            m_OutputStream << "\"tid\":" << result.ThreadID << ",";//线程ID
            m_OutputStream << "\"ts\":" << result.Start;
            m_OutputStream << "}";

            m_OutputStream.flush();
        }

        void WriteHeader()
        {
            m_OutputStream << "{\"otherData\": {},\"traceEvents\":[";
            m_OutputStream.flush();
        }

        void WriteFooter()
        {
            m_OutputStream << "]}";
            m_OutputStream.flush();
        }

        static Instrumentor& Get()
        {
            static Instrumentor instance;
            return instance;
        }
    };





	class InstrumentorTimer
	{
	public:
        InstrumentorTimer(const char* name)
			: my_Name(name), my_Stopped(false)
		{
			m_StartTimepoint = std::chrono::high_resolution_clock::now();//获得当前时间 
		}
		~InstrumentorTimer()
		{
			if (!my_Stopped) {
				stop(); 
			}
		}

		void stop() {
			auto endTimepoit = std::chrono::high_resolution_clock::now();//time_point
			auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
			auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoit).time_since_epoch().count();//花费时间，精确到微秒
			//time_since_epoch(),表示这个time_point距离元年也就是1970年1月1日所经过的duration
			//time_point_cast() 转换time_point
			auto duration = end - start;
			double ms = duration * 0.001;//计算毫秒数

			//可以输出到跟踪器
            uint32_t threadID = std::hash<std::thread::id>{}(std::this_thread::get_id());
            Instrumentor::Get().WriteProfile({ my_Name,start,end ,threadID });
			//std::cout <<my_Name<<"的耗时:" << duration << "us(" << ms << "ms)\n";
			my_Stopped = true;
		}
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
		const char* my_Name;
		bool my_Stopped;
	};
}

void Function1()
{
	using namespace my_81;
    //InstrumentorTimer timer("Function1");
    //PROFILE_SCOPE("Function1");
    PROFILE_FUNCTION();
	for (int i = 0; i < 1000; i++) {
		std::cout << "Hello World #" << i << std::endl;
	}
}

void Function2()
{
	using namespace my_81;
    //InstrumentorTimer timer("Function2");
    //PROFILE_SCOPE("Function2");
    PROFILE_FUNCTION();
	for (int i = 0; i < 1000; i++) {
		std::cout << "Hello World #" << sqrt(i) << std::endl;
	}
}


void RunBenchmarks() {
    using namespace my_81;
    //InstrumentorTimer timer("RunBenchmarks");
    //PROFILE_SCOPE("RunBenchmarks");
    PROFILE_FUNCTION();
    std::cout << "Runing Benchmarks......\n";
    std::thread a([]() {Function1(); });
    std::thread b([]() {Function2(); });

    //Function1();
    //Function2();
    a.join();
    b.join();
}

#if 0
int main() 
{
	using namespace my_81;

    //BeginSession和EndSession之间做的事情会被放入特定分析文件中,这样做能够将分析数据分解成多个文件
    Instrumentor::Get().BeginSession("Profile");//创建一个有给定文件名的新文件,默认为results.json
	//Function1();
	//Function2();
    RunBenchmarks();
    Instrumentor::Get().EndSession();
    //文件目录中会出现results.json
}
#endif