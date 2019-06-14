#pragma once

#include "msghandler.h"

class CmActivationReqHandler : public msg::TypedMessageHandler<ACT_MSG,int>
{
public:
    CmActivationReqHandler();
    void handleTyped(const int msg);
};
