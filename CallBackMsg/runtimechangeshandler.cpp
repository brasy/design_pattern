#include <iostream>
#include "Include/runtimechangeshandler.h"
#include "Include/observer_port.h"
#include "Include/observer_state.h"

namespace runtimeView
{

RuntimeChangesHandler::RuntimeChangesHandler(
        std::shared_ptr<subscribeApi::SharedSubscribeApi> api)
        : dbApi{std::move(api)}
{
    portObservers.push_back(std::make_unique<PortObserver>());
    stateObservers.push_back(std::make_unique<StateObserver>());
}

void RuntimeChangesHandler::subscribe() const
{
    std::cout << "changes subscribing \n";
    subscribeApi::UpdatedValuesCallback portCallback = [this](const subscribeApi::ChangeData& changes)
    {
        try{
            this->handlePortChanges(changes);
        }
        catch(std::exception& e){
            std::cout << "fail to handle port update: " << e.what();
        }
    };
    dbApi->subscribe(1, portCallback);
    subscribeApi::UpdatedValuesCallback stateCallback = [this](const subscribeApi::ChangeData& changes)
    {
        try{
            this->handleStateChanges(changes);
        }
        catch(std::exception& e){
            std::cout << "fail to handle port update: " << e.what();
        }
    };

    dbApi->subscribe(2, stateCallback);
}

void RuntimeChangesHandler::handlePortChanges(const subscribeApi::ChangeData& changes) const
{
    std::cout << "port changes in database have been detected\n";
    for (const auto& change : changes.values)
        std::cout << change;
    std::cout << "\n";
    for (const auto& handler : portObservers)
    {
        handler->onChanges(changes);
    }
}
void RuntimeChangesHandler::handleStateChanges(const subscribeApi::ChangeData& changes) const
{
    std::cout << "state changes in database have been detected\n";
    for (const auto& change : changes.values)
        std::cout << change;
    std::cout << "\n";
    for (const auto& handler : stateObservers)
    {
        handler->onChanges(changes);
    }
}

}
