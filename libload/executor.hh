#include "item.cc"

class Executor
{
     public:
	     Executor(int slots);
	     void ApplyTime(int sec);
         bool PushItem(Item it);
     private:
         std::vector<Item>* Items;
	     int Slots;
	     int OpenSlots;
	     void PopItem(Item it);
};
