#ifndef CONCRETEFACTORY_H
#define CONCRETEFACTORY_H

#include "IFactory.h"
#include "ConfigFactory.h"

namespace demo {

/* PortConfiguration ：portconfig实现类，基于虚基类，可生成实例
 * portconfigmgr ：对PortConfiguration的封装，针对具体的port实例做具体的事情，管理port配置
 */
class PortConfiguration
{
public:
    PortConfiguration(std::unique_ptr<const config::PortConfig> portcfg) : portConfig{std::move(portcfg)}{}
private:
    std::unique_ptr<const config::PortConfig> portConfig;
};

class PortConfigurationMgr
{
public:
    PortConfigurationMgr(std::unique_ptr<PortConfiguration> portcfg)
        :portCfg{std::move(portcfg)}{}

    std::string start(){return "port config management.";}

private:
    std::unique_ptr<const PortConfiguration> portCfg;
};


//产品类，实现获取产品版本
class TargetDB : public ITargetDB
{
public:
    std::string getVersion() const override {return "db version";}
};

/* 工厂类，基类，
 * 不同portconfig，对应不同产品
 * 基于portconfig的工厂类（PortConfigFactory），和实例化实现类（PortConfiguration）
 */
class BaseFactory : public IFactory
{
public:
    BaseFactory(std::unique_ptr<config::PortConfigFactory> portConfigFac, const config::EarlyConfig& eConfig)
        :portConfiguration{std::make_shared<PortConfiguration>(portConfigFac->createPortConfig(eConfig))} {}

    std::shared_ptr<PortConfiguration> portConfiguration;
};
}
#endif // CONCRETEFACTORY_H
