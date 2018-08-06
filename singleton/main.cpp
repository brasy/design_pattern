#include <iostream>
#include "singleton_factory.h"
#include <set>

using namespace std;

std::set<int> ids;
Singleton_msgDisp* msgMgr = nullptr;//Singleton_demo::getInstance();

bool processMsg(std::set<int>& inputIds)
{
    DispatchFactory factory;
    for(auto id : inputIds)
    {
        if(ids.find(id) == ids.end())
        {
            ids.insert(id);
            auto dispatcher = factory.createDispatcher();
            msgMgr->insertMsg(id, std::move(dispatcher));
            cout<<"insert new msg\n";
            for(auto& dis : msgMgr->msgDispatcher)
                cout<<dis.first<<endl;
        }
        else
        {
            auto dispatcher = msgMgr->getMsgDispatcher(id);
            auto ret = dispatcher->dispatch();
            if (ret)
                cout<<"success.\n";
        }
    }
    return 1;
}

int main()
{
    int i=2;
    std::set<int> inputIds{1,3,5};
    msgMgr = Singleton_msgDisp::getInstance();
    while (i--)
    {
        if (!processMsg(inputIds))
        {
            cout<<"process fail\n";
            return -1;
        }
    }

    return 0;
}
