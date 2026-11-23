#include "StatCommand.h"
#include <cstdint>
#include <filesystem>

void StatCommand::chooseOperation(std::vector<std::string> &arguments){
    fs::path currentPath = filesInformation.getCurrentPath();
    for(auto& element : arguments){
        if(fs::is_directory(currentPath / element)){
            operationForDirectory(element);
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

    std::cout << "Name : " << element << "\n";
    std::cout << "Regular file : " << fs::is_regular_file(fileStatus) << "\n";

    fs::file_time_type lastTime = fs::last_write_time(currentElement);
    auto systemTime = std::chrono::clock_cast<std::chrono::system_clock>(lastTime);
    std::time_t time = std::chrono::system_clock::to_time_t(systemTime);
    std::cout << "Last time changed: " << std::ctime(&time);

    std::cout << "File size: " << fs::file_size(currentElement) << "\n";
    std::cout << "Permissions: ";
    showPermissions(currentPath);
     
}

void StatCommand::operationForDirectory(std::string &element){
    fs::path currentPath = filesInformation.getCurrentPath();
    fs::path currentElement = currentPath / element;
    fs::file_status fileStatus = fs::status(currentElement);

    std::cout << "Name : " << element << "\n";
    std::cout << "Directory : " << fs::is_directory(fileStatus) << "\n";

    fs::file_time_type lastTime = fs::last_write_time(currentElement);
    auto systemTime = std::chrono::clock_cast<std::chrono::system_clock>(lastTime);
    std::time_t time = std::chrono::system_clock::to_time_t(systemTime);
    std::cout << "Last time changed: " << std::ctime(&time);

    countDirectorySize(currentPath);
    std::cout << "Permissions: ";
    showPermissions(currentPath);
}
void StatCommand::showPermissions(fs::path path) {
    fs::perms permissions = fs::status(path).permissions();

    std::string result;

    result += (permissions & fs::perms::owner_read) != fs::perms::none ? 'r' : '-';
    result += (permissions & fs::perms::owner_write) != fs::perms::none ? 'w' : '-';
    result += (permissions & fs::perms::owner_exec) != fs::perms::none ? 'x' : '-';

    result += (permissions & fs::perms::group_read) != fs::perms::none ? 'r' : '-';
    result += (permissions & fs::perms::group_write) != fs::perms::none ? 'w' : '-';
    result += (permissions & fs::perms::group_exec) != fs::perms::none ? 'x' : '-';

    result += (permissions & fs::perms::others_read) != fs::perms::none ? 'r' : '-';
    result += (permissions & fs::perms::others_write) != fs::perms::none ? 'w' : '-';
    result += (permissions & fs::perms::others_exec) != fs::perms::none ? 'x' : '-';

    std::cout << result << '\n';
}

void StatCommand::countDirectorySize(fs::path path){
    uintmax_t totalSize = 0;
    for(const auto& entry : fs::directory_iterator(path)){
        if(fs::is_regular_file(entry)){
            totalSize += fs::file_size(entry);
        }
    }
    std::cout << "Directory size : " << totalSize << "\n";
}
StatCommand::StatCommand(FilesInformation& fi) : filesInformation(fi){}