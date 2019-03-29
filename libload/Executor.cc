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
    if (this->OpenSlots == 0)
    {
	return false;
    }
    else
    {
	this->Items.push_back(it);
	this->OpenSlots--;
	return true;
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
    for(auto it = this->Items.begin(); it != this->Items.end(); it++)
    {
	it->SubtractTime(sec);
	if(it->IsDone())
	{
	    this->PopItem(it);
	}
    }
}
