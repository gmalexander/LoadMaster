#ifndef executor_h_h__
#define executor_h_h__
#include <string>
#include <vector>
#include "Item.hh"

class Executor
{
    public:
	Executor(int slots);
	bool ApplyTime(int sec);
        bool PushItem(Item it);
    private:
        std::Vector<Item> Items;
	int Slots;
	int OpenSlots;
	void PopItem(Item it);
}

#endif
