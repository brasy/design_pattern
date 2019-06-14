#include "observer.hpp"
#include <iostream>
using namespace std;

MsgImp::MsgImp(int msgID, void *msgfield) : m_msgID(msgID), m_msgfield(std::move(msgfield))
{
    //cout << "msgImp: " << m_msgID << " - " << (char *) m_msgfield << endl;
}

int MsgImp::getMsgId()
{
    return m_msgID;
}
void* MsgImp::getMsg()
{
    return m_msgfield;
}

void Subscriber::subscribe(MsgContainer *pMsgContainer, int MsgID)
{
    pMsgContainer->registerSubscriber(this, MsgID);
}

void Subscriber::unsubscribe(MsgContainer *pMsgContainer, int MsgID)
{
    pMsgContainer->deregisterSubscriber(this, MsgID);
}

SubscriberImp::SubscriberImp()
{}
SubscriberImp::~SubscriberImp()
{
    delete m_expext_field;
}

void SubscriberImp::handleMsg(std::shared_ptr<Msg> msg)
{
    m_expext_field = msg->getMsg();

    cout << __func__ << ": this is the SubscriberImp1..." << endl;
    cout <<__func__ << ": the MsgID is " << msg->getMsgId() << endl;
    cout <<__func__ << ": " << (char *) msg->getMsg() << ", SubscriberImp1 handle the msg"<<endl;
}

SubscriberImp2::SubscriberImp2()
{}
SubscriberImp2::~SubscriberImp2()
{
    delete m_expext_field;
}

void SubscriberImp2::handleMsg(std::shared_ptr<Msg> msg)
{
    m_expext_field = msg->getMsg();
    cout << __func__ << ": this is the SubscriberImp2..." << endl;
    cout <<__func__ << ": the MsgID is " << msg->getMsgId() << endl;
    cout <<__func__ << ": " << (char *) msg->getMsg() << ", SubscriberImp2 handle the msg"<<endl;
}

void MsgContainer::registerSubscriber(Subscriber *pSubscriber, int msgID)
{
    lock_guard<mutex> guard(m_mutex);

    if (m_subscriber.empty())
    {
        m_subscriber.insert(make_pair(msgID, pSubscriber));
    }

    bool isExist = false;
    map<int, Subscriber*>::iterator it = m_subscriber.lower_bound(msgID);
    while (it != m_subscriber.upper_bound(msgID))
    {
        if (it->second == pSubscriber)
            isExist = true;
        it++;
    }
    if (!isExist)
    {
        m_subscriber.insert(make_pair(msgID, pSubscriber));
    }
}

void MsgContainer::deregisterSubscriber(Subscriber *pSubscriber, int MsgID)
{
    lock_guard<mutex> guard(m_mutex);

    if (m_subscriber.empty())
    {
        return;
    }

    multimap<int, Subscriber*>::iterator it = m_subscriber.lower_bound(MsgID);
    while (it != m_subscriber.upper_bound(MsgID))
    {
        if (it->second == pSubscriber)
        {
            m_subscriber.erase(it);
            break;
        }
        it++;
    }
}

void MsgContainer::notify(std::shared_ptr<Msg> msg)
{
    multimap<int, Subscriber*>::iterator it = m_subscriber.lower_bound(msg->getMsgId());
    for (; it != m_subscriber.upper_bound(msg->getMsgId()); it++)
    {
        it->second->handleMsg(msg);
    }
}

void MsgContainer::receiveMsg(std::shared_ptr<Msg> msg)
{
    lock_guard<mutex> guard(m_mutex);

    this->notify(msg);
}

void Publisher::sendMsg(MsgContainer& pMsgContainer, std::shared_ptr<Msg> msg)
{
    pMsgContainer.receiveMsg(msg);
}


