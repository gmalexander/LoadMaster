#include "test.hh"

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
yautf::Test<T>::Test(std::string name, T expected)
{
    this->Name = name;
    this->Expected = expected;
    this->Result = nullptr;
}

template <typename T>
void yautf::Test<T>::SetActual(T actual)
{
    this->Actual = actual;
}

template <typename T>
void yautf::Test<T>::Assert()
{
    bool result;
    if (this->Expected == this->Actual)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    this->Result = new yautf::TestResult<T>(this->Expected, this->Actual, result);
}

template <typename T>
void yautf::Test<T>::DisplayResult()
{
    if(this->Result != nullptr)
    {
        std::cout << "For test: " << this->Name << "\n";
        this->Result->DisplayResult();
    }
}

template <typename T>
yautf::Test<T>::~Test()
{
    delete this->Result;
}