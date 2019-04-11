#include "executor.hh"

Executor::Executor(int slots)
{
     this->Slots = slots;
     this->OpenSlots = slots;
     this->Items = new std::vector<Item>();
}

bool Executor::PushItem(Item it)
{
     bool NO_SLOTS = false;
     bool OPEN_SLOTS = true;
     if (this->OpenSlots == 0)
     {
	     return NO_SLOTS;
     }
     else
     {
	     this->Items->push_back(it);
	     this->OpenSlots--;
	     return OPEN_SLOTS;
     }
}

void Executor::ApplyTime(int sec)
{
     for(auto item = this->Items->begin(); item != this->Items->end(); item++)
     {
	     item->SubtractTime(sec);
	     if(item->IsDone())
	     {
	         auto next = this->Items->erase(item);
              this->OpenSlots++;
              if (next == this->Items->end())
              {
                   break;
              }
	     }
     }
}
