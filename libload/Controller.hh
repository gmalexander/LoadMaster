#ifndef controller_h_h__
#define controler_h_h__
#include <string>
#include <vector>
#include "Item.hh"
#include "Executor.hh"

class Controller
{
     public:
	     Controller(int slots, std::vector<Item> items);
	     int CalculateN3Approximation();
     private:
	     std::vector<Item> Items;
	     std::vector<Executor> Executors;
		 int N3_GetShortestTime();
		 std::vector<Item>::iterator N3_LoadStep();
		 void N3_TimeStep();
};      

#endif