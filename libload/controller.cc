#include "controller.hh"

Controller::Controller(std::vector<Executor> executors, std::vector<Item> items)
{
    this->Items = items;
    this->Executors = executors;
}

int Controller::GetShortestTime()
{
    int interval = INT_MAX;
    for(auto item = this->Items->begin(); item < this->Items->end(); item++)
    {
       int runtime = item->GetRunTime();
       if (interval > runtime)
       {
	      interval = runtime;
       }
    }
    return interval;
}

std::vector<Item>::iterator Controller::LoadStep(std::vector<Item>::iterator nextItem)
{
    for(auto exec = this->Executors->begin(); exec != this->Executors->end(); exec++)
    {
	    if (nextItem != this->Items->end())
	    {
	       bool success = false;
	       do
	       {
             success = exec->PushItem(*nextItem);
	          if (success)
             {
                nextItem++;
             }
	       } while (success);
	    }
    }
    return nextItem;
}

void Controller::TimeStep(int interval)
{
    for(auto exec = this->Executors->begin(); exec != this->Executors->end(); exec++)
    {
       exec->ApplyTime(interval);
    }
}
	  
    
