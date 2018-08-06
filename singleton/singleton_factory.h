#ifndef SINGLETON_DEMO_H
#define SINGLETON_DEMO_H

#include <memory>
#include <map>
#include <iostream>

//一种产品对应一个handle
class msgHandler
{
public:
    msgHandler() {}
    int handler(){ std::cout<<"handler...\n"; return 1;}
};

//抽象产品，提供处理产品接口
class Dispatcher
{
public:
    virtual ~Dispatcher() = default;
    virtual int dispatch() = 0;
};
//具体产品，提供处理或生产具体东西的接口
class ConCreteDispatcher : public Dispatcher
{
public:
    ConCreteDispatcher():handle(std::make_unique<msgHandler>()){}
    virtual ~ConCreteDispatcher() = default;
    int dispatch() override
    {
        return handle->handler();
    }
private:
    std::unique_ptr<msgHandler> handle;

};
//工厂，提供创建具体产品的接口
class DispatchFactory
{
public:
    ~DispatchFactory() = default;
    std::unique_ptr<Dispatcher> createDispatcher()
    {
        return std::make_unique<ConCreteDispatcher>();
    }
};


//单例模式，getInstance，处理消息功能
class Singleton_msgDisp
{
public:
    ~Singleton_msgDisp()
    {
        removeAllMsg();
        Instance = nullptr;
    }
    static Singleton_msgDisp* getInstance();
    void insertMsg(int id, std::unique_ptr<Dispatcher>&&);
    void removeAllMsg();
    Dispatcher* getMsgDispatcher(int id);
    std::map<int, std::unique_ptr<Dispatcher>> msgDispatcher;
private:
    Singleton_msgDisp()
    {
        msgDispatcher.clear();
    }
    static Singleton_msgDisp *Instance;
};

#endif // SINGLETON_DEMO_H
