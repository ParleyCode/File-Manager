#pragma once
#include "../ConsoleCommands/ConsoleCommands.h"
#include "../DirectoryManager/DirectoryManager.h"
#include "../FileManager/FileManager.h"
#include "../FilesInformation.h"
#include <string>
#include <vector>

class DirectoryManager;

class CommandHandler{
    DirectoryManager& directoryManager;
    FileManager& fileManager;
    ConsoleCommands& consoleCommands;
    FilesInformation& filesInformation;

    std::string currentCommand;
public:
    CommandHandler(DirectoryManager& dm, FileManager& fm, ConsoleCommands& cc, FilesInformation& fi);
    void isCommandValid(std::string command, std::vector<std::string>& arguments);
};