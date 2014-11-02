// Singleton.cpp : Defines the entry point for the console application.
//
 
#include <string>
#include <iostream>
using namespace std;
class Log
{
public:
    static Log* GetInstance()
    {
        static Log oLog;
        return &oLog;
    }
 
    void Output(string strLog)
    {
        cout<<strLog<<(*m_pInt)<<endl;
    }
private:
    Log():m_pInt(new int(3))
    {
    }
    ~Log()
    {cout<<"~Log"<<endl;
        delete m_pInt;
        m_pInt = NULL;
    }
    int* m_pInt;
};
 
class Context
{
public:
    static Context* GetInstance()
    {
        static Context oContext;
        return &oContext;
    }
    ~Context()
    {
        Log::GetInstance()->Output(__FUNCTION__);
    }
 
    void fun()
    {
        Log::GetInstance()->Output(__FUNCTION__);
    }
private:
    Context(){}
    Context(const Context& context);
};
 
int main(int argc, char* argv[])
{
    Context::GetInstance()->fun();
    return 0;
}
