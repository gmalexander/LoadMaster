#include <string>
#include <array>
#include "Item.cc"
#include "TestResultAggregator.hh"
#include "TestResult.hh"
#include "Test.hh"

TestResult case1_verifyNameInstantiation()
{
    std::string caseName = "Verify Name Instantiation";
    std::string expectedName = "fixture1";
    int runtime = 1;

    Item fixture(expectedName, runtime);
    std::string actualName = fixture.GetName();
    Test<std::string> test(expectedName, actualName, caseName);
    TestResult result = test.Assert();
    return result;
}

TestResult case2_verifyRunTimeInstantiation()
{
    std::string caseName = "Verify RunTime Instantiation";
    std::string name = "fixture2";
    int expectedRunTime = 100;

    Item fixture(name, expectedRunTime);
    int actualRunTime = fixture.GetRunTime();
    Test<int> test(expectedRunTime, actualRunTime, caseName);
    TestResult result = test.Assert();
    return result;
}

int main()
{
   const int NUMBER_OF_CASES = 2;
   std::string groupingName = "Verify Item";
   TestResult case1 = case1_verifyNameInstantiation();
   TestResult case2 = case2_verifyRunTimeInstantiation();
   std::array<TestResult, NUMBER_OF_CASES> cases = {case1, case2};
   TestResultAggregator<NUMBER_OF_CASES> resultAggregate(groupingName);
   resultAggregate.DisplayResults(cases);
}