#ifndef test_h_h__
#define test_h_h__
#include <string>

template <typename T> class Test
{
    public:
       Test(T expected, T actual, std::string name);
       TestResult Assert();
    private:
       std::string Name;
       T Expected;
       T Actual;
};

#endif