#include "DirectoryManager.h"
#include <filesystem>
#include <sstream>
#include <string>
#include <vector>
#include "../ConsoleCommands/ConsoleCommands.h"
#include "../FileManager/FileManager.h"
#include "../FilesInformation.h"

void DirectoryManager::changeDirectory(std::vector<std::string>& arguments){
    fs::path currentPath = filesInformation.getCurrentPath();
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
    filesInformation.setCurrentPath(currentPath);
    arguments.clear();
}

void DirectoryManager::makeDirectory(std::vector<std::string> &arguments){
    for(const auto& element : arguments){
        fs::create_directory(element);
    }
    arguments.clear();
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
    arguments.clear();
}

void DirectoryManager::printWorkingDirectory(CommandHandler& commandHandler, std::vector<std::string> &argumnets){
    std::cout << filesInformation.getCurrentPath() << "\n";
    argumnets.clear();
}

void DirectoryManager::localStorage(std::vector<std::string> &arguments){
    int count = 0;
    bool showHidden = false;
    for(const auto& arg : arguments){
        if(arg == "-a"){showHidden = true;}
    }

    for(const auto& entry : fs::directory_iterator(filesInformation.getCurrentPath())){
        std::string filename = entry.path().filename().string();
        if(filename[0] == '.' && !showHidden){
            continue;
        }
        else{
            if(fs::is_directory(entry)){
                std::cout << entry.path().filename().string() << "/\t";
                continue;
            }
            std::cout << entry.path().filename().string() << "\t";
        }
        ++count;
        if(count % 7 == 0){
            std::cout << "\n";
        }
    }
    std::cout << "\n";
    arguments.clear();
}

DirectoryManager::DirectoryManager(FilesInformation& fi, ConsoleCommands& cc) : filesInformation(fi), consoleCommands(cc){}