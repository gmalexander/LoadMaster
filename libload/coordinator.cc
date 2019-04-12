#include "coordinator.hh"

Coordinator::Coordinator(std::vector<Executor> executors, std::vector<Item> items)
{
    this->Control = new Controller(executors, items);
}

int Coordinator::CalculateN3Approximation()
{
    bool alldone = false;
    int totalSeconds = 0;
    auto nextItem = this->Control->Items.begin();
    int interval = this->Control->GetShortestTime();
    while (!alldone)
    {
       nextItem = this->Control->LoadStep(nextItem);
       this->Control->TimeStep(interval);
       totalSeconds += interval;
    }
    return totalSeconds;
}