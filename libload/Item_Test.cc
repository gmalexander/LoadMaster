#include <string>
#include <array>
#include "Item.cc"
#include "TestResultAggregator.hh"
#include "TestResult.hh"
#include "Test.hh"

TestResult case1_verifyNameInstantiation()
{
    TestResult result;
    std::string caseName = "Verify Name Instantiation";
    std::string expectedName = "fixture1";
    int runtime = 1;

    Item fixture(expectedName, runtime);
    std::string actualName = fixture.GetName();
    std::string commonMessage = "Expected: " + expectedName + " Actual: " + actualName;
    Test test(expectedName, actualName, caseName);
    TestResult result = test.Assert();
    return TestResult;
}

TestResult case2_verifyRunTimeInstantiation()
{
    TestResult result;
    std::string caseName = "Verify RunTime Instantiation";
    std::string name = "fixture2";
    int expectedRunTime = 100;

    Item fixture(name, expectedRunTime);
    std::string actualRunTime = fixture.GetRunTime();
    std::string commonMessage = "Expected: " + expectedRunTime + " Actual: " + actualRunTime;
    Test test(expectedRunTime, actualRunTime, caseName);
    TestResult result = test.Assert();
    return TestResult;
}

int main()
{
   int numberOfCases = 2;
   std::string groupingName = "Verify Item"
   TestResult case1 = case1_verifyNameInstantiation();
   TestResult case2 = case2_verifyRunTimeInstantiation();
   std::array<TestResult, numberOfCases> cases = {case1, case2};
   TestResultAggregator<numberOfCases> resultAggregate(groupingName);
   resultAggregate.DisplayResults(cases);
}