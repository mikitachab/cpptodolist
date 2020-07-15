#pragma once

#include "Command.hpp"

#include <boost/program_options.hpp>

#include <vector>
#include <unordered_map>
#include <string>


namespace po = boost::program_options;


struct Controller {
    std::unordered_map<std::string, std::shared_ptr<Command>> commandMap;

    void registerCommand(std::string cmdName, std::shared_ptr<Command> cmd);
    void dispatch(std::string cmdName, po::variables_map vm);
};
