#ifndef testaggregator_h_h__
#define testaggregator_h_h__
#include <string>
#include <array>
#include "TestResultAggregator.hh"
#include "TestResult.hh"

template <size_t s> class TestResultAggregator
{
    public:
        TestResultAggregator(std::string aggregatorName);
        void DisplayResults(std::array<TestResult, s> results);
    private:
        std::string AggregatorName;
};

#endif