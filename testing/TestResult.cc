#include "TestResult.hh"
#include <string>

TestResult::TestResult(bool result, std::string name, std::string message)
{
    this->Result = result;
    this->Message = message;
    this->Name = name;
    this->SUCCESS_MESSAGE = "PASS";
    this->FAILURE_MESSAGE = "FAIL";
}

std::string TestResult::GetResultString()
{
    if (this->Result)
    {
        return this->SUCCESS_MESSAGE;
    }
    else
    {
        return this->FAILURE_MESSAGE;
    }
}

bool TestResult::GetResult()
{
    return this->Result;
}

std::string TestResult::GetMessage()
{
    return this->Message;
}

std::string TestResult::GetName()
{
    return this->Name;
}