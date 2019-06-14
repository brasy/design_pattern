#pragma once
#include <memory>

class Observer;

class Subject
{
public:
    virtual ~Subject() = default;
    virtual void attach(std::shared_ptr<Observer>) = 0;
    virtual void detach(std::shared_ptr<Observer>) = 0;
    virtual void notify() = 0;
};
