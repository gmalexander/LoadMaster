#ifndef item_h_h__
#define item_h_h__
#include <string>

class Item
{
    public:
       Item(std::string name, int runtime);
       void SubtractTime(int time);
       bool IsDone();
       std::string GetName();
       int GetRunTime();
    private:
       std::string Name;
       int RunTime;
       int TimeRemaining;
};
#endif
