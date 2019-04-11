#include "executor.cc"
#include "yautf.hh"

yautf::Test<bool>* case1_verifyItemPushOnNew()
{
    std::string caseName = "Verify Item Push on New Object";
    std::string fixtureName = "Fixture1";
    bool expectedValue = true;
    int slots = 1;
    int runTime = 100;
    auto itemPushOnNew = new yautf::Test<bool>(caseName, expectedValue);

    Item fixture1(fixtureName, runTime);
    Executor sys(slots);
    bool wasSuccessful = sys.PushItem(fixture1);
    bool actualValue = wasSuccessful;

    itemPushOnNew->SetActual(actualValue);
    return itemPushOnNew;
}

yautf::Test<bool>* case2_verifyItemRejectedOnFull()
{
    std::string caseName = "Verify Item Rejected On Full";
    std::string fixtureName = "Fixture1";
    std::string secondFixtureName = "Fixture2";
    bool expectedValue = false;
    int slots = 1;
    int runTime = 100;
    auto itemRejectedOnFull = new yautf::Test<bool>(caseName, expectedValue);

    Item fixture1(fixtureName, runTime);
    Item fixture2(secondFixtureName, runTime);
    Executor sys(slots);
    sys.PushItem(fixture1);
    bool wasFailure = sys.PushItem(fixture2);
    bool actualValue = wasFailure;

    itemRejectedOnFull->SetActual(actualValue);
    return itemRejectedOnFull;
}

yautf::Test<bool>* case3_verifyFullTimeAppliedOneItem()
{
    std::string caseName = "Verify Full Time Applied Against One Item";
    std::string fixtureName = "Fixture1";
    std::string secondFixtureName = "Fixture2";
    bool expectedValue = true;
    int timeToSubtract = 100;
    int slots = 1;
    int runTime = 100;
    auto fullTimeAppliedOneTime = new yautf::Test<bool>(caseName, expectedValue);

    Item fixture(fixtureName, runTime);
    Item fixture2(secondFixtureName, runTime);
    Executor sys(slots);
    sys.PushItem(fixture);
    sys.ApplyTime(timeToSubtract);
    bool wasSuccessful = sys.PushItem(fixture2);
    bool actualValue = wasSuccessful;

    fullTimeAppliedOneTime->SetActual(actualValue);
    return fullTimeAppliedOneTime;
}

yautf::Test<bool>* case4_verifyFullTimeAppliedTwoItems()
{
    std::string caseName = "Verify Full Time Applied Against Two Items";
    std::string fixtureName = "Fixture1";
    std::string secondFixtureName = "Fixture2";
    std::string thirdFixtureName = "Fixture3";
    std::string fourthFixtureName = "Fixture4";
    bool expectedValue = true;
    int timeToSubtract = 100;
    int slots = 2;
    int runTime = 100;
    auto fullTimeAppliedOneTime = new yautf::Test<bool>(caseName, expectedValue);

    Item fixture(fixtureName, runTime);
    Item fixture2(secondFixtureName, runTime);
    Item fixture3(thirdFixtureName, runTime);
    Item fixture4(fourthFixtureName, runTime);
    Executor sys(slots);
    sys.PushItem(fixture);
    sys.PushItem(fixture2);
    sys.ApplyTime(timeToSubtract);
    bool wasSuccessful = sys.PushItem(fixture3) && sys.PushItem(fixture4);
    bool actualValue = wasSuccessful;

    fullTimeAppliedOneTime->SetActual(actualValue);
    return fullTimeAppliedOneTime;
}

int main()
{
    auto manager = new yautf::TestManager<bool>();
    manager->LoadTest(case1_verifyItemPushOnNew());
    manager->LoadTest(case2_verifyItemRejectedOnFull());
    manager->LoadTest(case3_verifyFullTimeAppliedOneItem());
    manager->LoadTest(case4_verifyFullTimeAppliedTwoItems());
    manager->VerifyTests();
    manager->DisplayAllResults();
    delete manager;
}