#include "item.cc"

class Executor {
     public:
	     explicit Executor(int slots);
	     void ApplyTime(int sec);
         bool PushItem(Item* it);
         std::vector<Item> GetItems();
         bool IsFree();
     private:
         std::vector<Item>* Items;
         int Slots;
	     int OpenSlots;
};
