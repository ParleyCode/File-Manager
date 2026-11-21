#include "ConsoleUI.h"
#include "CommandHandler.h"
#include "DirectoryManager.h"
#include "FileManager.h"
#include <cstdio>
#include <exception>
#include <filesystem>
#include<iostream>
#include <sstream>
#include <string>

void ConsoleUI::getCommand(){
    FileManager fileManager;
    DirectoryManager directoryManager(fileManager);
    CommandHandler commandHandler(directoryManager);


    while (true) {
        fs::path currentPath = fileManager.getCurrentPath();
        std::string currentDirectory = currentPath.filename().string();
        std::string input;
        std::string command;
        std::cout << "[filesystem@linux? >.< " << currentDirectory << "]$ ";
        std::getline(std::cin, input);
        std::stringstream tags(input);
        tags >> currentCommand;
        arguments.clear();
        while(tags >> command){
            arguments.push_back(command);
        }
        commandHandler.isCommandValid(currentCommand, arguments);

    
    }
}