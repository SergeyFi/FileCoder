cmake_minimum_required(VERSION 3.17)
project(FileCoder)

set(CMAKE_CXX_STANDARD 17)

add_executable(FileCoder main.cpp Parser/IParser.h DataTypes/CommandData.h Parser/Parser.cpp Parser/Parser.h Logger/ILogger.h Logger/Logger.cpp Logger/Logger.h Commands/ICommand.h Commands/Command.cpp Commands/Command.h CommandHolder/ICommandHolder.cpp CommandHolder/ICommandHolder.h CommandHolder/CommandHolder.cpp CommandHolder/CommandHolder.h)