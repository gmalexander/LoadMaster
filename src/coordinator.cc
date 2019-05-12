#include "coordinator.hh"

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

Coordinator::Coordinator(std::vector<Executor>* executors, std::vector<Item>* items) {
    this->Control = new Controller(executors, items);
}

int Coordinator::Calculate() {
    int totalSeconds = 0;
    int interval = this->Control->GetShortestTime();
#if __DEBUG_MODE__
    std::cout << "\nDEBUG: Beginning nascent phase\n";
#endif
    while (!this->Control->GetItems().empty()) {
       this->Control->LoadStep();
       this->Control->TimeStep(interval);
       totalSeconds += interval;
#if __DEBUG_MODE__
       std::cout << "\nDEBUG: NASCENT CURRENT TIME: " << totalSeconds << "\n";
#endif
    }
#if __DEBUG_MODE__
    std::cout << "\nDEBUG: Item queue empty. Beginning senescent phase \n";
#endif
    while (!this->Control->AreExecutorsAllFree()) {
        this->Control->TimeStep(interval);
        totalSeconds += interval;
#if __DEBUG_MODE__
        std::cout << "\nDEBUG: SENESCENT CURRENT TIME: " << totalSeconds << "\n";
#endif
    }
    return totalSeconds;
}