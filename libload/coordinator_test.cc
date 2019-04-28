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

/* Hand Calculation:
 * Executors: 2
 * Slots: 2
 * Items: 6
 * Item 1 RunTime: 200
 * Item 2 RunTime: 150
 * Item 3 RunTime: 45 <-- Shortest Interval
 * Item 4 RunTime: 50
 * Item 5 RunTime: 60
 * Item 6 RunTime: 300
 * Executor 1:  I1(155)     I2(105) Executor 2: I3(0)       I4(50)      ----- Interval 0: T 45
 * Executor 1:  I1(110)     I2(60)  Executor 2: I5(15)      I4(05)      ----- Interval 1: T 90
 * Executor 1:  I1(65)      I2(15)  Executor 2: I5(0)       I4(0)       ----- Interval 2: T 135
 * Executor 1:  I1(20)      I2(0)   Executor 2: I6(255)     null        ----- Interval 3: T 180
 * Executor 1:  I1(0)       null    Executor 2: I6(210)     null        ----- Interval 4: T 225
 * Executor 1:  null        null    Executor 2: I6(165)     null        ----- Interval 5: T 270
 * Executor 1:  null        null    Executor 2: I6(120)     null        ----- Interval 6: T 315
 * Executor 1:  null        null    Executor 2: I6(75)      null        ----- Interval 6: T 360
 * Executor 1:  null        null    Executor 2: I6(30)      null        ----- Interval 7: T 405
 * Executor 1:  null        null    Executor 2: I6(0)       null        ----- Interval 8: T 450
 * Total Time:  450
 */

yautf::Test<int>* case3_verifyTimeForTwoExecutorsTwoSlotsSixItems()
{
    std::string caseName = "Verify Time for Two Executors, Two Slots, and Six Items";
    int expectedValue = 450;
    auto verifyTimeForTwoExecutorsTwoSlotsSixItems = new yautf::Test<int>(caseName, expectedValue);
    std::string fixture1Name = "Fixture 1";
    std::string fixture2Name = "Fixture 2";
    std::string fixture3Name = "Fixture 3";
    std::string fixture4Name = "Fixture 4";
    std::string fixture5Name = "Fixture 5";
    std::string fixture6Name = "Fixture 6";
    int fixture1RunTime = 200;
    int fixture2RunTime = 150;
    int fixture3RunTime = 45;
    int fixture4RunTime = 50;
    int fixture5RunTime = 60;
    int fixture6RunTime = 300;
    int slots = 2;
    Item fixture1(&fixture1Name, fixture1RunTime);
    Item fixture2(&fixture2Name, fixture2RunTime);
    Item fixture3(&fixture3Name, fixture3RunTime);
    Item fixture4(&fixture4Name, fixture4RunTime);
    Item fixture5(&fixture5Name, fixture5RunTime);
    Item fixture6(&fixture6Name, fixture6RunTime);
    Executor exec1(slots);
    Executor exec2(slots);
    auto items = new std::vector<Item>();
    items->push_back(fixture1);
    items->push_back(fixture2);
    items->push_back(fixture3);
    items->push_back(fixture4);
    items->push_back(fixture5);
    items->push_back(fixture6);
    auto executors = new std::vector<Executor>();
    executors->push_back(exec1);
    executors->push_back(exec2);
    Coordinator sys(executors, items);
    int actualValue = sys.Calculate();
    verifyTimeForTwoExecutorsTwoSlotsSixItems->SetActual(actualValue);
    return verifyTimeForTwoExecutorsTwoSlotsSixItems;
}

int main()
{
    auto mgmt = new yautf::TestManager<int>();
    mgmt->LoadTest(case1_verifyTimeForOneExecutorOneSlotOneItem());
    mgmt->LoadTest(case2_verifyTimeForOneExecutorOneSlotTwoItems());
    mgmt->LoadTest(case3_verifyTimeForTwoExecutorsTwoSlotsSixItems());
    mgmt->VerifyTests();
    mgmt->DisplayAllResults();
}