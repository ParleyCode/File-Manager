#pragma once

#include "../../FilesInformation.h"
#include <string>
#include <vector>

class WordCount{
private:
    FilesInformation& filesInformation;
public:
    void outputResult(std::vector<std::string>& arguments);
    void countSymbols(fs::path path);
    void countWords(fs::path path);
    void countLines(fs::path path);

    WordCount(FilesInformation& fi);
};