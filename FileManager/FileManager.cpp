#include "FileManager.h"
#include "../CommandHandler/CommandHandler.h"
#include "../ConsoleCommands/ConsoleCommands.h"
#include "../FilesInformation.h"
#include <filesystem>
#include <fstream>
#include <ios>
#include <vector>



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
    arguments.clear();
}

void FileManager::touchFiles(std::vector<std::string>& arguments){
    for(const auto& element : arguments){
        std::ofstream(element, std::ios::app);
    }
    arguments.clear();
}

FileManager::FileManager(FilesInformation& fi, ConsoleCommands& cc) : filesInformation(fi), consoleCommands(cc){}


