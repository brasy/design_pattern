#pragma once

#include "msghandler.h"

namespace provision {
template<int MsgId, typename MsgType>
class ProvisionBase : public msg::TypedMessageHandler<MsgId,MsgType>
{
public:
    virtual ~ProvisionBase<MsgId,MsgType>()=default;
    void handleTyped(const MsgType& msg)
    {}
    void addHandler(std::shared_ptr<HandlerType> handler, ProvisioningType type)
    {}
};

class ActDispatcher : public ProvisionBase<ACT_MSG,int>
{
public:
    ActDispatcher() {}
};
}
