#ifndef testaggregator_h_h__
#define testaggregator_h_h__
#include <string>
#include <array>
#include "TestAggregator.hh"

template <size_t s> class TestAggregator
{
    public:
        TestAggregator::TestAggregator(std::string aggregatorName);
        void DisplayResults(std::array<TestResult, s> results);
    private:
        std::string AggregatorName;
};

#endif