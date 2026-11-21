#pragma once

#include "../../FilesInformation.h"
#include <vector>
#include <string>

class MoveCommand{
private:
    FilesInformation& filesInformation;
public:
    void move(std::vector<std::string>& arguments);
    MoveCommand(FilesInformation& fi);
};