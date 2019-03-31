#include "TestResult.hh"
#include "Test.hh"
#include <string>

Test::Test(T expected, T actual, std::string name)
{
    this->Expected = expected;
    this->Actual = actual;
    this->Name = name;
}

TestResult Test::Assert()
{
    std::string message = "Expected: " + std::to_string(this->Expected) + " Actual: " + std::to_string(this->Actual) + "\n";
    if (this->Actual == this->Expected)
    {
        bool success = true;
        result = new TestResult(success, this->Name, message);
    }
    else
    {
        bool failure = false;
        result = new TestResult(failure, this->Name, message);
    }
    return TestResult;
}