#include "WordCount.h"
#include <filesystem>
#include <fstream>
#include <string>

void WordCount::outputResult(std::vector<std::string> &arguments){
    bool showCharacters = false;
    bool showLines = false;
    bool showWords = false;
    fs::path currentPath = filesInformation.getCurrentPath();
    fs::path filePath;
    std::string file;
    for(const auto& el : arguments){
        if(el == "-w"){
            showWords = true;
        }
        else if(el == "-l"){
            showLines = true;
        }
        else if(el == "-c"){
            showCharacters = true;
        }
        else{
            if(fs::is_regular_file(currentPath / el)){
                filePath = currentPath / el;
                file = el;
                break;
            }
            std::cout << "wc: failed to show information: unknown operatorn for \"" << el << "\"\n";
            return;
        }
    }
    if(showCharacters == true || showLines == true || showWords == true){    
        if(showLines == true){
            countLines(filePath);
            std::cout << " ";
        }
        if (showWords == true){
            countWords(filePath);
            std::cout << " ";
        }
        if(showCharacters == true){
            countSymbols(filePath);
            std::cout << " ";
        }
        std::cout << file << "\n";
    }
    else{
        countLines(filePath);
        std::cout << " ";
        countWords(filePath);
        std::cout << " ";
        countSymbols(filePath);
        std::cout << " " << file << "\n";
    }
    arguments.clear();
}

void WordCount::countLines(fs::path path){
    std::fstream fs(path);
    std::string line;
    int linesAmount = 0;
    while(std::getline(fs, line)){
        ++linesAmount;
    }
    std::cout << linesAmount << " ";
}

void WordCount::countSymbols(fs::path path){
    std::fstream fs(path);
    char symbol;
    int symbolsAmount = 0;
    while(fs >> symbol){
        ++symbolsAmount;
    }
    std::cout << symbolsAmount << " ";
    fs.close();
}

void WordCount::countWords(fs::path path){
    std::fstream fs(path);
    std::string word;
    int wordsAmount = 0;
    while(fs >> word){
        ++wordsAmount;
    }
    std::cout << wordsAmount << " ";
    fs.close();
}

WordCount::WordCount(FilesInformation& fi) : filesInformation(fi){}