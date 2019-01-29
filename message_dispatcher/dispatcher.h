#pragma once

/* msg dispacher
 * Dispacher->DispacherImpl (add msgid+MessageHandler to map and dispatch by msgid)
*/
#include <memory>

#include "msghandler.h"

namespace msg {

/* msg dispach base class*/
class Dispatcher
{
public:
    virtual ~Dispatcher()=default;
    virtual void addReceiver(std::unique_ptr<MessageHandler> msgHandler)=0;
    virtual void dispatch(int pEvent)=0;
};


}
