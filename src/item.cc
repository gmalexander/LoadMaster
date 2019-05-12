#include "item.hh"

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

Item::Item(std::string* name, int runtime) {
     this->RunTime = runtime;
     this->Name = *name;
     this->TimeRemaining = runtime;
}

void Item::SubtractTime(int time) {
     this->TimeRemaining -= time;
#if __DEBUG_MODE__
     std::cout << "\nDEBUG: Time Remaining: " << this->TimeRemaining << " for item: " << this->Name << "\n\n";
#endif
}

bool Item::IsDone() {
     return (this->TimeRemaining <= 0);
}

std::string Item::GetName() {
     return this->Name;
}

int Item::GetRunTime() {
     return this->RunTime;
}
