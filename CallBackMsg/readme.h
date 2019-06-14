#ifndef README_H
#define README_H

/*
 *
class DispatcherImpl : public Dispatcher
{ addReceiver, dispatch }

std::shared_ptr<sharedDbApi::SharedDbClientWrapper> sharedDbClient = sharedDbApi::SharedDbClientWrapperFactoryImpl().create(..)
                                                                    { return return std::make_unique<SharedDbClientWrapperImpl>() }

class StateManagementEntity
    std::unique_ptr<msg::Dispatcher> dispatcher
    dispatcher->addReceiver(std::make_unique<sharedDbApi::SharedDbNotificationHandlerWrapper>(std::shared_ptr<sharedDbApi::SharedDbClientWrapper>))
    std::unique_ptr<runtimeView::RuntimeMosStateChangesHandler> runtimeMoStateChangesHandler->subscribe();
    handleApplicationMsg{dispatcher->dispatch->handle }


class RuntimeMosStateChangesHandler
    std::shared_ptr<sharedDbApi::SharedDbClientWrapper> dbapi->subscribeWithFetch(callback)
    callback-> std::vector<std::unique_ptr<RuntimeMoStateChangeObserver>> -> onStateChanges(changes)

class HubmodRBlockUnblockObserver : public RuntimeMoStateChangeObserver
      onStateChanges


class SharedDbNotificationHandler : public msg::TypedSingleMessageHandler<BTSOM_SHARED_DB_NOTIFICATION_IND_MSG, SharedDbNotification>
                                                       handle { handleTyped }

class SharedDbNotificationHandlerWrapper : public SharedDbNotificationHandler
     handleTyped() {std::shared_ptr<SharedDbClientWrapper> -> handleTyped }


class SharedDbClientWrapper : public SharedDbApi, public SharedDbNotificationHandler


class SharedDbClientWrapperImpl : public SharedDbClientWrapper
    subscribeWithFetch {subscriptions.emplace(*(response.id), std::move(callback));}
    handleTyped {subscriptions.at(subId).handle(getAndRemoveChangeIndFromMap(subId));}
 *
*/



#endif // README_H
