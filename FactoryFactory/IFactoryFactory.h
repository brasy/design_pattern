#ifndef IFACTORY_FACTORY_H
#define IFACTORY_FACTORY_H

#include <memory>
#include "boost/noncopyable.hpp"
#include "IFactory.h"

namespace demo {

//工厂的工厂类，可以创建一个工厂Factory
class IFactoryFactory : private boost::noncopyable
{
public:
    using IfactoryPtr = std::shared_ptr<IFactory>;

    virtual ~IFactoryFactory() = default;
    virtual IfactoryPtr createFactory() = 0;
};

}

#endif // IFACTORY_FACTORY_H
