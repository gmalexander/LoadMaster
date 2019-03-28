#ifndef controller_h_h__
#define controler_h_h__
#include <string>
#include <vector>
#include "Item.hh"
#include "Executor.hh"

class Controller
{
    public:
	Controller(int slots, Vector<Item> items);
	std::string CalculateTime();
    private:
	Vector<Item> Items;
	Vector<Executor> Executors;
}         
