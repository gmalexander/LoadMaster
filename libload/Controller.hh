#ifndef controller_h_h__
#define controler_h_h__
#include <string>
#include <vector>
#include "Item.hh"
#include "Executor.hh"

class Controller
{
    public:
	Controller(int slots, vector<Item> items);
	int CalculateN3Approximation();
    private:
	vector<Item> Items;
	vector<Executor> Executors;
}         
