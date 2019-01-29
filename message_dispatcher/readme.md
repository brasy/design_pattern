## Dispatcher mode demo
### 1. createDispatcher
#### class inherit

> virtual basic class: Dispatcher  
>>     sub implement class:  DispatcherImpl  
>>>         add message handler  
>>>>             std::map<TmsgId, std::shared_ptr<Handler>> handlers  
>>>         dispatch message  


### 2. message handler

>virtual basic class: Handler  
>>    sub implement class: MessageHandler  
>>>        template message sub class: TypedMessageHandler //adapted many msgtype  

### 3. message 

inherit from TypedMessageHandler  
>    CcInitHandler  
>    AuthenticationHandler  
>    ...  


### 4. main
```
add message handler  
find message and dispatch message  
```
