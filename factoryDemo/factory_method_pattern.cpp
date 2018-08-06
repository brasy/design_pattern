//Factory Method Pattern
/*
 * 定义一个用于创建对象的接口，让子类决定实例化哪一个类, 使一个类的实例化延迟到其子类
 * 有一个工厂和一个产品，具体的工厂生产具体的产品
 *
 * 适用性
 * • 当一个类不知道它所必须创建的对象的类
 * • 当一个类希望由它的子类来指定它所创建的对象
 * • 当类将创建对象的职责委托给多个帮助子类中的某一个，并且你希望将哪一个帮助子类是代理者这一信息局部化的时候
 * 参与者：
 * • Product(抽象产品)
 * — 定义工厂方法所创建的对象的接口。
 * • Concrete Product(具体产品)
 * — 实现Product接口。
 *
 * • Factory(抽象工厂类)
 * — 声明工厂方法,该方法返回一个Product类型的对象。 Factory也可以定义一个工厂方法的缺省实现,它返回一个缺省的 ConcreteProduct对象。
 * — 可以调用工厂方法以创建一个 Product对象。
 * • ConcreteFactory(具体工厂类)
 * — 重定义工厂方法以返回一个 ConcreteProduct实例。
 */

#include <iostream>
#include <memory>

class Product
{
public:
    virtual void run() = 0;
};
class ConcreteProduct : public Product
{
public:
    virtual void run() override { std::cout << "Concrete product.\n"; }
};
class Factory
{
public:
    using productPtr = std::shared_ptr<Product>;
    virtual productPtr createProduct () =0;
};
class ContreteFactory : public Factory
{
public:
    virtual productPtr createProduct() override {return std::make_shared<ConcreteProduct>(); }
};

int factory_method()
{
    std::shared_ptr<Factory> creator(std::make_shared<ContreteFactory>());
    std::shared_ptr<Product> product(creator->createProduct());

    product->run(); //ConcreteProduct
}

/* 优点：
 * 1.良好的封装性，代码结构清晰。
 * 一个对象创建是有条件约束的，如一个调用者需要一个具体的产品对象，只要知道这个产品的类名（或约束字符串）就可以了，不用知道创建对象的艰辛过程，降低模块间的耦合。
 * 2.典型的解耦框架,符合迪米特法则
 * 符合迪米特法则，高层模块只需要知道产品的抽象类，其他的实现类都不用关心;
 * 符合依赖倒置原则，只依赖产品类的抽象；
 * 符合里氏替换原则，使用产品的子类替换产品父类/基类
 * 总结：使用父类的指针，指向子类的对象，调用子类的方法
 */
