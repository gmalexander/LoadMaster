#include "testmanager.hh"

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
yautf::TestManager<T>::TestManager()
{
    this->Tests = new std::vector<Test<T>>();
}

template <typename T>
yautf::TestManager<T>::~TestManager()
{
    auto start = this->Tests->begin();
    auto end = this->Tests->end();
    this->Tests->erase(start, end);
    delete this->Tests;
}

template <typename T>
void yautf::TestManager<T>::LoadTest(Test<T>* tst)
{
    this->Tests->push_back(*tst);
}

template <typename T>
void yautf::TestManager<T>::VerifyTests()
{
    for(auto it = this->Tests->begin(); it != this->Tests->end(); it++)
    {
        it->Assert();
    }
}

template <typename T>
void yautf::TestManager<T>::DisplayAllResults()
{
    std::cout << "TEST RESULTS:" << "\n";
    for(auto it = this->Tests->begin(); it != this->Tests->end(); it++)
    {
        std::cout << "\n";
        it->DisplayResult();
        std::cout << "\n\n";
    }
}