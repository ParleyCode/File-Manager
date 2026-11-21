#pragma once

#include "../../FilesInformation.h"
#include <string>
#include <vector>

class CopyCommand{
private:
    FilesInformation& filesInformation;
public:
    void copy(std::vector<std::string>& arguments);
    CopyCommand(FilesInformation& fi);
};