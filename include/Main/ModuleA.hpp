#pragma once
#include "PubSubModule/module.hpp"

 

class Module_A : public Module {
    public:
        Module_A() : Module() {} 
        void task();
};