#include "ConsoleUI.h"
#include "../CommandHandler/CommandHandler.h"
#include "../ConsoleCommands/ConsoleCommands.h"
#include "../DirectoryManager/DirectoryManager.h"
#include "../FileManager/FileManager.h"
#include "../FilesInformation.h"
#include <cstdio>
#include <exception>
#include <filesystem>
#include<iostream>
#include <sstream>
#include <string>

void ConsoleUI::getCommand(){
    ConsoleCommands consoleCommands;
    FilesInformation filesInformation;
    FileManager fileManager(filesInformation, consoleCommands);
    DirectoryManager directoryManager(filesInformation, consoleCommands);
    CommandHandler commandHandler(directoryManager, fileManager, consoleCommands, filesInformation);


    while (true) {
        fs::path currentPath = filesInformation.getCurrentPath();
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