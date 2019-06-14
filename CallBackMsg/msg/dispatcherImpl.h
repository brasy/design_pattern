#pragma once

#include "msg/dispatcher.h"
#include "msg/msghandler.h"
#include <map>

namespace msg {

/* msg dispach sub class*/

class DispatcherImpl : public Dispatcher
{
public:
    DispatcherImpl() {}
    void addReceiver(std::unique_ptr<MessageHandler> msgHandler) override;
    void dispatch(int pEvent) override;

private:
    std::map<TmsgId, std::shared_ptr<Handler>> handlers;
};

}
