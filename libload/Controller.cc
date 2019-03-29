#include <vector>
#include <string>
#include "Controller.hh"
#include "Executor.hh"
#include "Item.hh"

Controller::Controller(vector<Executor> executors, vector<Item> items)
{
    this->Items = items;
    this->Executors = executors;
}

int Controller::CalculateN3Approximation()
{
    bool alldone = false;
    int totalSeconds = 0;
    int interval = 0;
    auto nextItem = this->Items.begin();
    for(auto item = this->Items.begin(); item < this->Items.end(); item++)
    {
       if (item == this->Items.begin())
       {
	   interval = item->GetRunTime();
       }
       if (interval > item->GetRunTime())
       {
	   interval = item->GetRunTime();
       }
    }
    while (!alldone)
    {
       for(auto exec = this->Executors.begin(); exec != this->Executors.end(); exec++)
       {
	  if (nextItem != this->Items.end())
	  {
	     bool success = false;
	     do
	     {
                success = exec->PushItem(*nextItem);
	        success ? it++ : NULL;
	     } while (success);
	  }
       }
       for(auto exec = this->Executors.begin(); exec != this->Executors.end(); exec++)
       {
          exec->ApplyTime(interval);
       }
       totalSeconds += interval;
    }
    return totalSeconds;
}
	  
    
