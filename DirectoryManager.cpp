#include "DirectoryManager.h"
#include <filesystem>
#include <sstream>
#include <string>
#include <vector>
#include "FileManager.h"

void DirectoryManager::changeDirectory(std::vector<std::string>& arguments){
    fs::path currentPath = fileManager.getCurrentPath();
    if(arguments.size() != 1){
        std::cout << "cd: failure to change directory: too much arguments";
        return;
    }
    fs::path argumentPath = arguments[0];
    for(const auto& element : argumentPath){
        if(element == ".."){
            currentPath = currentPath.parent_path();
        }
        else if(element == "."){/*skip*/}
        else if(element.empty()){}
        else{
            if(fs::exists(currentPath / element)){
                if(fs::is_directory(currentPath / element)){
                currentPath /= element;
                }
            }
        }
    }
    fileManager.setCurrentPath(currentPath);
    getFileManager().clearArguments(arguments);
}

void DirectoryManager::makeDirectory(std::vector<std::string> &arguments){
    for(const auto& element : arguments){
        fs::create_directory(element);
    }
    getFileManager().clearArguments(arguments);
}

void DirectoryManager::removeDirectory(std::vector<std::string> &arguments){
    for(const auto& element : arguments){
        if(fs::exists(element)){
            if(fs::is_directory(element)){
                if(fs::is_empty(element)){
                fs::remove(element);
                continue;
                }
                std::cout << "rmdir: failed to remomve '"<<element<<"': Directory is not empty.\n"; 
                continue;
            }
            std::cout << element << "is not a directory\n";
            continue;
        }
        std::cout <<"rmdir: failed to remove '"<< element << "': No such directory\n";
        continue;
    }
    getFileManager().clearArguments(arguments);
}

DirectoryManager::DirectoryManager(FileManager& fm) : fileManager(fm){}