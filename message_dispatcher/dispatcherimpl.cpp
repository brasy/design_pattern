#include "dispatcherimpl.h"

namespace msg {

void DispatcherImpl::addReceiver(std::unique_ptr<MessageHandler> msgHandler)
{
    auto msgId = msgHandler->getMessageId();
    std::shared_ptr<Handler> sharedHandler{std::move(msgHandler)};
    auto result = handlers.insert(std::pair<int,std::shared_ptr<Handler>>(msgId, sharedHandler));
    std::cout<<"add message receiver result: "<<result.second<<std::endl;
}

void DispatcherImpl::dispatch(int pEvent)
{
    auto handler = handlers.find(pEvent);
    if(handler != handlers.end())
    {
        std::cout<<"handling message id: "<<pEvent<<std::endl;
        handler->second->handle(pEvent);
    }

}
}
