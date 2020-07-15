#include "App.hpp"

#include <string>
#include <iostream>


std::string App::getCommandName(){
    for (const auto& cmd : controller.commandMap) {
        if (args.count(cmd.first)) {
            return cmd.first;
        }
    }
    throw BadCommadException();
}

void App::run () {
    std::string cmdName = getCommandName();
    controller.dispatch(cmdName, args);
}
