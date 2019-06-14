#pragma once
#include "observer.h"
#include <iostream>
#include <string>

class ConcreteObserver : public Observer
{
public:
    ConcreteObserver(std::string name)
    {
        std::cout << "concrete observer \n";
        m_name = name;
    }
    void update(float value) override
    {
        std::cout << "concrete observer update:" << m_name << " - " << value << std::endl;
    }

private:
    std::string m_name;
};
