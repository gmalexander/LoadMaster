#include "item.cc"

class Executor {
     public:
	     explicit Executor(int slots);
	     void ApplyTime(int sec);
         bool PushItem(Item* it);
         std::vector<Item> GetItems();
     private:
         std::vector<Item>* Items;
	     int OpenSlots;
};
