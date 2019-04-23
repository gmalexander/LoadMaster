#include <vector>
#include <string>
#include <climits>

class Item {
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
