## Dispatcher mode demo
### 1. createDispatcher
#### class inherit
'''
virtual basic class: Dispatcher/n
    sub implement class:  DispatcherImpl/n
          add message handler/n
              std::map<TmsgId, std::shared_ptr<Handler>> handlers/n
          dispatch message/n

'''

### 2. message handler
'''
virtual basic class: Handler
    sub implement class: MessageHandler
        template message sub class: TypedMessageHandler //adapted many msgtype
'''

### 3. message 
'''
inherit from TypedMessageHandler
    CcInitHandler
    AuthenticationHandler
    ...
'''

### 4. main
'''
add message handler
find message and dispatch message
'''
