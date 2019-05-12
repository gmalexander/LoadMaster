#include "executor.hh"
#include <iostream>

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

Executor::Executor(int slots) {
     this->Slots = slots;
     this->Items = new std::vector<Item>();
#if __DEBUG_MODE__
     std::cout << "\nDEBUG: EXECUTOR AT ADDRESS " << this << " INSTANTIATED WITH SLOTS " << this->Slots << "\n";
#endif
}

bool Executor::PushItem(Item* it) {
     bool NO_PUSH = false;
     bool PUSH = true;
     if (this->Slots == this->Items->size()) {
#if __DEBUG_MODE__
         std::cout << "\nDEBUG: Item: " << it->GetName() << " NOT pushed to executor at address " << this << "\n";
#endif
	     return NO_PUSH;
     }
     else {
	     this->Items->push_back(*it);
#if __DEBUG_MODE__
	     std::cout << "\nDEBUG: Item: " << it->GetName() << " pushed to executor at address " << this << "\n";
#endif
	     return PUSH;
     }
}

void Executor::ApplyTime(int sec) {
     auto item = this->Items->begin();
     while (item != this->Items->end()) {
#if __DEBUG_MODE__
          std::cout << "\nDEBUG: Applying Time: " << sec << " on item: " << item->GetName() << " on executor at address " << this << "\n";
#endif
          item->SubtractTime(sec);
          if(item->IsDone()) {
#if __DEBUG_MODE__
              std::cout << "\nDEBUG: ITEMS DELETION FOR EXECUTOR AT ADDRESS: " << this << "\n";
              for(auto it : *(this->Items))
              {
                  std::cout << "\nDEBUG: Item: " << it.GetName() << " on executor at address " << this << "\n";
              }
#endif
              item = this->Items->erase(item);
#if __DEBUG_MODE__
              std::cout << "\nDEBUG: ITEMS AFTER DELETION FOR EXECUTOR AT ADDRESS: " << this << "\n";
              for(auto it : *(this->Items))
              {
                  std::cout << "\nDEBUG: Item: " << it.GetName() << "\n";
              }
#endif
          }
          else {
               item++;
          }
     }
}

bool Executor::IsFree()
{
#if __DEBUG_MODE__
    std::cout << "\nDEBUG: EXECUTOR AT ADDRESS " << this << " REPORTS IS EMPTY: " << this->Items->empty() << "\n";
#endif
    return (this->Items->empty());
}

std::vector<Item> Executor::GetItems() {
    return *(this->Items);
}