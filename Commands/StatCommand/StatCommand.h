#pragma once

#include "../../FilesInformation.h"
#include <string>
#include <vector>
#include <filesystem>
#include <ctime>
#include <chrono>

class StatCommand{
private:
    FilesInformation& filesInformation;
public:
    void chooseOperation(std::vector<std::string>& arguments);
    void operationForDirectory(std::string& element);
    void operationForFiles(std::string& element);

    StatCommand(FilesInformation& fi);
};