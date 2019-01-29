#pragma once
/* msgid=1, INIT_REQ */
#include "msghandler.h"

class CcInitHandler : public msg::TypedMessageHandler<INIT_REQ,int>
{
public:
    CcInitHandler();
    void handleTyped(const int msg);
};
