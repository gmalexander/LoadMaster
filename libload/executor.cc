#include "executor.hh"
#include <iostream>

Executor::Executor(int slots) {
     this->Slots = slots;
     this->Items = new std::vector<Item>();
#ifdef __DEBUG_MODE__
     std::cout << "\nEXECUTOR AT ADDRESS " << this << " INSTANTIATED WITH SLOTS " << this->Slots << "\n";
#endif
}

bool Executor::PushItem(Item* it) {
     bool NO_PUSH = false;
     bool PUSH = true;
     if (this->Slots == this->Items->size()) {
#ifdef __DEBUG_MODE__
         std::cout << "\nDEBUG: Item: " << it->GetName() << " NOT pushed to executor at address " << this << "\n";
#endif
	     return NO_PUSH;
     }
     else {
	     this->Items->push_back(*it);
#ifdef __DEBUG_MODE__
	     std::cout << "\nDEBUG: Item: " << it->GetName() << " pushed to executor at address " << this << "\n";
#endif
	     return PUSH;
     }
}

void Executor::ApplyTime(int sec) {
     auto item = this->Items->begin();
     while (item != this->Items->end()) {
#ifdef __DEBUG_MODE__
          std::cout << "\nDEBUG: Applying Time: " << sec << " on item: " << item->GetName() << " on executor at address " << this << "\n";
#endif
          item->SubtractTime(sec);
          if(item->IsDone()) {
#ifdef __DEBUG_MODE__
              std::cout << "\nDEBUG: ITEMS DELETION FOR EXECUTOR AT ADDRESS: " << this << "\n";
              for(auto it : *(this->Items))
              {
                  std::cout << "\nItem: " << it.GetName() << " on executor at address " << this << "\n";
              }
#endif
              item = this->Items->erase(item);
#ifdef __DEBUG_MODE__
              std::cout << "\nDEBUG: ITEMS AFTER DELETION FOR EXECUTOR AT ADDRESS: " << this << "\n";
              for(auto it : *(this->Items))
              {
                  std::cout << "\nItem: " << it.GetName() << "\n";
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
#ifdef __DEBUG_MODE__
    std::cout << "\nDEBUG: EXECUTOR AT ADDRESS " << this << " REPORTS IS EMPTY: " << this->Items->empty() << "\n";
#endif
    return (this->Items->empty());
}

std::vector<Item> Executor::GetItems() {
    return *(this->Items);
}