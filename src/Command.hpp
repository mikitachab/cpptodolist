#pragma once

#include "TodosLoader/TodosLoader.hpp"
#include <boost/program_options.hpp>

namespace po = boost::program_options;

struct Command {
    TodosLoader loader;
    virtual void execute(po::variables_map) = 0; 
};
