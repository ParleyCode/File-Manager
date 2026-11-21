#pragma once
#include <iostream>
#include <vector>
class ConsoleUI{
    std::string currentCommand;
    std::vector<std::string> arguments;
public:
    void getCommand();
};