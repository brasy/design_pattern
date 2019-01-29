#pragma once

/* msgid=2, AUTHENTICATION_REQ*/

#include "msghandler.h"
struct MessageInd
{
    int sessionId;
    enum status{
        sucess=0,
        fail,
        invalid
    };
};
class AuthenticationHandler : public msg::TypedMessageHandler<AUTHENTICATION_REQ, int>
{
public:
    AuthenticationHandler();
    void handleTyped(const int msg);
};

