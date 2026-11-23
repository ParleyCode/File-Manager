#include "HeadCommand.h"
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <string>


void HeadCommand::headCommand(std::vector<std::string> &arguments){
    if(arguments.size() > 3 || arguments.empty()){
        std::cout << "head: failed to show output: too much arguments\n";
        return;
    }
    fs::path currentPath = filesInformation.getCurrentPath();
    fs::path elementPath;
    std::string operation;
    int operationAmount = 0;

    for(const auto& element : arguments){
        if(fs::exists(currentPath / element)){
            if(fs::is_regular_file(currentPath / element) && !((currentPath / element).extension().empty())){
                elementPath = currentPath / element;
            }
            else{
                std::cout << "head: failed to output: unknown format or directory";
            }
        }
        else if(element == "-n" || element == "-c"){
            operation = element;
        }
        else{
            try{
                operationAmount = std::stoi(element);
            }
            catch(const std::invalid_argument& e){
                std::cout << "head: unkown input: check command input or use help\n";
                return;
            }
        }
    }

    if(operation == "-n"){
        operationForLines(operationAmount, elementPath);
    }
    else{
        operationForChars(operationAmount, elementPath);
    }
    
    arguments.clear();
}

void HeadCommand::operationForChars(int charsAmount, fs::path elementPath){
    std::fstream fs(elementPath);
    char symbol;
    int counter = 0;
    while(fs.get(symbol) && counter < charsAmount){
        if(fs.eof()){
            break;
        }
        std::cout << symbol;
        ++counter;
    }
    std::cout << "\n";
}

void HeadCommand::operationForLines(int linesAmount, fs::path elementPath){
    std::fstream fs(elementPath);
    std::string line;
    for(int i = 0; i < linesAmount; ++i){
        std::getline(fs, line);
        if(fs.eof()){
            break;
        }
        std::cout << line << "\n";
    }
}

HeadCommand::HeadCommand(FilesInformation& fi) : filesInformation(fi){}