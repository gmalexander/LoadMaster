#ifndef testresult_h_h__
#define testresult_h_h__
#include <string>

class TestResult
{
    public:
        TestResult(bool result, std::string name, std::string message);
        bool GetResult();
        std::string GetResultString();
        std::string GetMessage();
        std::string GetName();
    private:
        std::string Message;
        std::string Name;
        std::string SUCCESS_MESSAGE;
        std::string FAILURE_MESSAGE;
        bool Result;
};

#endif