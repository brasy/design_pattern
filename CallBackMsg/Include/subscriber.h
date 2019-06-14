#pragma once

#include <string>
#include <functional>
#include <map>
#include "boost/optional/optional.hpp"
#include <memory>
#include "msg/msghandler.h"

namespace subscribeApi {
//changes
struct ChangeData
{
    std::string values;
    inline bool operator==(const ChangeData& others) const
    {
        return values == others.values;
    }
};

//callback function point
using UpdatedValuesCallback = std::function<void(const ChangeData&)>;

//sharedb subscribe/handle
class SharedSubscribeApi
{
public:
    virtual int subscribe(int queryId, UpdatedValuesCallback) = 0;
    virtual void handleTypeMsg(const int queryId) = 0;

};

//notify
class ShareDbNotificationHandler : public msg::TypedMessageHandler<Notify_MSG, int>
{
public:
    void handleTyped(const int msg) override
    {
        handleTypeMsg(msg);
    }
    virtual void handleTypeMsg(int msg) = 0;
    virtual ~ShareDbNotificationHandler()=default;
};

//notify
class SharedDbNotificationHandlerWrapper : public ShareDbNotificationHandler
{
public:
    SharedDbNotificationHandlerWrapper(std::shared_ptr<SharedSubscribeApi> apiInit): sharedDbClientWrapper{std::move(apiInit)} {}
    void handleTypeMsg(const int msg) override
    {
        sharedDbClientWrapper->handleTypeMsg(msg);
    }
private:
     std::shared_ptr<SharedSubscribeApi> sharedDbClientWrapper;
};

//callback class
class NotifyCallback
{
public:
    NotifyCallback(UpdatedValuesCallback callback);
    void handle(const ChangeData& changes) const;

private:
    boost::optional<UpdatedValuesCallback> changesCallback;
};

//detail sharedb processing
class SharedSubscribeApiImp : public SharedSubscribeApi//, public ShareDbNotificationHandler
{
public:
    SharedSubscribeApiImp() {}
    int subscribe(int queryId, UpdatedValuesCallback) override;
    int sub(int queryId, NotifyCallback);

    void handleTypeMsg(const int id) override;
    virtual ~SharedSubscribeApiImp() = default;

private:
ChangeData getChanges(int id);
std::map<int, NotifyCallback> subscriptions;
};

}

