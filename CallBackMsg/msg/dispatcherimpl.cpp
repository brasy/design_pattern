#include "msg/dispatcherImpl.h"
#include <iostream>

namespace msg {

void DispatcherImpl::addReceiver(std::unique_ptr<MessageHandler> msgHandler)
{
    auto msgId = msgHandler->getMessageId();
    std::shared_ptr<Handler> sharedHandler{std::move(msgHandler)};
    auto result = handlers.insert(std::pair<int,std::shared_ptr<Handler>>(msgId, sharedHandler));
    std::cout<<"DispatcherImpl: add message receiver result: "<<result.second<<std::endl;
}

void DispatcherImpl::dispatch(int pEvent)
{
    auto handler = handlers.find(pEvent);
    if (handler != handlers.end())
    {
        std::cout << "DispatcherImpl: handle msg: " << std::to_string(pEvent) << std::endl;
        handler->second->handle(pEvent);
    }
    else {
        std::cout << "DispatcherImpl: unable to dispatch msg " << std::to_string(pEvent) << std::endl;
    }
}

}
