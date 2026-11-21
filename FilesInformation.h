#pragma once

#include <iostream>
#include <filesystem>

namespace  fs = std::filesystem;

class FilesInformation{
    std::string currentPath = fs::current_path();

public:
    void setCurrentPath(std::string path){currentPath = path;};
    std::string getCurrentPath(){return currentPath;};
};