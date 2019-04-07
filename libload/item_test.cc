#include "item.cc"
#include "yautf.cc"

yautf::Test<bool>* case1_verifySubtraction()
{
    std::string caseName = "Verify Subtraction";
    std::string fixtureName = "Fixture";
    int runTime = 100;
    bool expectedValue = true;
    int valueToSubtract = 100;
    auto verifySubtraction = new yautf::Test<bool>(caseName, expectedValue);
    Item fixture(fixtureName, runTime);
    bool actualValue;

    fixture.SubtractTime(valueToSubtract);
    actualValue = fixture.IsDone();
    verifySubtraction->SetActual(actualValue);
    return verifySubtraction;
}

int main()
{
    auto manager = new yautf::TestManager<bool>();
    manager->LoadTest(case1_verifySubtraction());
    manager->VerifyTests();
    manager->DisplayAllResults();
    delete manager;
}