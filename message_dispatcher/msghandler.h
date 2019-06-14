#pragma once

/* msg handler base/sub class for factoryMode
 * Handler->MessageHandler->TypeMessageHandler(template,handle by msg+type)
*/
#include <iostream>

typedef int TmsgId;

enum MSG_TYPE
{
    NO_MSG=0,
    INIT_REQ,
    AUTHENTICATION_REQ,
    ACT_MSG,
    VAL_MSG
};

namespace msg {

/* msg handler base class */
class Handler
{
public:
    virtual ~Handler() = default;
    virtual void handle(const int pEvent) = 0;
};

/* msg handler sub class */
class MessageHandler : public Handler
{
public:
    virtual ~MessageHandler()=default;
    virtual TmsgId getMessageId() const=0;
};

/* msg handler sub class / template class, handle msg by msgid and msgtype */
template<int MsgId, typename MsgType>
class TypedMessageHandler : public MessageHandler
{
public:
    //TypedMessageHandler() {},if need to adapted many msgtype,then handle input should redefine (as class), then static_cast to subclass
    void handle(const int pEvent) override
    {
        if (MsgId == pEvent)
        {
            const auto& msg=static_cast<const MsgType&>(pEvent);
            handleTyped(msg);
        }
        else {
            std::cout<<"cannot find msg"<<std::endl;
        }
    }
    TmsgId getMessageId() const override
    {
        return MsgId;
    }

    virtual void handleTyped(const MsgType msg)=0;
    virtual ~TypedMessageHandler()=default;
};
}
