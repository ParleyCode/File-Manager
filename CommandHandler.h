#pragma once
#include "DirectoryManager.h"
#include "FileManager.h"
#include <string>
#include <vector>

class CommandHandler{
    DirectoryManager& directoryManager;
    std::string currentCommand;
public:
    CommandHandler(DirectoryManager& dm);
    FileManager& getFileManager();
    DirectoryManager& getDirectoryManager();
    void isCommandValid(std::string command, std::vector<std::string>& arguments);
};