#include <iostream>
#include "dispatcherimpl.h"
#include "ccinithandler.h"
#include "authenticationhandler.h"

using namespace std;

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

    return 0;
}
