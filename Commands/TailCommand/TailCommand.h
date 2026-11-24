#pragma once

#include "../../FilesInformation.h"
#include <vector>
#include <string>

class TailCommand{
    FilesInformation& filesInformation;
public:
    void tailCommand(std::vector<std::string>& arguments);
    void operationForLines(int linesAmount, fs::path elementPath);
    void operationForChars(int charsAmount, fs::path elementPath);

    TailCommand(FilesInformation& fi);
};