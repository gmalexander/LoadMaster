#include <string>
#include <array>
#include <iostream>
#include "TestResultAggregator.hh"
#include "TestResult.hh"

TestResultAggregator::TestResultAggregator(std::string aggregatorName)
{
    this->AggregatorName = aggregatorName;
}

void TestResultAggregator::DisplayResults(std::array<TestResult, s> results)
{
    int passCount = 0;
    std::cout << "For test grouping: " << this->AggregatorName << "\n";

    for(int x = 0; x < results.size(); x++)
    {
        TestResult currentResult = results[x];
        std::string textResult = currentResult->GetStatusString();

        std::cout << "\t" << "Test Case " << x << " - " << currentResult.GetName() << ": " << textResult << " \n";
        std::cout << "\t" << currentResult.GetMessage() << "\n";
        
        passCount += currentResult.GetResult();
    }
    
    std::cout << "Cases passed: " << passCount << " out of " << results.size() << "\n";
}