#include "yautf.hh"
#include "coordinator.cc"

yautf::Test<int>* case1_verifyTimeForOneExecutorOneSlotOneItem()
{
    std::string caseName = "Verify Proper Time for One Executor with One Slot and One Item";
    int expectedValue = 100;
    auto verifyTimeForOneExecutorOneSlotOneItem = new yautf::Test<int>(caseName, expectedValue);
    std::string fixtureName = "Fixture 1";
    int runTime = 100;
    int slots = 1;
    Item fixture(&fixtureName, runTime);
    Executor exec(slots);
    auto items = new std::vector<Item>();
    items->push_back(fixture);
    auto executors = new std::vector<Executor>();
    executors->push_back(exec);
    Coordinator coord(executors, items);
    int actualValue = coord.Calculate();
    verifyTimeForOneExecutorOneSlotOneItem->SetActual(actualValue);
    return verifyTimeForOneExecutorOneSlotOneItem;
}

yautf::Test<int>* case2_verifyTimeForOneExecutorOneSlotTwoItems()
{
    std::string caseName = "Verify Proper Time for One Executor with One Slot and Two Items";
    int expectedValue = 200;
    auto verifyTimeForOneExecutorOneSlotOneItem = new yautf::Test<int>(caseName, expectedValue);
    std::string fixtureName = "Fixture 1";
    std::string fixture2Name = "Fixture 2";
    int runTime = 100;
    int runTime2 = 150;
    int slots = 1;
    Item fixture(&fixtureName, runTime);
    Item fixture2(&fixture2Name, runTime2);
    Executor exec(slots);
    auto items = new std::vector<Item>();
    items->push_back(fixture);
    items->push_back(fixture2);
    auto executors = new std::vector<Executor>();
    executors->push_back(exec);
    Coordinator coord(executors, items);
    int actualValue = coord.Calculate();
    verifyTimeForOneExecutorOneSlotOneItem->SetActual(actualValue);
    return verifyTimeForOneExecutorOneSlotOneItem;
}

int main()
{
    auto mgmt = new yautf::TestManager<int>();
    mgmt->LoadTest(case1_verifyTimeForOneExecutorOneSlotOneItem());
    mgmt->LoadTest(case2_verifyTimeForOneExecutorOneSlotTwoItems());
    mgmt->VerifyTests();
    mgmt->DisplayAllResults();
}