#include "CommandHandler.h"
#include "DirectoryManager.h"
#include "ConsoleUI.h"
#include "FileManager.h"
#include <functional>
#include <string>
#include <unordered_map>

void CommandHandler::isCommandValid(std::string command,std::vector<std::string>& arguments) {
    std::unordered_map<std::string,std::function<void(std::vector<std::string>&)>> allCommands = {

        //Print Working Directory
    {"pwd", [this](std::vector<std::string>& arguments){directoryManager.getFileManager().printWorkingDirectory(*this, arguments);}},
        //Change Directory
        {"cd", [this](std::vector<std::string>& arguments) {directoryManager.changeDirectory(arguments);}},
        //Clear Screen
        {"clear", [this](std::vector<std::string>& arguments){directoryManager.getFileManager().clearScreen();}},
        //Make Directory
        {"mkdir", [this](std::vector<std::string>& arguments){directoryManager.makeDirectory(arguments);}},
        //Remove Directory
        {"rmdir", [this](std::vector<std::string>& arguments){directoryManager.removeDirectory(arguments);}},
        //Remove Files
        {"rm", [this](std::vector<std::string>& arguments){directoryManager.getFileManager().removeFile(arguments);}},
        //Touch Files
        {"touch", [this](std::vector<std::string>& arguments){getFileManager().touchFiles(arguments);}},
        //Local Storage
        {"ls", [this](std::vector<std::string>& arguments){getFileManager().localStorage(arguments);}}
    };

    if (allCommands.find(command) != allCommands.end()) {
        allCommands.at(command)(arguments);
    }
    else{
        std::cout << "Unknown command for '"<< command << "'" << "\n";
    }
}

CommandHandler::CommandHandler(DirectoryManager& dm) : directoryManager(dm){}

DirectoryManager& CommandHandler::getDirectoryManager(){
    return directoryManager;
}

FileManager& CommandHandler::getFileManager(){
    return directoryManager.getFileManager();
}
