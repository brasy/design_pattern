#pragma once

#include "msghandler.h"

namespace provision {

enum class ProvisioningType
{
    Config,
    SoftwareUpgrade,
    SoftwareRollback,
    UserManagement
};

inline std::ostream& operator<<(std::ostream& out, ProvisioningType type)
{
    switch (type) {
    case ProvisioningType::Config:
        return out << "Config";
    case ProvisioningType::SoftwareUpgrade:
        return out << "SoftwareUpgrade";
    case ProvisioningType::SoftwareRollback:
        return out << "SoftwareRollback";
    case ProvisioningType::UserManagement:
        return out << "UserManagement";
    default:
        return out << "Invalid";
    }
}

template<int MsgId, typename MsgType>
class ProvisionBase : public msg::TypedMessageHandler<MsgId,MsgType>
{
public:
    using Base = ProvisionBase<MsgId, MsgType>;
    using HandlerType = msg::TypedMessageHandler<MsgId, MsgType>;

    virtual ~ProvisionBase<MsgId,MsgType>()=default;
    void handleTyped(const MsgType msg) override
    {
        std::cout << "ProvisionBase handle Type \n";
        try{

            handlers[provision::ProvisioningType::Config]->handle(msg);
        }catch(const std::exception& ex)
        {
            std::cout << "could not dispatch mes: " << ex.what() << std::endl;
        }
    }
    void addHandler(std::shared_ptr<HandlerType> handler, ProvisioningType type)
    {
        std::cout << "add handler: " << type << std::endl;
        handlers[type] = handler;
    }

private:
    std::map<ProvisioningType, std::shared_ptr<HandlerType>> handlers;
};

}

class ActDispatcher : public provision::ProvisionBase<ACT_MSG,int>
{
public:
    using Base::ProvisionBase;
};



class ValDispatcher : public provision::ProvisionBase<VAL_MSG,int>
{
public:
    using Base::ProvisionBase;
};
