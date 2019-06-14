#pragma once

#include "observer.h"
#include <iostream>

/* error: undefined reference to `vtable for 类名'
 * reason: 这个报错是很经典的Qt报错。一般是定义了成员函数，没有去实现。
 *         也就是你的成员函数在头文件里声明了，没有在cpp里实现.
 * solution: 在cpp中实现onChanges(.)
*/
namespace runtimeView
{
class StateObserver : public RuntimeObserver
{
public:
    StateObserver();
    virtual ~StateObserver() = default;
    void onChanges(const subscribeApi::ChangeData&) override;
};
}
