#include "item.cc"
#include "yautf.hh"

yautf::Test<bool>* case1_verifyCompleteSubtraction() {
    std::string caseName = "Verify Complete Subtraction";
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

yautf::Test<bool>* case2_verifyIncompleteSubtraction() {
    std::string caseName = "Verify Incomplete Subtraction";
    std::string fixtureName = "Fixture";
    int runTime = 100;
    bool expectedValue = false;
    int valueToSubtract = 50;
    auto verifyIncompleteSubtraction = new yautf::Test<bool>(caseName, expectedValue);
    Item fixture(fixtureName, runTime);
    bool actualValue;

    fixture.SubtractTime(valueToSubtract);
    actualValue = fixture.IsDone();
    verifyIncompleteSubtraction->SetActual(actualValue);
    return verifyIncompleteSubtraction;
}

yautf::Test<bool>* case3_verifyOvertimeSubtraction() {
    std::string caseName = "Verify Overtime Subtraction";
    std::string fixtureName = "Fixture";
    int runTime = 100;
    bool expectedValue = true;
    int valueToSubtract = 101;
    auto verifyOvertimeSubtraction = new yautf::Test<bool>(caseName, expectedValue);
    Item fixture(fixtureName, runTime);
    bool actualValue;

    fixture.SubtractTime(valueToSubtract);
    actualValue = fixture.IsDone();
    verifyOvertimeSubtraction->SetActual(actualValue);
    return verifyOvertimeSubtraction;
}

int main() {
    auto manager = new yautf::TestManager<bool>();
    manager->LoadTest(case1_verifyCompleteSubtraction());
    manager->LoadTest(case2_verifyIncompleteSubtraction());
    manager->LoadTest(case3_verifyOvertimeSubtraction());
    manager->VerifyTests();
    manager->DisplayAllResults();
    delete manager;
}