#ifndef CONFIGFACTORY_H
#define CONFIGFACTORY_H

#include <memory>

namespace config {

//config1: hardware type, for port config
enum class HwType
{
    WCDMA,
    LTE
};

class EarlyConfig
{
public:
    explicit EarlyConfig(){hwType = defaultHwType;}
    HwType getHwType() const {return hwType;}
    void setHwType(const HwType inHwType){hwType = inHwType;}

private:
    static constexpr HwType defaultHwType{HwType::WCDMA};
    HwType hwType{defaultHwType};
};


//config2: port config, dependent on hw type
/* portconfig 虚基类，两个子类：产品，两个具体产品
 * portconfigfactory：工厂，创建产品实例
 */
class PortConfig
{
public:
    virtual ~PortConfig() = default;
    virtual int getPort() const = 0;
};
class BbuPortConfig : public PortConfig
{
public:
    int getPort() const override { return 21;}
};
class FzPortConfig : public PortConfig
{
public:
    int getPort() const override { return 22;}
};

//port config factory
class PortConfigFactory
{
public:
    std::unique_ptr<PortConfig> createPortConfig(const config::EarlyConfig& eConfig) const {
        const auto hwType = eConfig.getHwType();
        if (hwType == HwType::WCDMA)
        {
            return std::make_unique<BbuPortConfig>();
        }
        return std::make_unique<FzPortConfig>();
    }
};

}

#endif // CONFIGFACTORY_H
