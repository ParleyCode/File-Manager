#include "FileManager.h"
#include "CommandHandler.h"
#include <filesystem>
#include <fstream>
#include <ios>
#include <vector>

void FileManager::printWorkingDirectory(CommandHandler& commandHandler, std::vector<std::string> &argumnets){
    std::cout << currentPath << "\n";
    clearArguments(argumnets);
}

void FileManager::clearScreen(){
    std::cout << "\033[2J\033[1;1H";
}

void FileManager::removeFile(std::vector<std::string> &arguments){
    for(const auto& element : arguments){
        if(fs::exists(element)){
            if(fs::is_directory(element)){
                std::cout << "rm: failed to remove '"<<element<<"': Is a directory.";
            }
            else{
                fs::remove(element);
                continue;
            }
        }
        std::cout << "rm: failed to remove '"<<element<<"': No such file.\n";
    }
    clearArguments(arguments);
}

void FileManager::touchFiles(std::vector<std::string>& arguments){
    for(const auto& element : arguments){
        std::ofstream(element, std::ios::app);
    }
    clearArguments(arguments);
}

void FileManager::localStorage(std::vector<std::string> &arguments){
    int count = 0;
    bool showHidden = false;
    for(const auto& arg : arguments){
        if(arg == "-a"){showHidden = true;}
    }

    for(const auto& entry : fs::directory_iterator(this->getCurrentPath())){
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
    clearArguments(arguments);
}


void FileManager::clearArguments(std::vector<std::string> &arguments){
    arguments.clear();
}
