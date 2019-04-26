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

int main()
{
    auto mgmt = new yautf::TestManager<int>();
    mgmt->LoadTest(case1_verifyTimeForOneExecutorOneSlotOneItem());
    mgmt->VerifyTests();
    mgmt->DisplayAllResults();
}