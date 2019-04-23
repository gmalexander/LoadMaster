#include "controller.cc"
#include "yautf.hh"

/* You may notice a lot of code reuse. The reason for this is as follows:
 * - Boilerplate for readable function calls
 * - Lack of factory functions (this is a TODO)
 * - Memory Management not yet refined in the library (this is also a TODO)
 * - Non-coupling of cases - I want to keep them in isolation in the event a change is made to the
 *   SUT which would cause say two cases to still be able to be coupled, but the third case to not be
 */

yautf::Test<int>* case1_verifyShortestTimeThreeInputsShortestFirst()
{
    std::string caseName = "Verify Shortest Time Between Three Items Shortest First";
    std::string fixture1Name = "Fixture 1";
    std::string fixture2Name = "Fixture 2";
    std::string fixture3Name = "Fixture 3";
    int executorSlots = 2;
    int fixture1RunTime = 100;
    int fixture2RunTime = 200;
    int fixture3RunTime = 150;
    int expectedResult = fixture1RunTime;
    auto verifyShortestTime = new yautf::Test<int>(caseName, expectedResult);
    Item fixture1(fixture1Name, fixture1RunTime);
    Item fixture2(fixture2Name, fixture2RunTime);
    Item fixture3(fixture3Name, fixture3RunTime);
    Executor exec1(executorSlots);
    Executor exec2(executorSlots);
    Executor exec3(executorSlots);
    auto fixtures = new std::vector<Item>();
    fixtures->push_back(fixture1);
    fixtures->push_back(fixture2);
    fixtures->push_back(fixture3);
    auto executors = new std::vector<Executor>();
    executors->push_back(exec1);
    executors->push_back(exec2);
    executors->push_back(exec3);
    Controller ctrl(executors, fixtures);
    int actualResult = ctrl.GetShortestTime();
    verifyShortestTime->SetActual(actualResult);
    return verifyShortestTime;
}

yautf::Test<int>* case2_verifyShortestTimeThreeInputsShortestSecond()
{
    std::string caseName = "Verify Shortest Time Between Three Items Shortest Second";
    std::string fixture1Name = "Fixture 1";
    std::string fixture2Name = "Fixture 2";
    std::string fixture3Name = "Fixture 3";
    int executorSlots = 2;
    int fixture1RunTime = 200;
    int fixture2RunTime = 100;
    int fixture3RunTime = 150;
    int expectedResult = fixture2RunTime;
    auto verifyShortestTime = new yautf::Test<int>(caseName, expectedResult);
    Item fixture1(fixture1Name, fixture1RunTime);
    Item fixture2(fixture2Name, fixture2RunTime);
    Item fixture3(fixture3Name, fixture3RunTime);
    Executor exec1(executorSlots);
    Executor exec2(executorSlots);
    Executor exec3(executorSlots);
    auto fixtures = new std::vector<Item>();
    fixtures->push_back(fixture1);
    fixtures->push_back(fixture2);
    fixtures->push_back(fixture3);
    auto executors = new std::vector<Executor>();
    executors->push_back(exec1);
    executors->push_back(exec2);
    executors->push_back(exec3);
    Controller ctrl(executors, fixtures);
    int actualResult = ctrl.GetShortestTime();
    verifyShortestTime->SetActual(actualResult);
    return verifyShortestTime;
}

yautf::Test<int>* case3_verifyShortestTimeThreeInputsShortestThird()
{
    std::string caseName = "Verify Shortest Time Between Three Items Shortest Third";
    std::string fixture1Name = "Fixture 1";
    std::string fixture2Name = "Fixture 2";
    std::string fixture3Name = "Fixture 3";
    int executorSlots = 2;
    int fixture1RunTime = 200;
    int fixture2RunTime = 150;
    int fixture3RunTime = 100;
    int expectedResult = fixture3RunTime;
    auto verifyShortestTime = new yautf::Test<int>(caseName, expectedResult);
    Item fixture1(fixture1Name, fixture1RunTime);
    Item fixture2(fixture2Name, fixture2RunTime);
    Item fixture3(fixture3Name, fixture3RunTime);
    Executor exec1(executorSlots);
    Executor exec2(executorSlots);
    Executor exec3(executorSlots);
    auto fixtures = new std::vector<Item>();
    fixtures->push_back(fixture1);
    fixtures->push_back(fixture2);
    fixtures->push_back(fixture3);
    auto executors = new std::vector<Executor>();
    executors->push_back(exec1);
    executors->push_back(exec2);
    executors->push_back(exec3);
    Controller ctrl(executors, fixtures);
    int actualResult = ctrl.GetShortestTime();
    verifyShortestTime->SetActual(actualResult);
    return verifyShortestTime;
}

