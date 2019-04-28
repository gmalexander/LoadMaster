#include "executor.hh"
#include <iostream>

Executor::Executor(int slots) {
     this->Slots = slots;
     this->Items = new std::vector<Item>();
}

bool Executor::PushItem(Item* it) {
     bool NO_PUSH = false;
     bool PUSH = true;
     if (this->Slots == this->Items->size()) {
	     return NO_PUSH;
     }
     else {
	     this->Items->push_back(*it);
	     return PUSH;
     }
}

void Executor::ApplyTime(int sec) {
     auto item = this->Items->begin();
     while (item != this->Items->end()) {
          item->SubtractTime(sec);
          if(item->IsDone()) {
               item = this->Items->erase(item);
          }
          else {
               item++;
          }
     }
}

bool Executor::IsFree()
{
    return (this->Items->empty());
}

std::vector<Item> Executor::GetItems() {
    return *(this->Items);
}