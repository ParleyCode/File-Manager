#pragma once

#include <string>
#include <vector>
#include  "../FilesInformation.h"

class ConsoleCommands{

private: 
    FilesInformation& filesInformation;
public:

    void clearScreen();
    void echo(std::vector<std::string>& arguments);
    void cat(std::vector<std::string>& arguments);
    ConsoleCommands(FilesInformation& fi);
};