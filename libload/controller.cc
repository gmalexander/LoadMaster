#include "controller.hh"

Controller::Controller(std::vector<Executor>* executors, std::vector<Item>* items)
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

void Controller::LoadStep()
{
    for(auto executor = this->Executors->begin(); executor != this->Executors->end(); executor++)
    {
        Item currentItem = this->Items->pop_back();
        bool successful = executor->PushItem(currentItem);
        if (!successful)
        {
            this->Items->push_back(currentItem);
        }
    }
}

void Controller::TimeStep(int interval)
{
    for(auto exec = this->Executors->begin(); exec != this->Executors->end(); exec++)
    {
       exec->ApplyTime(interval);
    }
}

std::vector<Item> GetItems()
{
    return *(this->Items);
}

std::vector<Executor> GetExecutors()
{
    return *(this->Executors);
}
    
