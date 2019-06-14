#pragma once

#include "observer.h"
#include <iostream>
namespace runtimeView {

class PortObserver : public RuntimeObserver
{
public:
    PortObserver();
    virtual ~PortObserver() = default;
    void onChanges(const subscribeApi::ChangeData&) override;
};
}

