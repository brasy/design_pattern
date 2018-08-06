#ifndef FILESCREATER_H
#define FILESCREATER_H

#include <memory>
#include "FactoryFactory/ConfigFactory.h"

class FilesCreater
{
public:
    FilesCreater(std::shared_ptr<config::EarlyConfig>);
    int createFiles();
    virtual ~FilesCreater() = default;
private:
    int createFilesForLTE();
    int createFilesForW();
    void replaceStr(std::string&, const std::string&, const std::string&);
    int writeToFiles(const std::string&, const std::string&);

    std::string PATH_LTE = "Lte.xml";
    std::string PATH_WCDMA = "Wcdma.xml";
    std::shared_ptr<config::EarlyConfig> eConfig;
};

#endif // FILESCREATER_H
