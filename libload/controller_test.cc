#include "controller.cc"
#include "yautf.hh"

yautf::Test<int>* case1_verifyShortestTimeThreeInputs()
{
    std::string caseName = "Verify Shortest Time Between Three Items";
    std::string fixture1Name = "Fixture 1";
    std::string fixture2Name = "Fixture 2";
    std::string fixture3Name = "Fixture 3";
    int executorSlots = 2;
    int fixture1RunTime = 100;
    int fixture2RunTime = 200;
    int fixture3RunTime = 150;
    int expectedResult = fixture1RunTime;
    yautf::Test<int>* verifyShortestTime = new yautf::Test<int>(caseName, expectedResult);
    Item fixture1(fixture1Name, fixture1RunTime);
    Item fixture2(fixture2Name, fixture2RunTime);
    Item fixture3(fixture3Name, fixture3RunTime);
    Executor exec1(executorSlots);
    Executor exec2(executorSlots);
    Executor exec3(executorSlots);
    std::vector<Item>* fixtures = new std::vector<Item>();
    fixtures->push_back(fixture1);
    fixtures->push_back(fixture2);
    fixtures->push_back(fixture3);
    /* Note that it is not required right
     * now for GetShortestTime to require working
     * executors, but that COULD change in the future
     */
    std::vector<Executor>* executors = new std::vector<Executor>();
    executors->push_back(exec1);
    executors->push_back(exec2);
    executors->push_back(exec3);
    Controller ctrl(executors, fixtures);
    int actualResult = ctrl.GetShortestTime();
    verifyShortestTime->SetActual(actualResult);
    return verifyShortestTime;
}

int main()
{
    yautf::TestManager<int>* shortestTimeMgmt = new yautf::TestManager<int>();
    shortestTimeMgmt->LoadTest(case1_verifyShortestTimeThreeInputs());
    shortestTimeMgmt->VerifyTests();
    shortestTimeMgmt->DisplayAllResults();
    delete shortestTimeMgmt;
}