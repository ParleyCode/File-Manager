#pragma once

#include "../../FilesInformation.h"
#include <string>
#include <vector>

class HeadCommand{
private:
    FilesInformation& filesInformation;
public:
    void headCommand(std::vector<std::string>& arguments);
    void operationForLines(int linesAmount, fs::path elementPath);
    void operationForChars(int charsAmount, fs::path elementPath);

    HeadCommand(FilesInformation& fi);
};