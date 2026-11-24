#include "TailCommand.h"

#include <fstream>
#include <deque>

void TailCommand::tailCommand(std::vector<std::string> &arguments){
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

void TailCommand::operationForChars(int charsAmount, fs::path elementPath){

    std::fstream fs(elementPath);
    std::deque<char> symbols(charsAmount);
    char symbol;
    int counter = 0;
    while(fs.get(symbol)){
        if(fs.eof()){
            break;
        }
        if(symbols.size() == charsAmount){
            symbols.pop_front();
        }
        symbols.push_back(symbol);
        ++counter;
    }
    for(const auto& element : symbols){
        std::cout << element;
    }
    std::cout << "\n";
}

void TailCommand::operationForLines(int linesAmount, fs::path elementPath){
    std::fstream fs(elementPath);
    std::string line;
    std::deque<std::string> lines(linesAmount);
    while(std::getline(fs,line)){
        if(lines.size() == linesAmount){
            lines.pop_front();
        }
        lines.push_back(line);
    }
    for(const auto& element : lines){
        std::cout << element << "\n";
    }
}

TailCommand::TailCommand(FilesInformation& fi) : filesInformation(fi){}