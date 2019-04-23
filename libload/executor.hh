#include "item.cc"

class Executor {
     public:
	     explicit Executor(int slots);
	     void ApplyTime(int sec);
         bool PushItem(Item* it);
     private:
         std::vector<Item>* Items;
	     int OpenSlots;
};
