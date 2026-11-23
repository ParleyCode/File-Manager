#pragma once
#include "../ConsoleCommands/ConsoleCommands.h"
#include "../FilesInformation.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

class CommandHandler;

class FileManager{
    FilesInformation& filesInformation;
    ConsoleCommands& consoleCommands;
    public:
    void removeFile(std::vector<std::string>& arguments);
    void touchFiles(std::vector<std::string>& argumnets);
    void renameFiles(std::vector<std::string>& arguments);
    void tailCommand(std::vector<std::string>& arguments);

    FileManager(FilesInformation& fi, ConsoleCommands& cc);
};