#include "testresult.hh"

/**************************************************************************************************
*    YAUTF, Yet Another Unit Testing Framework. A microframework for quick C++ unit testing.      *
*    Copyright (C) 2019  Grant Alexander                                                          *
*                                                                                                 *
*    This program is free software: you can redistribute it and/or modify                         *
*    it under the terms of the GNU General Public License as published by                         *
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

template <typename T>
yautf::TestResult<T>::TestResult() {}

template <typename T>
yautf::TestResult<T>::TestResult(T expected, T actual, bool result)
{
    this->Expected = expected;
    this->Actual = actual;
    this->Result = result;
}

template <typename T>
void yautf::TestResult<T>::DisplayResult()
{
    std::string resultReadable;
    if (this->Result)
    {
        resultReadable = "SUCCESS";
    }
    else
    {
        resultReadable = "FAILURE";
    }
    std::cout << "RESULT: " << resultReadable << "\n";
    std::cout << "Expected: " << this->Expected << " Actual: " << this->Actual << "\n";
}