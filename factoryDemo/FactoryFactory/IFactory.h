#ifndef IFACTORY_H
#define IFACTORY_H

#include <memory>
#include "boost/noncopyable.hpp"

namespace demo {

//某产品，可以获取产品版本信息
class ITargetDB
{
public:
    virtual ~ITargetDB() = default;
    virtual std::string getVersion() const = 0;
};

//工厂类，可以创建某产品
class IFactory : private boost::noncopyable
{
public:
    using ITargetDbPtr = std::shared_ptr<ITargetDB>;

    virtual ~IFactory() = default;
    virtual ITargetDbPtr createTargetDB() = 0;
};
}

#endif // IFACTORY_H
