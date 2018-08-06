#include "WcdmaFactory.h"
#include <iostream>

namespace demo {

FzFactory::FzFactory(std::unique_ptr<config::PortConfigFactory> portCfgFact, const config::EarlyConfig& eConfig)
    :BaseFactory(std::move(portCfgFact), eConfig)
{
    std::cout<<"this is fz factory instance.\n";
}

IFactory::ITargetDbPtr FzFactory::createTargetDB()
{
    std::cout<<"create fz target db.\n";
    return std::make_shared<TargetDB>();
}
}
