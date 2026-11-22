#include "MoveCommand.h"
#include <algorithm>
#include<iostream>
#include <filesystem>

namespace fs = std::filesystem;

void MoveCommand::move(std::vector<std::string>& arguments) {
    if(arguments.size() != 2) {
        std::cout << "\nmv: failed to move: incorrect arguments";
        return;
    }

    fs::path currentPath = filesInformation.getCurrentPath();

    fs::path source = currentPath / arguments[0];
    fs::path finalLocation = currentPath / arguments[1];
    if(fs::is_directory(finalLocation)) {
        finalLocation /= source.filename();
    }

    fs::rename(source, finalLocation);
    arguments.clear();
}

MoveCommand::MoveCommand(FilesInformation& fi): filesInformation(fi){}