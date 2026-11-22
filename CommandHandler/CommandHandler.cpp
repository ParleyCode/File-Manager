#include "CommandHandler.h"
#include "../DirectoryManager/DirectoryManager.h"
#include "../ConsoleUI/ConsoleUI.h"
#include "../FileManager/FileManager.h"
#include "../Commands/Commands.h"
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

void CommandHandler::isCommandValid(std::string command,std::vector<std::string>& arguments) {
    std::unordered_map<std::string,std::function<void(std::vector<std::string>&)>> allCommands = {

        //Print Working Directory
    {"pwd", [this](std::vector<std::string>& arguments){directoryManager.printWorkingDirectory(*this, arguments);}},
        //Change Directory
        {"cd", [this](std::vector<std::string>& arguments) {directoryManager.changeDirectory(arguments);}},
        //Clear Screen
        {"clear", [this](std::vector<std::string>& arguments){consoleCommands.clearScreen();}},
        //Make Directory
        {"mkdir", [this](std::vector<std::string>& arguments){this->directoryManager.makeDirectory(arguments);}},
        //Remove Directory
        {"rmdir", [this](std::vector<std::string>& arguments){directoryManager.removeDirectory(arguments);}},
        //Remove Files
        {"rm", [this](std::vector<std::string>& arguments){fileManager.removeFile(arguments);}},
        //Touch Files
        {"touch", [this](std::vector<std::string>& arguments){fileManager.touchFiles(arguments);}},
        //Local Storage
        {"ls", [this](std::vector<std::string>& arguments){directoryManager.localStorage(arguments);}},
        //Move Command
        {"mv", [this](std::vector<std::string>& arguments){MoveCommand moveCommand(filesInformation); moveCommand.move(arguments);}},
        //Copy Command
        {"cp", [this](std::vector<std::string>& arguments){CopyCommand copyCommand(filesInformation); copyCommand.copy(arguments);}},
        //Exit Command
        {"exit", [](std::vector<std::string>& arguments){exit(0);}},
        //Echo Command
        {"echo", [this](std::vector<std::string>& arguments){this->consoleCommands.echo(arguments);}},
        //Cat Command
        {"cat", [this](std::vector<std::string>& arguments){this->consoleCommands.cat(arguments);}}

    };

    if (allCommands.find(command) != allCommands.end()) {
        allCommands.at(command)(arguments);
    }
    else{
        std::cout << "Unknown command for '"<< command << "'" << "\n";
    }
}

CommandHandler::CommandHandler(DirectoryManager& dm, FileManager& fm, ConsoleCommands& cc, FilesInformation& fi) 
: directoryManager(dm),  consoleCommands(cc), fileManager(fm), filesInformation(fi){}

