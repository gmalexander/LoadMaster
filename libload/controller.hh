#include "executor.cc"

class Controller {
     public:
	     Controller(std::vector<Executor>* executors, std::vector<Item>* items);
		 int GetShortestTime();
		 void LoadStep();
		 void TimeStep(int interval);
		 bool AreExecutorsIdle();
		 std::vector<Item> GetItems();
		 std::vector<Executor> GetExecutors();
     private:
	     std::vector<Item>* Items;
	     std::vector<Executor>* Executors;
};