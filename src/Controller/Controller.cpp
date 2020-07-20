#include "Controller.hpp"

#include <exception>


void Controller::registerCommand(std::string cmdName, std::shared_ptr<Command> cmd) {
    if (!commandMap.count(cmdName)){
        commandMap[cmdName] = cmd;
    } else {
        throw std::runtime_error(cmdName + " is already registered");
    }
}

void Controller::dispatch(std::string cmdName, po::variables_map vm) {
    if (commandMap.count(cmdName)){
        auto cmd = commandMap.at(cmdName);
        cmd->execute(vm);
    } else {
        throw std::runtime_error("calling unregistered command: " + cmdName);
    }
}