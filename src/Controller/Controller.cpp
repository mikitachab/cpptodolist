#include "Controller.hpp"

void Controller::registerCommand(std::string cmdName, std::shared_ptr<Command> cmd) {
    commandMap[cmdName] = cmd;
    // TODO handle command already exist
}

void Controller::dispatch(std::string cmdName, po::variables_map vm) {
    auto cmd = commandMap.at(cmdName);
    // TODO handle cmd does not exist
    cmd->execute(vm);
}