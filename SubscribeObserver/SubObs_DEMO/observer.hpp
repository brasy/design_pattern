#pragma once
#include <map>
#include <mutex>
#include <memory>

class Msg
{
public:
    virtual int getMsgId() = 0;
    virtual void* getMsg() = 0;
};

class MsgImp :public Msg
{
public:
    MsgImp(int msgID, void *msgfield);
    virtual ~MsgImp() = default;

    virtual int getMsgId() override;
    virtual void* getMsg() override;

private:
    int m_msgID;
    void *m_msgfield; //msg type can redefine
};

class MsgContainer;

class Subscriber
{
public:
    virtual ~Subscriber() = default;
    virtual void subscribe(MsgContainer* observer, int msgId);
    virtual void unsubscribe(MsgContainer* observer, int msgId);
    virtual void handleMsg(std::shared_ptr<Msg> msg) = 0;
};

class MsgContainer
{
public:
    virtual void registerSubscriber(Subscriber* subscriber, int msgId);
    virtual void deregisterSubscriber(Subscriber* subscriber, int msgId);
    virtual void receiveMsg(std::shared_ptr<Msg> msg);

protected:
    virtual void notify(std::shared_ptr<Msg> msg);

private:
    std::multimap<int, Subscriber*> m_subscriber;
    std::mutex m_mutex;
};

class SubscriberImp : public Subscriber
{
public:
    SubscriberImp();
    virtual ~SubscriberImp();
    //invalid new-expression of abstract class type ‘××××‘, so must realize the function
    //or delete function define info about "=0" in parent class and use parent function
    //void subscribe(MsgContainer* observer, int msgId){}
    //void unsubscribe(MsgContainer* observer, int msgId){}
    void handleMsg(std::shared_ptr<Msg> msg) override;
private:
    void *m_expext_field;
};

class SubscriberImp2 :public Subscriber
{
public:
    SubscriberImp2();
    virtual ~SubscriberImp2();
    void handleMsg(std::shared_ptr<Msg> msg) override;
private:
    void *m_expext_field;
};

class Publisher
{
public:
    virtual void sendMsg(MsgContainer&, std::shared_ptr<Msg> msg);
};

class PublisherImp :public Publisher
{
public:
    PublisherImp(){}
    virtual ~PublisherImp() = default;
};
