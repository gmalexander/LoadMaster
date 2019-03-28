#ifndef executor_h_h__
#define executor_h_h__
#include <string>
#include <vector>
#include "Item.hh"

class Executor
{
    public:
	Executor(int slots);
	void ApplyTime(int sec);
        void PushItem(Item it);
    private:
        std::Vector<Item> items;
	void PopItem(Item it);
}

#endif
