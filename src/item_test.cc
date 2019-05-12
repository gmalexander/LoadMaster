#include "item.cc"
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

yautf::Test<bool>* case1_verifyCompleteSubtraction() {
    std::string caseName = "Verify Complete Subtraction";
    std::string fixtureName = "Fixture";
    int runTime = 100;
    bool expectedValue = true;
    int valueToSubtract = 100;
    auto verifySubtraction = new yautf::Test<bool>(caseName, expectedValue);
    Item fixture(&fixtureName, runTime);
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
    Item fixture(&fixtureName, runTime);
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
    Item fixture(&fixtureName, runTime);
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