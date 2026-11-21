#include "ConsoleCommands.h"
#include <iostream>


void ConsoleCommands::clearScreen(){
    std::cout << "\033[2J\033[1;1H";
}