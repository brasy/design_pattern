#pragma once

#include "subject.h"
#include "observer.h"
#include <iostream>
#include <list>

// 具体主题
class ConcreteSubject : public Subject
{
public:
    ConcreteSubject() { m_value = 10.0; }

    void setValue(float value) {
        m_value = value;
    }

    //override must be have, as the keyword can make sure the actually over ride
    void attach(std::shared_ptr<Observer> observer) override {
        m_observers.push_back(observer);
    }

    void detach(std::shared_ptr<Observer> observer) override {
        m_observers.remove(observer);
    }

    void notify() override {
        std::list<std::shared_ptr<Observer>>::iterator it = m_observers.begin();
        while (it != m_observers.end()) {
            (*it)->update(m_value);
            ++it;
        }
    }

private:
    std::list<std::shared_ptr<Observer>> m_observers;  // 观察者列表
    float m_value;
};
