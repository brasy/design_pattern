#include <iostream>

/*工厂方法模式和抽象工厂模式的区别
简单工厂模式：
只有一个工厂类一个生产方法，根据参数不同生产不同的产品。
工厂方法模式：
每一个工厂类只负责一个产品生产，不生成其它产品。好比一条生产线只生产一个产品线。
抽象工厂模式：
每一个工厂类提供多个方法，可以生产不同的产品。好比多条生产线可以生产多家产品。
*/

#include "FactoryFactory/ConfigFactory.h"
#include "FilesCreater.h"

using namespace std;

int main(int argc, char *argv[])
{
    auto econfig = std::make_shared<config::EarlyConfig>();
    econfig->setHwType(config::HwType::LTE);
    FilesCreater fileCreater(econfig);
    if(fileCreater.createFiles())
        cout<<"read and write fail\n";

    return 0;
}
