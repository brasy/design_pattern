#pragma once

#include "subscriber.h"

namespace runtimeView{

class RuntimeObserver
{
public:
    virtual ~RuntimeObserver() = default;
    virtual void onChanges(const subscribeApi::ChangeData&) = 0;
};

}
