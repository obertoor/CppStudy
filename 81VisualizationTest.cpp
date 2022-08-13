#include<iostream>
#include<string>
#include<cmath>
#include<chrono>
#include <algorithm>
#include <fstream>
#include <thread>


//��������  ���ӻ���׼����



//ʹ�ùȸ�chrome���п��ӻ�����(Chrome Tracing),��վ:chrome://tracing/
//����һ�������������ݵ�json��

//Instrumentor ��׮:ע����벢���з���

#define PROFILE 1//����Ҫ����ʱ�����Ϊ0����,�����ʱ��
#if PROFILE
#define PROFILE_SCOPE(name) InstrumentorTimer timer##__LINE__(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCSIG__)
//�������InstrumentorTimer timer(name);
//##__LINE__��Ϊ��ƴ�Ӵ����к�
//__FUNCTION__��õ�ǰ��������
//__FUNCSIG__��õ�ǰ����ǩ��
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

        //����һ���и����ļ��������ļ�,Ĭ��Ϊresults.json
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
            m_OutputStream << "\"tid\":" << result.ThreadID << ",";//�߳�ID
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
			m_StartTimepoint = std::chrono::high_resolution_clock::now();//��õ�ǰʱ�� 
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
			auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoit).time_since_epoch().count();//����ʱ�䣬��ȷ��΢��
			//time_since_epoch(),��ʾ���time_point����Ԫ��Ҳ����1970��1��1����������duration
			//time_point_cast() ת��time_point
			auto duration = end - start;
			double ms = duration * 0.001;//���������

			//���������������
            uint32_t threadID = std::hash<std::thread::id>{}(std::this_thread::get_id());
            Instrumentor::Get().WriteProfile({ my_Name,start,end ,threadID });
			//std::cout <<my_Name<<"�ĺ�ʱ:" << duration << "us(" << ms << "ms)\n";
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

    //BeginSession��EndSession֮����������ᱻ�����ض������ļ���,�������ܹ����������ݷֽ�ɶ���ļ�
    Instrumentor::Get().BeginSession("Profile");//����һ���и����ļ��������ļ�,Ĭ��Ϊresults.json
	//Function1();
	//Function2();
    RunBenchmarks();
    Instrumentor::Get().EndSession();
    //�ļ�Ŀ¼�л����results.json
}
#endif