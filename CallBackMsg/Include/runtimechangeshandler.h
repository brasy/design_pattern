#pragma once
#include "observer.h"
#include <memory>
#include <vector>

namespace runtimeView {

class RuntimeChangesHandler
{
public:
    RuntimeChangesHandler(std::shared_ptr<subscribeApi::SharedSubscribeApi> api);
    void subscribe() const;
private:
    void handlePortChanges(const subscribeApi::ChangeData& changes) const;
    void handleStateChanges(const subscribeApi::ChangeData& changes) const;

    std::vector<std::unique_ptr<RuntimeObserver>> portObservers;
    std::vector<std::unique_ptr<RuntimeObserver>> stateObservers;
    std::shared_ptr<subscribeApi::SharedSubscribeApi> dbApi;
};
}
