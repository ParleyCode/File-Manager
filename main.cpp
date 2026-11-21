#include <iostream>
#include "ConsoleUI/ConsoleUI.h"
#include "CommandHandler/CommandHandler.h"
#include "DirectoryManager/DirectoryManager.h"
#include "FileManager/FileManager.h"

int main(){
    ConsoleUI ConsoleUi;
    ConsoleUi.getCommand();

    return 0;
}