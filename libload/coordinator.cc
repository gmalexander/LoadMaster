#include "coordinator.hh"

Coordinator::Coordinator(std::vector<Executor> executors, std::vector<Item> items)
{
    this->Control = new Controller(executors, items);
}

int Coordinator::Calculate()
{
    bool alldone = false;
    int totalSeconds = 0;
    int interval = this->Control->GetShortestTime();
    while (!this->Control->GetItems()->empty())
    {
       this->Control->LoadStep();
       this->Control->TimeStep(interval);
       totalSeconds += interval;
    }
    return totalSeconds;
}