#include "singleton_factory.h"
#include <iostream>

Singleton_msgDisp* Singleton_msgDisp::Instance = nullptr;

Singleton_msgDisp* Singleton_msgDisp::getInstance()
{
    if (Instance == nullptr)
        Instance = new Singleton_msgDisp;
    return Instance;
}

void Singleton_msgDisp::insertMsg(int id, std::unique_ptr<Dispatcher>&& dispatcher)
{
    if (dispatcher)
    {
        auto ret = msgDispatcher.insert(std::pair<int,std::unique_ptr<Dispatcher>>(id,std::move(dispatcher)));
        if(!ret.second)
            std::cout<<"dispatch already exist.\n";
    }
    else
        std::cout<<"invalid dispatch.\n";
}

void Singleton_msgDisp::removeAllMsg()
{
    if (not msgDispatcher.empty())
    {
        for(auto& it : msgDispatcher)
        {
            it.second = nullptr;
        }
        msgDispatcher.clear();
    }
}

Dispatcher* Singleton_msgDisp::getMsgDispatcher(int id)
{
    auto dispatcher = msgDispatcher.find(id);
    if (dispatcher != msgDispatcher.end())
        return (*dispatcher).second.get();
    else
        std::cout<<"unable to find dispatcher.\n";
    return nullptr;
}
