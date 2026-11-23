#include "FileManager.h"
#include "../CommandHandler/CommandHandler.h"
#include "../ConsoleCommands/ConsoleCommands.h"
#include "../FilesInformation.h"
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <filesystem>
#include <fstream>
#include <ios>
#include <string>
#include <vector>



void FileManager::removeFile(std::vector<std::string> &arguments){
    for(const auto& element : arguments){
        fs::path currentPath = filesInformation.getCurrentPath();
        fs::path finalPath = currentPath / element;
        if(fs::exists(finalPath)){
            if(fs::is_directory(finalPath)){
                std::cout << "rm: failed to remove '"<<element<<"': Is a directory.";
            }
            else{
                fs::remove(finalPath);
                continue;
            }
        }
        std::cout << "rm: failed to remove '"<<element<<"': No such file.\n";
    }
    arguments.clear();
}

void FileManager::touchFiles(std::vector<std::string>& arguments){
    for(const auto& element : arguments){
        fs::path currentPath = filesInformation.getCurrentPath();
        fs::path finalPath = currentPath / element;

        std::ofstream(finalPath, std::ios::app);
    }
    arguments.clear();
}

void FileManager::renameFiles(std::vector<std::string> &arguments){
    fs::path currentPath = filesInformation.getCurrentPath();
    fs::path oldFilePath = currentPath / arguments[0];
    fs::path newFilePath = currentPath / arguments[1];
    if(fs::exists(oldFilePath)){
        fs::rename(oldFilePath, newFilePath);
    }
    else{
        std::cout << "rename: failed to rename: " << arguments[0] << " does not exist.\n";
    }
    arguments.clear();
}


FileManager::FileManager(FilesInformation& fi, ConsoleCommands& cc) : filesInformation(fi), consoleCommands(cc){}


