#include "controller.hh"
#include <iostream>

Controller::Controller(std::vector<Executor>* executors, std::vector<Item>* items) {
    this->Items = items;
    this->Executors = executors;
}

int Controller::GetShortestTime() {
    int interval = INT_MAX;
    for(auto item = this->Items->begin(); item < this->Items->end(); item++) {
       int runtime = item->GetRunTime();
       if (interval > runtime) {
	      interval = runtime;
       }
    }
    return interval;
}

void Controller::LoadStep() {
    for(auto executor : *(this->Executors)) {
        bool successful;
        do {
            if (!this->Items->empty()) {
                Item currentItem = this->Items->at(this->Items->size() - 1);
                successful = executor.PushItem(&currentItem);
                if (successful) {
                    this->Items->pop_back();
                }
            }
            else {
                successful = false;
            }
        } while (successful);
    }
}

void Controller::TimeStep(int interval) {
    for(auto executor : *(this->Executors)) {
       executor.ApplyTime(interval);
    }
}

bool Controller::AreExecutorsIdle() {
    for (auto executor : *(this->Executors)) {
        if (!executor.IsFree()) {
            return false;
        }
    }
    return true;
}

std::vector<Item> Controller::GetItems() {
    return *(this->Items);
}

std::vector<Executor> Controller::GetExecutors() {
    return *(this->Executors);
}
    
