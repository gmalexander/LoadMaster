#include "coordinator.hh"

Coordinator::Coordinator(std::vector<Executor>* executors, std::vector<Item>* items) {
    this->Control = new Controller(executors, items);
}

int Coordinator::Calculate() {
    int totalSeconds = 0;
    int interval = this->Control->GetShortestTime();
#if __DEBUG_MODE__
    std::cout << "\nDEBUG: Beginning nascent phase\n";
#endif
    while (!this->Control->GetItems().empty()) {
       this->Control->LoadStep();
       this->Control->TimeStep(interval);
       totalSeconds += interval;
#if __DEBUG_MODE__
       std::cout << "\nDEBUG: NASCENT CURRENT TIME: " << totalSeconds << "\n";
#endif
    }
#if __DEBUG_MODE__
    std::cout << "\nDEBUG: Item queue empty. Beginning senescent phase \n";
#endif
    while (!this->Control->AreExecutorsAllFree()) {
        this->Control->TimeStep(interval);
        totalSeconds += interval;
#if __DEBUG_MODE__
        std::cout << "\nDEBUG: SENESCENT CURRENT TIME: " << totalSeconds << "\n";
#endif
    }
    return totalSeconds;
}