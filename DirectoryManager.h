#pragma once

#include <vector>
#include <string>

class FileManager;

class DirectoryManager{

FileManager& fileManager;

public:
    void changeDirectory(std::vector<std::string>& arguments);
    void makeDirectory(std::vector<std::string>& arguments);
    void removeDirectory(std::vector<std::string>& arguments);
    FileManager& getFileManager(){
        return fileManager;
    }
    DirectoryManager(FileManager& fm);
};