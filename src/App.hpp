#pragma once

#include "Controller/Controller.hpp"
#include <boost/program_options.hpp>
#include <exception>

namespace po = boost::program_options;

struct App {
    Controller controller;
    po::variables_map args;
    
    std::string getCommandName();
    void run();
};

struct BadCommadException: public std::exception {
    const char* what() const throw() {
        return "invalid command provided";
    }
};