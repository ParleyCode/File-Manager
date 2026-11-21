#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

class CommandHandler;

class FileManager{

    std::string currentPath = fs::current_path();

    public:
    void setCurrentPath(std::string path){currentPath = path;};
    std::string getCurrentPath(){return currentPath;};
    void printWorkingDirectory(CommandHandler& commandHandler, std::vector<std::string>& argumnets);
    void clearScreen();
    void removeFile(std::vector<std::string>& arguments);
    void touchFiles(std::vector<std::string>& argumnets);
    void localStorage(std::vector<std::string>& arguments);
    void clearArguments(std::vector<std::string>& arguments);
};