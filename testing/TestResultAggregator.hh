#ifndef testaggregator_h_h__
#define testaggregator_h_h__
#include <string>
#include <array>
#include "TestResultAggregator.hh"
#include "TestResult.hh"

template <size_t S> class TestResultAggregator
{
    public:
        TestResultAggregator(std::string aggregatorName);
        void DisplayResults(std::array<TestResult, S> results);
    private:
        std::string AggregatorName;
};

#endif