//Abstruct Factory Pattern
/*
 * 提供一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类。
 * 适用性
 * • 一个系统要独立于它的产品的创建、组合和表示
 * • 一个系统要由多个产品系列中的一个来配置
 * • 当要强调一系列相关的产品对象的设计以便进行联合使用
 * • 当你提供一个产品类库，而只想显示它们的接口而不是实现
 *
 * 参与者
 * • AbstractFactory (抽象工厂)
 * — 声明一个创建抽象产品对象的操作接口
 * • ConcreteFactory (具体工厂)
 * — 实现创建具体产品对象的操作。
 * • AbstractProduct (抽象产品)
 * — 为一类产品对象声明一个接口。
 * • ConcreteProduct (具体产品)
 * — 定义一个将被相应的具体工厂创建的产品对象。
 * — 实现AbstractProduct接口。
 * • Client（使用场景）
 * — 仅使用由AbstractFactory和AbstractProduct类声明的接口。
 */

#include <iostream>
#include <memory>

class RoadsterAbstractVehile {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
};

class DasAutoRoadsterVehile: public RoadsterAbstractVehile {
public:
    virtual void start() {
        std::cout << "DasAuto RoadsterVehile starts." << std::endl;
    }

    virtual void stop() {
        std::cout << "DasAuto RoadsterVehile stops." << std::endl;
    }
};

class FordRoadsterVehile: public RoadsterAbstractVehile {
public:
    virtual void start() {
        std::cout << "Ford RoadsterVehile starts." << std::endl;
    }

    virtual void stop() {
        std::cout << "Ford RoadsterVehile stops." << std::endl;
    }
};

class BizAbstractVehile {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
};

class DasAutoBizVehile: public BizAbstractVehile {
public:
    virtual void start() {
        std::cout << "DasAuto BizVehile starts." << std::endl;
    }

    virtual void stop() {
        std::cout << "DasAuto BizVehile stops." << std::endl;
    }

};

class FordBizVehile: public BizAbstractVehile {
public:
    virtual void start() {
        std::cout << "Ford BizVehile starts." << std::endl;
    }

    virtual void stop() {
        std::cout << "Ford BizVehile stops." << std::endl;
    }
};

class VehileAbstractFactory {
public:
    virtual RoadsterAbstractVehile* CreateRoadsterVehile() = 0;
    virtual BizAbstractVehile* CreateBizVehile() = 0;
};

class DasAutoFactory: public VehileAbstractFactory {
    virtual RoadsterAbstractVehile* CreateRoadsterVehile() {
        return new DasAutoRoadsterVehile();
    }
    virtual BizAbstractVehile* CreateBizVehile() {
        return new DasAutoBizVehile();
    }
};

class FordFactory: public VehileAbstractFactory {
    virtual RoadsterAbstractVehile* CreateRoadsterVehile() {
        return new FordRoadsterVehile();
    }
    virtual BizAbstractVehile* CreateBizVehile() {
        return new FordBizVehile();
    }
};


int main_abstractFac()
{
    std::shared_ptr<VehileAbstractFactory> dasauto_factory(std::make_shared<DasAutoFactory>());
    std::shared_ptr<VehileAbstractFactory> ford_factory(std::make_shared<FordFactory>());

    std::shared_ptr<RoadsterAbstractVehile>
        dasauto_roadster(dasauto_factory->CreateRoadsterVehile());
    (*dasauto_roadster).start();
    dasauto_roadster->stop();

    std::shared_ptr<BizAbstractVehile>
        dasauto_biz(dasauto_factory->CreateBizVehile());
    (*dasauto_biz).start();
    dasauto_biz->stop();

    std::shared_ptr<RoadsterAbstractVehile>
        ford_roadster(ford_factory->CreateRoadsterVehile());
    (*ford_roadster).start();
    ford_roadster->stop();

    std::shared_ptr<BizAbstractVehile>
        ford_biz(ford_factory->CreateBizVehile());
    (*ford_biz).start();
    ford_biz->stop();

    return 0;
}
