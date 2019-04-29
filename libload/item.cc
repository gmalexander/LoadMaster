#include "item.hh"

Item::Item(std::string* name, int runtime) {
     this->RunTime = runtime;
     this->Name = *name;
     this->TimeRemaining = runtime;
}

void Item::SubtractTime(int time) {
     this->TimeRemaining -= time;
#ifdef __DEBUG_MODE__
     std::cout << "\nDEBUG: Time Remaining: " << this->TimeRemaining << " for item: " << this->Name << "\n\n";
#endif
}

bool Item::IsDone() {
     return (this->TimeRemaining <= 0);
}

std::string Item::GetName() {
     return this->Name;
}

int Item::GetRunTime() {
     return this->RunTime;
}
