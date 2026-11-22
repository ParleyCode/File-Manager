#include "ConsoleCommands.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <sstream>
#include <string>

namespace fs = std::filesystem;

void ConsoleCommands::clearScreen(){
    std::cout << "\033[2J\033[1;1H";
}

void ConsoleCommands::echo(std::vector<std::string> &arguments){
    fs::path currentPath = filesInformation.getCurrentPath();
    fs::path filePath;

    if(std::find(arguments.begin(), arguments.end(), ">") != arguments.end()){
        for(auto it = arguments.begin(); it != arguments.end(); ++it){
            if(*it == ">"){
                if(it + 1 != arguments.end()){
                filePath = *(it + 1);
                currentPath /= filePath;
                break;
                }
                else{
                    std::cout << "echo: error, empty file\n";
                }
            }
        }
        if(!fs::exists(currentPath)){
            std::cout << "\necho: failed to input: uknown file " << filePath << "\n";
        }
        else{
            std:: fstream fs(currentPath.string(), std::fstream::app);
            if(fs::file_size(currentPath) != 0){
                fs << "\n";
            }
            for(auto it = arguments.begin(); *it != ">"; ++it){
                fs << *it << " ";
            }
            fs.close();
        }
    }
    else{
        for(auto it = arguments.begin(); it != arguments.end(); ++it){
            std::cout << *it << " ";
        }
    std::cout << "\n";
    }

    arguments.clear();
}

void ConsoleCommands::cat(std::vector<std::string> &arguments){
    if(arguments.size() > 2){
        std::cout << "\ncat: could not do the operation: too much arguments";
        return;
    }
    fs::path currentPath = filesInformation.getCurrentPath();
    fs::path fileName = arguments[0];
    fs::path filePath = currentPath / fileName;
    if(!fs::exists(filePath)){
        std::cout << "cat: could not open file " << fileName << "\n";
        return;
    }
    std::fstream fs(filePath.string());
    std::string line;
    std::cout << "\n";
    while(!fs.eof()){
        std::getline(fs, line);
        std::cout<< line << "\n";
    }
}

ConsoleCommands::ConsoleCommands(FilesInformation& fi) : filesInformation(fi){}