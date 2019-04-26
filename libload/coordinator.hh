#include "controller.cc"

class Coordinator {
    public:
        Coordinator(std::vector<Executor>* executors, std::vector<Item>* items);
        int Calculate();
    private:
        Controller* Control;
};