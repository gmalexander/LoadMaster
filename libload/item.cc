#include "item.hh"

Item::Item(std::string name, int runtime)
{
     this->RunTime = runtime;
     this->Name = name;
     this->TimeRemaining = runtime;
}

void Item::SubtractTime(int time)
{
     this->TimeRemaining -= time;
}

bool Item::IsDone()
{
     if(this->TimeRemaining <= 0)
     {
	     return true;
     }
     else
     {
	     return false;
     }
}

std::string Item::GetName()
{
     return this->Name;
}

int Item::GetRunTime()
{
     return this->RunTime;
}
