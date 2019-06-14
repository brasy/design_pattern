#include "observer.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    std::shared_ptr<Subscriber> subscriber = std::make_shared<SubscriberImp>();
    MsgContainer msgcontainer;
    std::shared_ptr<Publisher> publisher = std::make_shared<PublisherImp>();

    char *msgfield = NULL;

    subscriber->subscribe(&msgcontainer, 2);

    std::shared_ptr<Subscriber> subscriber2 = std::make_shared<SubscriberImp2>();
    subscriber2->subscribe(&msgcontainer, 2);

    std::cout << "-----------------------------------------------" << std::endl;
    msgfield = "publisher: the publisher send this msg";

    std::shared_ptr<Msg> msg = std::make_shared<MsgImp>(2, msgfield);
    publisher->sendMsg(msgcontainer, msg);

    subscriber2->unsubscribe(&msgcontainer,2);

    std::cout << "-----------------------------------------------" << std::endl;
    msgfield = "publisher: the publisher send this msg2";
    msg = std::make_shared<MsgImp>(2, msgfield);
    publisher->sendMsg(msgcontainer, msg);

    std::cout << "-----------------------------------------------" << std::endl;
    subscriber2->subscribe(&msgcontainer, 3);
    msgfield = "publisher: msg 3";
    msg = std::make_shared<MsgImp>(3, msgfield);
    publisher->sendMsg(msgcontainer, msg);

    return 0;
}
