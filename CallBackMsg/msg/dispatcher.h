#pragma once
#include <memory>
#include "msg/msghandler.h"

namespace msg
{

class Dispatcher
{
public:
    virtual ~Dispatcher() = default;

    virtual void addReceiver(std::unique_ptr<MessageHandler> messageHandler) = 0;
    virtual void dispatch(int pEvent) = 0;
};
}
