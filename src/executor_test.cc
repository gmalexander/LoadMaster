#include "executor.cc"
#include "yautf.hh"

/**************************************************************************************************
*    LoadMaster, a framework for calculating the duration of clustered tasks                      *
*    Copyright (C) 2019  Grant Alexander                                                          *
*                                                                                                 *
*    This program is free software: you can redistribute it and/or modify                         *
*    it under the terms of the GNU Lesser General Public License as published by                  *
*    the Free Software Foundation, either version 3 of the License, or                            *
*    (at your option) any later version.                                                          *
*                                                                                                 *
*    This program is distributed in the hope that it will be useful,                              *
*    but WITHOUT ANY WARRANTY; without even the implied warranty of                               *
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                                *
*    GNU General Public License for more details.                                                 *
*                                                                                                 *
*    You should have received a copy of the GNU General Public License                            *
*    along with this program.  If not, see <https://www.gnu.org/licenses/>.                       *
***************************************************************************************************/

yautf::Test<bool>* case1_verifyItemPushOnNew() {
    std::string caseName = "Verify Item Push on New Object";
    std::string fixtureName = "Fixture1";
    bool expectedValue = true;
    int slots = 1;
    int runTime = 100;
    auto itemPushOnNew = new yautf::Test<bool>(caseName, expectedValue);

    Item fixture1(&fixtureName, runTime);
    Executor sys(slots);
    bool wasSuccessful = sys.PushItem(&fixture1);
    bool actualValue = wasSuccessful;

    itemPushOnNew->SetActual(actualValue);
    return itemPushOnNew;
}

yautf::Test<bool>* case2_verifyItemRejectedOnFull() {
    std::string caseName = "Verify Item Rejected On Full";
    std::string fixtureName = "Fixture1";
    std::string secondFixtureName = "Fixture2";
    bool expectedValue = false;
    int slots = 1;
    int runTime = 100;
    auto itemRejectedOnFull = new yautf::Test<bool>(caseName, expectedValue);

    Item fixture1(&fixtureName, runTime);
    Item fixture2(&secondFixtureName, runTime);
    Executor sys(slots);
    sys.PushItem(&fixture1);
    bool wasFailure = sys.PushItem(&fixture2);
    bool actualValue = wasFailure;

    itemRejectedOnFull->SetActual(actualValue);
    return itemRejectedOnFull;
}

yautf::Test<bool>* case3_verifyFullTimeAppliedOneItem() {
    std::string caseName = "Verify Full Time Applied Against One Item";
    std::string fixtureName = "Fixture1";
    std::string secondFixtureName = "Fixture2";
    bool expectedValue = true;
    int timeToSubtract = 100;
    int slots = 1;
    int runTime = 100;
    auto fullTimeAppliedOneTime = new yautf::Test<bool>(caseName, expectedValue);

    Item fixture(&fixtureName, runTime);
    Item fixture2(&secondFixtureName, runTime);
    Executor sys(slots);
    sys.PushItem(&fixture);
    sys.ApplyTime(timeToSubtract);
    bool wasSuccessful = sys.PushItem(&fixture2);
    bool actualValue = wasSuccessful;

    fullTimeAppliedOneTime->SetActual(actualValue);
    return fullTimeAppliedOneTime;
}

yautf::Test<bool>* case4_verifyFullTimeAppliedTwoItems() {
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

    Item fixture(&fixtureName, runTime);
    Item fixture2(&secondFixtureName, runTime);
    Item fixture3(&thirdFixtureName, runTime);
    Item fixture4(&fourthFixtureName, runTime);
    Executor sys(slots);
    sys.PushItem(&fixture);
    sys.PushItem(&fixture2);
    sys.ApplyTime(timeToSubtract);
    bool wasSuccessful = sys.PushItem(&fixture3) && sys.PushItem(&fixture4);
    bool actualValue = wasSuccessful;

    fullTimeAppliedOneTime->SetActual(actualValue);
    return fullTimeAppliedOneTime;
}

int main() {
    auto manager = new yautf::TestManager<bool>();
    manager->LoadTest(case1_verifyItemPushOnNew());
    manager->LoadTest(case2_verifyItemRejectedOnFull());
    manager->LoadTest(case3_verifyFullTimeAppliedOneItem());
    manager->LoadTest(case4_verifyFullTimeAppliedTwoItems());
    manager->VerifyTests();
    manager->DisplayAllResults();
    delete manager;
}