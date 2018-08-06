#ifndef FZFACTORY_H
#define FZFACTORY_H

#include "ConcreteFactory.h"

namespace demo {

class FzFactory : public BaseFactory
{
public:
    FzFactory(std::unique_ptr<config::PortConfigFactory> portCfgFact, const config::EarlyConfig& eConfig);
    virtual ITargetDbPtr createTargetDB() override;
};
}
#endif // FZFACTORY_H
