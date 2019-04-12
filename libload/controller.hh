#include "executor.cc"

class Controller
{
     public:
	     Controller(std::vector<Executor>* executors, std::vector<Item>* items);
		 int N3_GetShortestTime();
		 std::vector<Item>::iterator N3_LoadStep(std::vector<Item>::iterator nextItem);
		 void N3_TimeStep(int interval);
     private:
	     std::vector<Item>* Items;
	     std::vector<Executor>* Executors;
};