yautf::Test<int>* case4_verifyLoadStepThreeItemsOneExecutorOneSlotLoads()
{
    std::string caseName = "Verify Load Step with Three Items, One Executor, and One Slot";
    std::string fixture1Name = "fixture1";
    std::string fixture2Name = "fixture2";
    std::string fixture3Name = "fixture3";
    int runTime = 100;
    int slots = 1;
    int expectedResult = 2;
    auto verifyLoadStepThreeItemsOneExecutorOneSlot = new yautf::Test<int>(caseName, expectedResult);
    Item fixture1(fixture1Name, runTime);
    Item fixture2(fixture2Name, runTime);
    Item fixture3(fixture3Name, runTime);
    Executor exec(slots);
    auto items = new std::vector<Item>();
    items->push_back(fixture1);
    items->push_back(fixture2);
    items->push_back(fixture3);
    auto executors = new std::vector<Executor>();
    executors->push_back(exec);
    Controller ctrl(executors, items);
    ctrl.LoadStep();
    std::vector<Item> currentItems = ctrl.GetItems();
    int actualResult = currentItems.size();
    verifyLoadStepThreeItemsOneExecutorOneSlot->SetActual(actualResult);
    return verifyLoadStepThreeItemsOneExecutorOneSlot;
}

yautf::Test<int>* case5_verifyLoadStepThreeItemsTwoExecutorsOneSlotLoads()
{
    std::string caseName = "Verify Load Step with Three Items, Two Executors, and One Slot";
    std::string fixture1Name = "fixture1";
    std::string fixture2Name = "fixture2";
    std::string fixture3Name = "fixture3";
    int runTime = 100;
    int slots = 1;
    int expectedResult = 1;
    auto verifyLoadStepThreeItemsOneExecutorOneSlot = new yautf::Test<int>(caseName, expectedResult);
    Item fixture1(fixture1Name, runTime);
    Item fixture2(fixture2Name, runTime);
    Item fixture3(fixture3Name, runTime);
    Executor exec1(slots);
    Executor exec2(slots);
    auto items = new std::vector<Item>();
    items->push_back(fixture1);
    items->push_back(fixture2);
    items->push_back(fixture3);
    auto executors = new std::vector<Executor>();
    executors->push_back(exec1);
    executors->push_back(exec2);
    Controller ctrl(executors, items);
    ctrl.LoadStep();
    std::vector<Item> currentItems = ctrl.GetItems();
    int actualResult = currentItems.size();
    verifyLoadStepThreeItemsOneExecutorOneSlot->SetActual(actualResult);
    return verifyLoadStepThreeItemsOneExecutorOneSlot;
}

yautf::Test<int>* case6_verifyLoadStepThreeItemsTwoExecutorsTwoSlotsLoads()
{
    std::string caseName = "Verify Load Step with Three Items, Two Executors, and Two Slots";
    std::string fixture1Name = "fixture1";
    std::string fixture2Name = "fixture2";
    std::string fixture3Name = "fixture3";
    int runTime = 100;
    int slots = 2;
    int expectedResult = 0;
    auto verifyLoadStepThreeItemsOneExecutorOneSlot = new yautf::Test<int>(caseName, expectedResult);
    Item fixture1(fixture1Name, runTime);
    Item fixture2(fixture2Name, runTime);
    Item fixture3(fixture3Name, runTime);
    Executor exec1(slots);
    Executor exec2(slots);
    auto items = new std::vector<Item>();
    items->push_back(fixture1);
    items->push_back(fixture2);
    items->push_back(fixture3);
    auto executors = new std::vector<Executor>();
    executors->push_back(exec1);
    executors->push_back(exec2);
    Controller ctrl(executors, items);
    ctrl.LoadStep();
    std::vector<Item> currentItems = ctrl.GetItems();
    int actualResult = currentItems.size();
    verifyLoadStepThreeItemsOneExecutorOneSlot->SetActual(actualResult);
    return verifyLoadStepThreeItemsOneExecutorOneSlot;
}

int main()
{
    auto mgmt = new yautf::TestManager<int>();
    mgmt->LoadTest(case1_verifyShortestTimeThreeInputsShortestFirst());
    mgmt->LoadTest(case2_verifyShortestTimeThreeInputsShortestSecond());
    mgmt->LoadTest(case3_verifyShortestTimeThreeInputsShortestThird());
    mgmt->LoadTest(case4_verifyLoadStepThreeItemsOneExecutorOneSlotLoads());
    mgmt->LoadTest(case5_verifyLoadStepThreeItemsTwoExecutorsOneSlotLoads());
    mgmt->LoadTest(case6_verifyLoadStepThreeItemsTwoExecutorsTwoSlotsLoads());
    mgmt->VerifyTests();
    mgmt->DisplayAllResults();
    delete mgmt;
}