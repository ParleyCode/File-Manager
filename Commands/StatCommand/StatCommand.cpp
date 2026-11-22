#include "StatCommand.h"

void StatCommand::chooseOperation(std::vector<std::string> &arguments){
    fs::path currentPath = filesInformation.getCurrentPath();
    for(auto& element : arguments){
        if(fs::is_directory(currentPath / element)){
            std::cout << "Operation for directories\n";
            //operationForDirectory(element);
        }
        else if(fs::is_regular_file(currentPath / element)){
            operationForFiles(element);
        }
        else if(!fs::exists(currentPath / element)){
            std::cout << "stat: failed to show information \"" << element << "\" does not exist\n";
        }
        else{
            std::cout << "stat: failed to show information\n";
        }
    }
}

void StatCommand::operationForFiles(std::string& element){
    fs::path currentPath = filesInformation.getCurrentPath();
    fs::path currentElement = currentPath / element;
    fs::file_status fileStatus = fs::status(currentElement);

    std::cout << "File : " << element << "\n";
    std::cout << "Regular file : " << fs::is_regular_file(fileStatus) << "\n";

    fs::file_time_type lastTime = fs::last_write_time(currentElement);
    auto systemTime = std::chrono::clock_cast<std::chrono::system_clock>(lastTime);
    std::time_t time = std::chrono::system_clock::to_time_t(systemTime);
    std::cout << "Last time changed: " << std::ctime(&time);
}

StatCommand::StatCommand(FilesInformation& fi) : filesInformation(fi){}