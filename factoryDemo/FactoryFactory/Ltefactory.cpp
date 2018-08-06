#include "LteFactory.h"
#include <iostream>

namespace demo{

BbuFactory::BbuFactory(std::unique_ptr<config::PortConfigFactory> portCfgFact, const config::EarlyConfig& eConfig)
    :BaseFactory(std::move(portCfgFact), eConfig)
{
    std::cout<<"this is bbu factory instance\n";
}

IFactory::ITargetDbPtr BbuFactory::createTargetDB()
{
    std::cout<<" this is target for BBU\n";
    return std::make_shared<TargetDB>();
}

}
