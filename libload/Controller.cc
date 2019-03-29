#include <vector>
#include <string>
#include <climits>
#include "Controller.hh"
#include "Executor.hh"
#include "Item.hh"

Controller::Controller(vector<Executor> executors, vector<Item> items)
{
    this->Items = items;
    this->Executors = executors;
}

int Controller::N3_GetShortestTime()
{
    int interval = INT_MAX;
    for(auto item = this->Items.begin(); item < this->Items.end(); item++)
    {
       int runtime = item->GetRunTime();
       if (interval > runtime)
       {
	      interval = runtime;
       }
    }
    return interval;
}

std::vector<Item>::iterator Controller::N3_LoadStep(std::vector<Item>::iterator nextItem)
{
    for(auto exec = this->Executors.begin(); exec != this->Executors.end(); exec++)
    {
	    if (nextItem != this->Items.end())
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

void Controller::N3_TimeStep()
{
    for(auto exec = this->Executors.begin(); exec != this->Executors.end(); exec++)
    {
       exec->ApplyTime(interval);
    }
}

int Controller::CalculateN3Approximation()
{
    bool alldone = false;
    int totalSeconds = 0;
    auto nextItem = this->Items.begin();
    int interval = this->N3_GetShortestTime();
    while (!alldone)
    {
       nextItem = this->N3_LoadStep(nextItem);
       this->N3_TimeStep();
       totalSeconds += interval;
    }
    return totalSeconds;
}
	  
    
