#include "Include/subscriber.h"
#include <iostream>

namespace subscribeApi {

int SharedSubscribeApiImp::subscribe(int queryId, UpdatedValuesCallback callback)
{
    std::cout << "SharedSubscribeApiImp: subscribe: " << queryId << std::endl;
    return sub(queryId, NotifyCallback(callback));
}

int SharedSubscribeApiImp::sub(int queryId, NotifyCallback callback)
{
    subscriptions.emplace(queryId, std::move(callback));
    return queryId;
}

void SharedSubscribeApiImp::handleTypeMsg(const int id)
{
    std::cout << "SharedSubscribeApiImp: handleType: " << id << std::endl;
    try
    {
        subscriptions.at(id).handle(getChanges(id));
    }
    catch (const std::out_of_range&)
    {
        std::cout << "SharedSubscribeApiImp: Callback function for subscriptionId:" << id << " not found\n";
    }
    catch (std::exception& e)
    {
        std::cout << "SharedSubscribeApiImp: fail to handle  " << e.what() << std::endl;
    }
}
ChangeData SharedSubscribeApiImp::getChanges(int id)
{
    return {std::to_string(id)};
}

NotifyCallback::NotifyCallback(UpdatedValuesCallback callback) : changesCallback{std::move(callback)}
{}

void NotifyCallback::handle(const ChangeData &changes) const
{
    std::cout << "NotifyCallback: notify handle: " << changes.values << std::endl;
    if (changesCallback)
        (*changesCallback)(changes);
}

}
