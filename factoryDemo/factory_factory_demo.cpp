#include <iostream>

/*工厂方法模式和抽象工厂模式的区别
简单工厂模式：
只有一个工厂类一个生产方法，根据参数不同生产不同的产品。
工厂方法模式：
每一个工厂类只负责一个产品生产，不生成其它产品。好比一条生产线只生产一个产品线。
抽象工厂模式：
每一个工厂类提供多个方法，可以生产不同的产品。好比多条生产线可以生产多家产品。
*/

/*
 * * 参与者
 * IFactoryFactory (抽象工厂的工厂)
 * FactoryFactory (具体工厂的工厂)
 * - 创建工厂
 *
 * IFactory (抽象工厂)
 * 为工厂对象声明一个接口。
 * BaseFactory (实现工厂基接口)
 * - 声明一个创建抽象工厂对象的接口
 * FzFactory (具体工厂)
 * BbuFactory (具体工厂)
 * PortConfigFactory (具体工厂，服务于其他具体工厂)
 *
 * ITargetDB (抽象产品)
 * TargetDB (具体产品)
 * 每家具体工厂都生产的产品，定义一个将被相应的具体工厂创建的产品对象。
 *
 * PortConfig (抽象产品，服务于其他具体工厂具体产品)
 * BbuPortConfig (具体产品)
 * FzPortConfig (具体产品)
 * PortConfiguration (实现产品接口)
 * PortConfigurationMgr (实现产品接口的接口，管理实现产品接口)
 *
 *
 * * demo（使用场景）
 * — 使用FactoryFactory类和PortConfigFactory声明的接口。
 * - 使用PortConfigFactory根据EarlyConfig创建具体产品PortConfig，PortConfig移动给PortConfiguration，再移动给PortConfigurationMgr，在执行具体事情
 * - 使用FactoryFactory创建工厂的工厂BaseFactory，BaseFactory再根据资源（使用PortConfigFactory生成具体产品PortConfiguration和EarlyConfig）生成具体工厂，
 *   具体的工厂再创建产品
 */
using namespace std;

#include "FactoryFactory/ConcreteFactoryFactory.h"
#include "FactoryFactory/ConcreteFactory.h"
#include "FactoryFactory/ConfigFactory.h"

int main_ff()
{
    //工厂的工厂，根据earlyconfig和必备工厂PortConfigFactory，生成具体的产品工厂，产品工厂再生成targetdb产品并获取产品版本
    demo::FactoryFactory factoryFactory;
    auto factory = factoryFactory.createFactory();
    auto db = factory->createTargetDB();
    cout<< db->getVersion() << endl;

    //portconfig工厂，根据系统配置earlyconfig，portconfig移动给portconfig实例，再移动给portconfig管理实例，运行管理信息
    config::PortConfigFactory portFct;
    demo::PortConfigurationMgr cfgMgr{std::make_unique<demo::PortConfiguration>(
                    portFct.createPortConfig(config::EarlyConfig()))};
    cout<<cfgMgr.start()<<endl;

    //根据earlyconfig，portconfig工厂, 创建具体的portconfig产品，并获取产品port信息
    config::EarlyConfig earlyconfig;
    config::PortConfigFactory portFactory;
    auto portCfg = portFactory.createPortConfig(earlyconfig);
    cout<<portCfg->getPort()<<endl;


    //修改earlyconfig，portconfig工厂, 创建具体的portconfig产品，并获取产品port信息
    earlyconfig.setHwType(config::HwType::LTE);
    portCfg = portFactory.createPortConfig(earlyconfig); //根据入参创建不同portcofig
    cout<<portCfg->getPort()<<endl;

    return 0;
}
