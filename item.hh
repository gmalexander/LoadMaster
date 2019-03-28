#ifndef item_h_h__
#define item_h_h__
#include <string>

class Item
{
    public:
       Item(std::string name, int runtime);
       int SubtractTime(int time);
       bool IsDone();
       std::string GetName();
    private:
       std::string Name;
       int RunTime;
       int TimeRemaining;
};
