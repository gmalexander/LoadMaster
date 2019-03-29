#include <vector>
#include <string>
#include "Executor.hh"
#include "Item.hh"

Executor::Executor(int slots)
{
     this->Slots = slots;
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
	     this->Items.push_back(it);
	     this->OpenSlots--;
	     return OPEN_SLOTS;
     }
}

void Executor::PopItem(Item item)
{
     for(auto it = this->Items.begin(); it != this->Items.end(); it++)
     {
         if (it->GetName() == item.GetName())
         {
	         this->Items.erase(it);
	         this->OpenSlots++;
	         break;
         }
     }
}

void Executor::ApplyTime(int sec)
{
     for(auto item = this->Items.begin(); item != this->Items.end(); item++)
     {
	     item->SubtractTime(sec);
	     if(item->IsDone())
	     {
	         this->PopItem(*item);
	     }
     }
}
