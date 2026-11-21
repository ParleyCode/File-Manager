cmake_minimum_required(VERSION 3.16)

project(FileManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(FileManager
    main.cpp
    FileManager/FileManager.cpp
    FileManager/FileManager.h
    DirectoryManager/DirectoryManager.cpp
    DirectoryManager/DirectoryManager.h
    ConsoleUI/ConsoleUI.cpp
    ConsoleUI/ConsoleUI.h
    CommandHandler/CommandHandler.cpp
    CommandHandler/CommandHandler.h
    ConsoleCommands/ConsoleCommands.cpp
    ConsoleCommands/ConsoleCommands.h
    FilesInformation.h
)