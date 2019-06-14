#include "Include/observer_port.h"

namespace runtimeView
{
PortObserver::PortObserver()
{}
void PortObserver::onChanges(const subscribeApi::ChangeData& changes)
{
    std::cout << "port changes " << std::endl;
}
}
