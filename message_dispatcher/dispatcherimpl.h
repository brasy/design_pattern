#pragma once

#include "dispatcher.h"
#include <map>

namespace msg {

/* msg dispach sub class*/

class DispatcherImpl : public Dispatcher
{
public:
    DispatcherImpl() {}
    void addReceiver(std::unique_ptr<MessageHandler> msgHandler) override;
    void dispatch(int pEvent);

private:
    std::map<TmsgId, std::shared_ptr<Handler>> handlers;
};

}

