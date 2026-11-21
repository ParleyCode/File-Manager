#pragma once

#include "../CommandHandler/CommandHandler.h"
#include "../ConsoleCommands/ConsoleCommands.h"
#include "../FileManager/FileManager.h"
#include "../FilesInformation.h"
#include <vector>
#include <string>

class FileManager;
class DirectoryManager{

    FilesInformation& filesInformation;
    ConsoleCommands& consoleCommands;

public:
    void changeDirectory(std::vector<std::string>& arguments);
    void makeDirectory(std::vector<std::string>& arguments);
    void removeDirectory(std::vector<std::string>& arguments);
    void printWorkingDirectory(CommandHandler& commandHandler, std::vector<std::string>& argumnets);
    void localStorage(std::vector<std::string>& arguments);
    DirectoryManager(FilesInformation& fi, ConsoleCommands& cc);
};