#include "controller.cc"

class Coordinator {
    public:
        Coordinator(std::vector<Executor>* executors, std::vector<Item>* items);
        int CalculateN3Approximation();
    private:
        Controller* Control;
}