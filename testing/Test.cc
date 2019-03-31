#include "TestResult.hh"
#include "Test.hh"
#include <string>

template <typename T>
Test<T>::Test(T expected, T actual, std::string name)
{
    this->Expected = expected;
    this->Actual = actual;
    this->Name = name;
}

template <typename T>
TestResult Test<T>::Assert()
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