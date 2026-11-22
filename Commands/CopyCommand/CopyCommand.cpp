#include "CopyCommand.h"

void CopyCommand::copy(std::vector<std::string> &arguments){
        if(arguments.size() != 2) {
        std::cout << "\ncp: failed to move: incorrect arguments";
        return;
    }

    fs::path currentPath = filesInformation.getCurrentPath();

    fs::path source = currentPath / arguments[0];
    fs::path finalLocation = currentPath / arguments[1];
    if(fs::is_directory(finalLocation)) {
        finalLocation /= source.filename();
    }

    fs::copy(source, finalLocation);
    arguments.clear();
}

CopyCommand::CopyCommand(FilesInformation& fi) : filesInformation(fi){}