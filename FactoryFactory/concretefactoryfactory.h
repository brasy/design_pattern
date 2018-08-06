#ifndef CONCRETEFACTORYFACTORY_H
#define CONCRETEFACTORYFACTORY_H

#include "IFactoryFactory.h"
#include "ConfigFactory.h"
#include "LteFactory.h"
#include "WcdmaFactory.h"

namespace demo {

//产品工厂的工厂，用于生成不同的产品工厂实例，根据不同earlyconfig需求生成不同产品工厂
class FactoryFactory : public IFactoryFactory
{
public:
    IfactoryPtr createFactory() override {
        auto earconfig = getEarlyConfig();
        if (earconfig.getHwType() == config::HwType::LTE)
        {
            return createBbuFactory();
        }
        return createFzFactory();
    }
private:
    IfactoryPtr createBbuFactory() const {
        return std::make_shared<BbuFactory>(createPortCfgFactory(), getEarlyConfig());
    }

    IfactoryPtr createFzFactory() const {
        return std::make_shared<FzFactory>(createPortCfgFactory(), getEarlyConfig());
    }

    config::EarlyConfig getEarlyConfig() const {return config::EarlyConfig();}
    std::unique_ptr<config::PortConfigFactory> createPortCfgFactory() const {return std::make_unique<config::PortConfigFactory>();}
};
}

#endif // CONCRETEFACTORYFACTORY_H
