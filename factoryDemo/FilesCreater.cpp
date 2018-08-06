#include "FilesCreater.h"
#include <fstream>
#include <iostream>

FilesCreater::FilesCreater(std::shared_ptr<config::EarlyConfig> earlyConfig)
    :eConfig(std::move(earlyConfig))
{
}

int FilesCreater::createFiles()
{
    auto hwtype = eConfig->getHwType();
    if (hwtype == config::HwType::WCDMA)
    {
        return createFilesForW();
    }
    else if (hwtype == config::HwType::LTE)
    {
        return createFilesForLTE();
    }

    return -1;
}
int FilesCreater::createFilesForLTE()
{
    std::string stringBuff = "this is for my Lte";
    std::string searchKey = "my";

    replaceStr(stringBuff,searchKey,"0:0");

    return writeToFiles(PATH_LTE, stringBuff);
}

int FilesCreater::createFilesForW()
{
    std::string stringBuff = "this is for my wcdma";
    std::string searchKey = "my";

    replaceStr(stringBuff,searchKey,"1:1");

    return writeToFiles(PATH_WCDMA, stringBuff);
}

void FilesCreater::replaceStr(std::string& source, const std::string& key, const std::string& replace)
{
    size_t size{};
    for(;(size = source.find(key)) != std::string::npos;)
        source.replace(size, key.length(), replace);
}

int FilesCreater::writeToFiles(const std::string& filePath, const std::string& stringBuff)
{
    std::ofstream outFile;

    outFile.open(filePath.c_str());
    //std::cout<<system("dir")<<std::endl;
    //std::cout<<filePath.c_str();
    if(outFile.is_open())
    {
        std::cout<<"open and write ok\n";
        outFile<<stringBuff;
        outFile.close();
        return 0;
    }

    std::cout<<"open to write fail\n";
    return -1;
}
