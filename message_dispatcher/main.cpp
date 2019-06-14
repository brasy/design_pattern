#include <iostream>
#include "dispatcherimpl.h"
#include "ccinithandler.h"
#include "authenticationhandler.h"

#include "provisionactdispatcher.h"
#include "cmactivationreqhandler.h"

using namespace std;

//just for same message with different type (0417)
std::unique_ptr<ActDispatcher> createProvisionDispatcher()
{
    auto proDispatcher = std::make_unique<ActDispatcher>();
    proDispatcher->addHandler(std::make_unique<CmActivationReqHandler>(), provision::ProvisioningType::Config);

    return proDispatcher;
}

std::unique_ptr<msg::DispatcherImpl> createDispatcher()
{
    auto dispatcher = std::make_unique<msg::DispatcherImpl>();
    dispatcher->addReceiver(std::make_unique<CcInitHandler>());
    dispatcher->addReceiver(std::make_unique<AuthenticationHandler>());

    //a set of handlers of different provisioning for a message
    dispatcher->addReceiver(createProvisionDispatcher());
    return dispatcher;
}

std::unique_ptr<provision::ActDispatcher> createProvisionDispatcher()
{
    auto proDispatcher = std::make_unique<provision::ActDispatcher>();
}

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    auto dispacher=createDispatcher();

    int msgid = 1;
    dispacher->dispatch(msgid);
    msgid=2;
    dispacher->dispatch(msgid);
    msgid=3;
    dispacher->dispatch(msgid);

    return 0;
}
