# subscribe database changes demo

```
runtimeView subscribe shareDatabase changes, regist callback for handling notify message
when changes, notify message canbe wrapped by dispatcher(addReceiver,dispatch) method
```

## call and dispatch message
 * main.cpp
> 1. Instantiate the runtimeView, and notify message dispatcher
> 2. dispatch a message \'Notify_MSG\'

 * RuntimeChangesHandler.cpp/.h
> 1. subscribe `queryId/subscribeId contion, lambda callback (functionPoint)`
> 2. create observer vector to handle the call back
> 3. callbacks `traverse changes and handle it by observer`

 * PortObserver.cpp/.h
 a observer or a handler instance, inherit from `RuntimeObserver`
 * StateObserver.cpp/.h
 a observer or a handler instance, inherit from `RuntimeObserver`
 
 * observer.h
 virtual basic class `RuntimeObserver`
 
 * subscribe.h
> 1. ChangeData struct
> 2. callback function point

> 3. virtual basic class `SharedSubscribeApi`
>>  4. notifyHandler `ShareDbNotificationHandler`
       inherit from `TypedMessageHandler` template, for `handleTypeMsg` method for message handle
	   separated by message type and message struct
       define the message handler
>>  5. notifyHandler `SharedDbNotificationHandlerWrapper` wrapper
       inherit `ShareDbNotificationHandler`, for `handleTypeMsg` method for message handle
       handleTypeMsg call virtual basic method

> 6. notify callback `NotifyCallback`
     handle method

>>  7. shareDb subscribe instance `SharedSubscribeApiImp`
>>>         * inherit from virtual basic class `SharedSubscribeApi` for `subscribe` and `handleTypeMsg`
>>>         * `subscriptions` map for saving the pair of queryId/subscribeId and notifyHandler
>>>         * `subscribe` database with queryId/subscribeId
>>>         * `handleTypeMsg` find the notifyHandler by queryId/subscribeId
 
 
