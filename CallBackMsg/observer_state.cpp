#include "Include/observer_state.h"

namespace runtimeView
{
StateObserver::StateObserver()
{}
void StateObserver::onChanges(const subscribeApi::ChangeData& changes)
{
    std::cout << "State Changes " << std::endl;
}
}
