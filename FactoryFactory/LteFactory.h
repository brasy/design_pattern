#ifndef BBUFACTORY_H
#define BBUFACTORY_H

#include "ConcreteFactory.h"

namespace demo {

class BbuFactory : public BaseFactory
{
public:
    BbuFactory(std::unique_ptr<config::PortConfigFactory> portCfgFact, const config::EarlyConfig& eConfig);
    virtual ITargetDbPtr createTargetDB() override;
};
}
#endif // BBUFACTORY_H
