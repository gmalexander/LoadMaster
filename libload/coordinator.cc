#include "coordinator.hh"

Coordinator::Coordinator(std::vector<Executor> executors, std::vector<Item> items)
{
    this->control = new Controller(executors, items);
}

int Coordinator::CalculateN3Approximation()
{
    bool alldone = false;
    int totalSeconds = 0;
    auto nextItem = this->Items.begin();
    int interval = this->N3_GetShortestTime();
    while (!alldone)
    {
       nextItem = this->N3_LoadStep(nextItem);
       this->N3_TimeStep(interval);
       totalSeconds += interval;
    }
    return totalSeconds;
}